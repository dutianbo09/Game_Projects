// Bullet.h: interface for the CBullet class.
//
//////////////////////////////////////////////////////////////////////

#include "CommonClass.h"
#include "WeaponY.h"
#if !defined(AFX_BULLETY_H__CFFF5D79_D511_4C20_A3A9_6511F0BFD19D__INCLUDED_)
#define AFX_BULLET_H__CFFF5D79_D511_4C20_A3A9_6511F0BFD19D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBulletY : public CWeaponY  
{
private:
	int m_iOwner;//�ӵ��ķ�����
public:
	CBulletY(const char* szName);
	virtual ~CBulletY();
	void			SetOwner(int owner)  {m_iOwner=owner;}//set����
	int				GetOwner()  {return m_iOwner;}//get����
	void			OnMove(int iDir);//onmove����
	void			OnSpriteColSprite(CWeaponY* pSprite);//�ӵ���ײ

};

#endif // !defined(AFX_BULLET_H__CFFF5D79_D511_4C20_A3A9_6511F0BFD19D__INCLUDED_)
