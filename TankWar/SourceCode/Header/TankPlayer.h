// TankPlayer.h: interface for the CTankPlayer class.
//
//////////////////////////////////////////////////////////////////////
#include "CommonClass.h"
#include "LessonX.h"
#include "Weapon.h"
#include <math.h>

#if !defined(AFX_TANKPLAYER_H__A57D5525_FC47_41C4_9593_9D1BC319193C__INCLUDED_)
#define AFX_TANKPLAYER_H__A57D5525_FC47_41C4_9593_9D1BC319193C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTankPlayer : public CWeapon  
{
private:

public:
	CTankPlayer(const char* szName);
	virtual ~CTankPlayer();	
	void		Init();
    void		OnMove(int iKey,bool bPress);
	void		OnFire();
	void		OnSpriteColSprite(CWeapon* pSprite);
	float		GetTankPlayerRotation() {return GetSpriteRotation();}
	friend class CBullet;
	float		GetTankEnemyRotation() {return GetSpriteRotation();}
};

#endif // !defined(AFX_TANKPLAYER_H__A57D5525_FC47_41C4_9593_9D1BC319193C__INCLUDED_)
