// Weapon.h: interface for the CWeapon class.
//
//////////////////////////////////////////////////////////////////////

#include "CommonClass.h"
#if !defined(AFX_WEAPON_H__51A4F580_AC80_4A20_A223_12FD3CD79964__INCLUDED_)
#define AFX_WEAPON_H__51A4F580_AC80_4A20_A223_12FD3CD79964__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWeapon : public CSprite  
{
private:
	int			m_iDir;
	float		m_fSpeedX;
	float		m_fSpeedY;
	int			m_iHp;
	float		m_fRotSpeed;
public:
	CWeapon(const char* szName);
	virtual ~CWeapon();
	//set ����
	void			SetHp(int hp)  {m_iHp=hp;}
	void			SetDir(int dir)  {m_iDir=dir;}
	void			SetSpeedX(float speedX)  {m_fSpeedX=speedX;}
	void			SetSpeedY(float speedY)  {m_fSpeedY=speedY;}
	void			SetRotSpeed(float rotSpeed) {m_fRotSpeed=rotSpeed;}
	//get ����
	int				GetHp()  {return m_iHp;}
	int				GetDir()  {return m_iDir;}
	float			GetSpeedX()  {return m_fSpeedX;}
	float			GetSpeedY()  {return m_fSpeedY;}
	float			GetRotSpeed() {return m_fRotSpeed;}

	bool			IsDead();//�жϾ����Ƿ�����
	virtual void	Init(){};//��ʼ������
	virtual void	OnMove(float fDeltaTime){};//�з�̹���ƶ�����
	virtual void	OnMove(){};
	virtual void	OnFire(float deltaTime){};//�����ӵ�����
	virtual void	OnSpriteColSprite(CWeapon* pSprite){};//�����뾫����ײʱ����ĺ���

};

#endif // !defined(AFX_WEAPON_H__51A4F580_AC80_4A20_A223_12FD3CD79964__INCLUDED_)
