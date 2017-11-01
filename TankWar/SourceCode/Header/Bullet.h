// Bullet.h: interface for the CBullet class.
//
//////////////////////////////////////////////////////////////////////

#include "CommonClass.h"
#include "Weapon.h"
#include "TankPlayer.h"
#include "LessonX.h"
#if !defined(AFX_BULLET_H__CFFF5D79_D511_4C20_A3A9_6511F0BFD19D__INCLUDED_)
#define AFX_BULLET_H__CFFF5D79_D511_4C20_A3A9_6511F0BFD19D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBullet : public CWeapon  
{
private:
	int m_iOwner;//子弹的发射者
public:
	CBullet(const char* szName);
	virtual ~CBullet();
	void		SetOwner(int owner)			{m_iOwner=owner;}//set方法
	int			GetOwner()					{return m_iOwner;}//get方法
	void		OnMove(int iDir);//子弹移动
	void		OnSpriteColSprite(CWeapon* pSprite);//子弹与物体碰撞
	void		Reflect(CWeapon* pSprite,float x,float y);//子弹的反射方法

};

#endif // !defined(AFX_BULLET_H__CFFF5D79_D511_4C20_A3A9_6511F0BFD19D__INCLUDED_)
