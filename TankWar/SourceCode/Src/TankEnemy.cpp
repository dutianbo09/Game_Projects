// TankEnemy.cpp: implementation of the CTankEnemy class.
//
//////////////////////////////////////////////////////////////////////

#include "TankEnemy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTankEnemy::CTankEnemy(const char* szName):CWeapon(szName)
{

}

CTankEnemy::~CTankEnemy()
{

}

void CTankEnemy::Init()
{
	SetHp(2);
	SetSpritePosition(0 ,5);
	SetSpriteWorldLimit(WORLD_LIMIT_NULL,-32,-27.4,32,27.4);
	SetSpriteCollisionActive(1,1);//设置为可以接受和发生碰撞
	SetSpriteVisible(true);
}

void CTankEnemy::OnMove(int iKey,bool bPress)
{
	if(bPress)
	{
		switch(iKey)
		{
		case KEY_UP:
		
			SetSpeedX(30*sin(GetSpriteRotation()/180*3.14));
			SetSpeedY(-30*cos(GetSpriteRotation()/180*3.14));
			break;
		case KEY_RIGHT:
			SetSpriteAngularVelocity(160.f);
			break;
		case KEY_DOWN:
			SetSpeedX(-20*sin(GetSpriteRotation()/180*3.14));
			SetSpeedY(20*cos(GetSpriteRotation()/180*3.14));
			break;
		case KEY_LEFT:
			SetSpriteAngularVelocity(-160.f);
			break;
		}
	
		SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
	}
	else
	{
		if(iKey==KEY_UP||iKey==KEY_LEFT||iKey==KEY_DOWN||iKey==KEY_RIGHT)
		{
			SetSpeedX(0);
			SetSpeedY(0);
			SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
			SetSpriteAngularVelocity(0.f);
		}
	}

}
void CTankEnemy::OnFire()
{
	float x,y;
	x=GetSpriteLinkPointPosX(1)+1*sin(GetSpriteRotation()/180*3.14);
	y=GetSpriteLinkPointPosY(1)-1*cos(GetSpriteRotation()/180*3.14);
	g_GameMainX.AddBullet(x,y,0);
}

void CTankEnemy::OnSpriteColSprite(CWeapon* pSprite)
{
	if(pSprite==NULL)
	{
		return;
	}
	else if(strstr(pSprite->GetName(),"bullet")!=NULL)
	{
		SetHp(0);		
	}
	else if(strstr(pSprite->GetName(),"wall")!=NULL||strstr(pSprite->GetName(),"myPlayer")!=NULL)
	{
		SetSpeedX(0);
		SetSpeedY(0);
		SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
	}
}
