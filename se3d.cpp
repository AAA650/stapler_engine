//se3d.cpp
#include "pch.h"
#include "include/se3d.h"

DLLAPI_SE vecd camera::m_fnGetScrPos(vect TargetPos) {
	double sina = sin(dir.m_fnxz()), cosa = cos(dir.m_fnxz()), sinb = sin(dir.m_fnyz()), cosb = cos(dir.m_fnyz());
	double tmpDist = sina * cosa * TargetPos.m_fnx() + sinb * TargetPos.m_fny() - cosa * cosb * TargetPos.m_fnz(),
		CamToTargDistance = fabs(tmpDist),
		ScrToTargDistance = fabs(m_dScreenDistance - tmpDist);
	if (CamToTargDistance < m_dScreenDistance && CamToTargDistance < ScrToTargDistance)
		return vecd(0, 0);
	vecd ret(0, 0);
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