// Weapon.cpp: implementation of the CWeapon class.
//
//////////////////////////////////////////////////////////////////////

#include "WeaponY.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWeaponY::CWeaponY(const char* szName):CSprite(szName)
{
	m_iDir=0;
	m_fSpeedX=0.f;
	m_fSpeedY=0.f;
	m_iHp=2;

}

CWeaponY::~CWeaponY()
{

}

bool CWeaponY::IsDead()
{
	if(m_iHp==0)
	{
		return true;
	}
	return false;
}
