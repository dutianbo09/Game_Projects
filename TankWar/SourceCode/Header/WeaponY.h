// Weapon.h: interface for the CWeaponY class.
//
//////////////////////////////////////////////////////////////////////

#include "CommonClass.h"
#if !defined(AFX_WEAPONY_H__51A4F580_AC80_4A20_A223_12FD3CD79964__INCLUDED_)
#define AFX_WEAPONY_H__51A4F580_AC80_4A20_A223_12FD3CD79964__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWeaponY : public CSprite  
{
private:
	int						m_iDir;
	float					m_fSpeedX;
	float					m_fSpeedY;
	int						m_iHp;
public:
	CWeaponY(const char* szName);
	virtual ~CWeaponY();
	//set 方法
	void					SetHp(int hp)  {m_iHp=hp;}
	void					SetDir(int dir)  {m_iDir=dir;}
	void					SetSpeedX(float speedX)  {m_fSpeedX=speedX;}
	void					SetSpeedY(float speedY)  {m_fSpeedY=speedY;}
	//get 方法
	int						GetHp()  {return m_iHp;}
	int						GetDir()  {return m_iDir;}
	float					GetSpeedX()  {return m_fSpeedX;}
	float					GetSpeedY()  {return m_fSpeedY;}

	bool IsDead();//判断精灵是否死亡
	virtual void			Init(){};//初始化函数
	virtual void			OnMove(float fDeltaTime){};//敌方坦克移动函数
	virtual void			OnMove(){};
	virtual void			OnFire(float deltaTime){};//发射子弹函数
	virtual void			OnSpriteColSprite(CWeaponY* pSprite){};//精灵与精灵碰撞时处理的函数


};

#endif // !defined(AFX_WEAPON_H__51A4F580_AC80_4A20_A223_12FD3CD79964__INCLUDED_)
