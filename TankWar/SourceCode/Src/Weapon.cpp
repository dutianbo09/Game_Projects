// Weapon.cpp: implementation of the CWeapon class.
//
//////////////////////////////////////////////////////////////////////

#include "Weapon.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWeapon::CWeapon(const char* szName):CSprite(szName)
{
	m_iDir=0;
	m_fSpeedX=0.f;
	m_fSpeedY=0.f;
	m_iHp=5;
	m_fRotSpeed=0.f;

}

CWeapon::~CWeapon()
{

}

bool CWeapon::IsDead()
{
	if(m_iHp<=0)
	{
		return true;
	}
	return false;
}
