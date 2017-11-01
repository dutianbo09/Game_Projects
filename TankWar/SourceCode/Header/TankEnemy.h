// TankEnemy.h: interface for the CTankEnemy class.
//
//////////////////////////////////////////////////////////////////////

#include "CommonClass.h"
#include "LessonX.h"
#include "Weapon.h"
#if !defined(AFX_TANKENEMY_H__5146D01F_047B_4470_A7BE_7F0FA5F9D904__INCLUDED_)
#define AFX_TANKENEMY_H__5146D01F_047B_4470_A7BE_7F0FA5F9D904__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTankEnemy : public CWeapon  
{
private:
	float m_fChangeDirTime;
	float m_fBulletCreateTime;
public:
	CTankEnemy(const char* szName);
	virtual ~CTankEnemy();
	void		SetChangeDirTime(float changeDirTime)  {m_fChangeDirTime=changeDirTime;}
	float		GetChangeDirTime()  {return m_fChangeDirTime;}
	void		Init();
	void		OnMove(int iKey,bool bPress);
	void		OnFire();
	void		OnSpriteColSprite(CWeapon* pSprite);
	float		GetTankEnemyRotation() {return GetSpriteRotation();}
	
};

#endif // !defined(AFX_TANKENEMY_H__5146D01F_047B_4470_A7BE_7F0FA5F9D904__INCLUDED_)
