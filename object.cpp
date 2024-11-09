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
	box = Vec3(VEC2(iInVec), box.z_);
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
	double sina = sin(dir.x_z_), cosa = cos(dir.x_z_), sinb = sin(dir.y_z_), cosb = cos(dir.y_z_);
	double tmpDist = sina * cosa * TargetPos.x_ + sinb * TargetPos.y_ - cosa * cosb * TargetPos.z_,
		CamToTargDistance = fabs(tmpDist),
		ScrToTargDistance = fabs(m_dScreenDistance - tmpDist);
	if (CamToTargDistance < m_dScreenDistance && CamToTargDistance < ScrToTargDistance)
		return Vec2(0, 0);
	Vec2 ret(0, 0);
	if (cosb == 0) {
		ret.x_ = (TargetPos.x_ * cosa + TargetPos.z_ * sina)* m_dScreenDistance / CamToTargDistance;
		ret.y_ = (TargetPos.x_ * cosa - TargetPos.z_ * sina)* m_dScreenDistance / CamToTargDistance;
		return ret;
	};
	if (sinb == 0)
		ret.y_ = m_dScreenDistance * TargetPos.y_ / (CamToTargDistance * cosb);
	else
		ret.y_ = m_dScreenDistance * (TargetPos.y_ - CamToTargDistance * sinb) / (CamToTargDistance * cosb);
	if (sina == 0)
		ret.x_ = (TargetPos.x_ * m_dScreenDistance) / (cosa * CamToTargDistance);
	else if (cosa == 0)
		ret.x_ = (TargetPos.z_ * m_dScreenDistance) / (sina * CamToTargDistance);
	else
		ret.x_ = (TargetPos.x_ * cosb + TargetPos.y_ * sina * sinb - sina * CamToTargDistance) * m_dScreenDistance / (cosa * cosb * CamToTargDistance);
	return ret;
};
