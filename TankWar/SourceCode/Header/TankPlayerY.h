// TankPlayer.h: interface for the CTankPlayer class.
//
//////////////////////////////////////////////////////////////////////
#include "CommonClass.h"
#include "LessonY.h"
#include "WeaponY.h"

#if !defined(AFX_TANKPLAYERY_H__A57D5525_FC47_41C4_9593_9D1BC319193C__INCLUDED_)
#define AFX_TANKPLAYERY_H__A57D5525_FC47_41C4_9593_9D1BC319193C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTankPlayerY : public CWeaponY  
{
private:
	
public:
	CTankPlayerY(const char* szName);
	virtual ~CTankPlayerY();
	void		Init();
	void		OnMove(int iKey,bool bPress);
	void		OnFire();
	void		OnSpriteColSprite(CWeaponY* pSprite);

};

#endif // !defined(AFX_TANKPLAYER_H__A57D5525_FC47_41C4_9593_9D1BC319193C__INCLUDED_)
