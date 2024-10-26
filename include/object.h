//object.h   All things about objects.
#pragma once

#define OBJECT_H
#include "SEDefinition.h"
#include <iostream>
#include "Vect.h"

#define SE_OBJ_VECM_D 2
#define SE_OBJ_VECM_T 3

struct DLLAPI_SE ObjInfo {
public:
	Vec3 pos, box;
	dirt dir;
	int iStatus = 0;
	short nVecMode = SE_OBJ_VECM_T;
};

class DLLAPI_SE object {
protected:
	Vec3 pos, box;
	dirt dir;
	int m_iStatus = 0;
	short m_nVecMode = SE_OBJ_VECM_T;
public:
	int m_fnSetPos(Vec3);
	int m_fnAddPos(Vec3);
	const Vec3& m_fnGetPos() const;
	int m_fnSetBox(Vec3);
	int m_fnSetBox(Vec2);
	const Vec3& m_fnGetBox() const;
	int m_fnSetStatus(int);
	int m_fnGetStatus() const;
	int m_fnSetupObj();
	int m_fnSetupObj(ObjInfo);

};

class DLLAPI_SE camera :public object {
protected:
	double m_dScreenDistance = 1;
public:
	Vec2 m_fnGetScrPos(Vec3);
};
