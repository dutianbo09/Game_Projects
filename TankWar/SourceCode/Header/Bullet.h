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
	int m_iOwner;//�ӵ��ķ�����
public:
	CBullet(const char* szName);
	virtual ~CBullet();
	void		SetOwner(int owner)			{m_iOwner=owner;}//set����
	int			GetOwner()					{return m_iOwner;}//get����
	void		OnMove(int iDir);//�ӵ��ƶ�
	void		OnSpriteColSprite(CWeapon* pSprite);//�ӵ���������ײ
	void		Reflect(CWeapon* pSprite,float x,float y);//�ӵ��ķ��䷽��

};

#endif // !defined(AFX_BULLET_H__CFFF5D79_D511_4C20_A3A9_6511F0BFD19D__INCLUDED_)
