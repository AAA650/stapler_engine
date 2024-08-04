// object.cpp
#include "pch.h"
#include "include/object.h"

DLLAPI_SE int object::m_fnSetPos(vect iInVec) {
	pos = iInVec;
	return 0;
};
DLLAPI_SE int object::m_fnAddPos(vect iInVec) {
	pos += iInVec;
	return 0;
};
DLLAPI_SE const vect& object::m_fnGetPos() const {
	return pos;
};
DLLAPI_SE int object::m_fnSetBox(vect iInVec) {
	box = iInVec;
	return 0;
};
DLLAPI_SE int object::m_fnSetBox(vecd iInVec) {
	box = vect(POSVECD(iInVec), box.m_fnz());
	return 0;
};
DLLAPI_SE const vect& object::m_fnGetBox() const {
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
	pos = vect(0, 0, 0);
	box = vect(0, 0, 0);
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
