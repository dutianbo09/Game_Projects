// TankEnemy.h: interface for the CTankEnemy class.
//
//////////////////////////////////////////////////////////////////////

#include "CommonClass.h"
#include "LessonY.h"
#include "WeaponY.h"
#if !defined(AFX_TANKENEMYY_H__5146D01F_047B_4470_A7BE_7F0FA5F9D904__INCLUDED_)
#define AFX_TANKENEMYY_H__5146D01F_047B_4470_A7BE_7F0FA5F9D904__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTankEnemyY : public CWeaponY  
{
private:
	float m_fChangeDirTime;
	float m_fBulletCreateTime;
public:
	CTankEnemyY(const char* szName);
	virtual ~CTankEnemyY();
	void			SetChangeDirTime(float changeDirTime)  {m_fChangeDirTime=changeDirTime;}
	float			GetChangeDirTime()  {return m_fChangeDirTime;}
	void			Init();
	void			OnMove();
	void			OnMove(float fDeltaTime);
	void			OnFire(float fDeltaTime);
	void			OnSpriteColSprite(CWeaponY* pSprite);
	
};

#endif // !defined(AFX_TANKENEMY_H__5146D01F_047B_4470_A7BE_7F0FA5F9D904__INCLUDED_)
