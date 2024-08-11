//object.h   All things about objects.
#pragma once

#define OBJECT_H
#include "SEDefinition.h"
#include <iostream>
#include "vec.h"

#define SE_OBJ_VECM_D 2
#define SE_OBJ_VECM_T 3

struct DLLAPI_SE ObjInfo {
public:
	vect pos, box;
	dirt dir;
	int iStatus = 0;
	short nVecMode = SE_OBJ_VECM_T;
};

class DLLAPI_SE object {
protected:
	vect pos, box;
	dirt dir;
	int m_iStatus = 0;
	short m_nVecMode = SE_OBJ_VECM_T;
public:
	int m_fnSetPos(vect);
	int m_fnAddPos(vect);
	const vect& m_fnGetPos() const;
	int m_fnSetBox(vect);
	int m_fnSetBox(vecd);
	const vect& m_fnGetBox() const;
	int m_fnSetStatus(int);
	int m_fnGetStatus() const;
	int m_fnSetupObj();
	int m_fnSetupObj(ObjInfo);

};

class DLLAPI_SE camera :public object {
protected:
	double m_dScreenDistance = 1;
public:
	vecd m_fnGetScrPos(vect);
};
