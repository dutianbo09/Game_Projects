// TankPlayer.cpp: implementation of the CTankPlayer class.
//
//////////////////////////////////////////////////////////////////////

#include "TankPlayer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTankPlayer::CTankPlayer(const char* szName):CWeapon(szName)
{
	

}

CTankPlayer::~CTankPlayer()
{

}

void CTankPlayer::Init()
{
	SetHp(2);
	SetSpritePosition(0.f,0.f);
	SetSpriteWorldLimit(WORLD_LIMIT_NULL,-32,-27.4,32,27.4);
	SetSpriteCollisionActive(1,1);//设置为可以接受和发生碰撞
	SetSpriteVisible(true);
	SetSpriteRotation(0);
}

void CTankPlayer::OnMove(int iKey,bool bPress)
{
	if(bPress)
	{
		switch(iKey)
		{
		case KEY_W:
		
			SetSpeedX(30*sin(GetSpriteRotation()/180*3.14));
			SetSpeedY(-30*cos(GetSpriteRotation()/180*3.14));
			break;
		case KEY_D:
			SetSpriteAngularVelocity(160.f);
			break;
		case KEY_S:
			SetSpeedX(-20*sin(GetSpriteRotation()/180*3.14));
			SetSpeedY(20*cos(GetSpriteRotation()/180*3.14));
			break;
		case KEY_A:
			SetSpriteAngularVelocity(-160.f);
			break;
		}
	
		SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
	}
	else
	{
		if(iKey==KEY_W||iKey==KEY_A||iKey==KEY_S||iKey==KEY_D)
		{
			SetSpeedX(0);
			SetSpeedY(0);
			SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
			SetSpriteAngularVelocity(0.f);
		}
	}
		
}

void CTankPlayer::OnFire()
{
	float x,y;
	x=GetSpriteLinkPointPosX(1)+1*sin(GetSpriteRotation()/180*3.14);
	y=GetSpriteLinkPointPosY(1)-1*cos(GetSpriteRotation()/180*3.14);
	g_GameMainX.AddBullet(x,y,1);
}

void CTankPlayer::OnSpriteColSprite(CWeapon* pSprite)
{
	if(pSprite==NULL)
	{
	
		return;
	}
	else if(strstr(pSprite->GetName(),"bullet")!=NULL)
	{
		SetHp(0);
		
	}
	else if(strstr(pSprite->GetName(),"wall")!=NULL||strstr(pSprite->GetName(),"enemy")!=NULL)
	{
		SetSpeedX(0);
		SetSpeedY(0);
		SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
	}
}
