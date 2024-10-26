// object.cpp
#include "pch.h"
#include "include/Object.h"

DLLAPI_SE int object::m_fnSetPos(Vec3 iInVec) {
	pos = iInVec;
	return 0;
};
DLLAPI_SE int object::m_fnAddPos(Vec3 iInVec) {
	pos += iInVec;
	return 0;
};
DLLAPI_SE const Vec3& object::m_fnGetPos() const {
	return pos;
};
DLLAPI_SE int object::m_fnSetBox(Vec3 iInVec) {
	box = iInVec;
	return 0;
};
DLLAPI_SE int object::m_fnSetBox(Vec2 iInVec) {
	box = Vec3(VEC2(iInVec), box.m_fnz());
	return 0;
};
DLLAPI_SE const Vec3& object::m_fnGetBox() const {
	return box;
};
DLLAPI_SE int object::m_fnSetStatus(int iInSta) {
	m_iStatus = iInSta;
	return 0;
};
DLLAPI_SE int object::m_fnGetStatus() const {
	return m_iStatus;
};
DLLAPI_SE int object::m_fnSetupObj() {
	pos = Vec3(0, 0, 0);
	box = Vec3(0, 0, 0);
	dir = dirt(0, 0, 0);
	m_iStatus = 0;
	m_nVecMode = SE_OBJ_VECM_T;
	return 0;
};
DLLAPI_SE int object::m_fnSetupObj(ObjInfo Inf) {
	pos = Inf.pos;
	box = Inf.box;
	dir = Inf.dir;
	m_iStatus = Inf.iStatus;
	m_nVecMode = Inf.nVecMode;
	return 0;
};


DLLAPI_SE Vec2 camera::m_fnGetScrPos(Vec3 TargetPos) {
	double sina = sin(dir.m_fnxz()), cosa = cos(dir.m_fnxz()), sinb = sin(dir.m_fnyz()), cosb = cos(dir.m_fnyz());
	double tmpDist = sina * cosa * TargetPos.m_fnx() + sinb * TargetPos.m_fny() - cosa * cosb * TargetPos.m_fnz(),
		CamToTargDistance = fabs(tmpDist),
		ScrToTargDistance = fabs(m_dScreenDistance - tmpDist);
	if (CamToTargDistance < m_dScreenDistance && CamToTargDistance < ScrToTargDistance)
		return Vec2(0, 0);
	Vec2 ret(0, 0);
	if (cosb == 0) {
		ret.m_fnx((TargetPos.m_fnx() * cosa + TargetPos.m_fnz() * sina) * m_dScreenDistance / CamToTargDistance);
		ret.m_fny((TargetPos.m_fnx() * cosa - TargetPos.m_fnz() * sina) * m_dScreenDistance / CamToTargDistance);
		return ret;
	};
	if (sinb == 0)
		ret.m_fny(m_dScreenDistance * TargetPos.m_fny() / (CamToTargDistance * cosb));
	else
		ret.m_fny(m_dScreenDistance * (TargetPos.m_fny() - CamToTargDistance * sinb) / (CamToTargDistance * cosb));
	if (sina == 0)
		ret.m_fnx((TargetPos.m_fnx() * m_dScreenDistance) / (cosa * CamToTargDistance));
	else if (cosa == 0)
		ret.m_fnx((TargetPos.m_fnz() * m_dScreenDistance) / (sina * CamToTargDistance));
	else
		ret.m_fnx((TargetPos.m_fnx() * cosb + TargetPos.m_fny() * sina * sinb - sina * CamToTargDistance) * m_dScreenDistance / (cosa * cosb * CamToTargDistance));
	return ret;
};
