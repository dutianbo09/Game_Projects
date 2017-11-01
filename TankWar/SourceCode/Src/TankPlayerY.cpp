// TankPlayer.cpp: implementation of the CTankPlayerY class.
//
//////////////////////////////////////////////////////////////////////

#include "TankPlayerY.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTankPlayerY::CTankPlayerY(const char* szName):CWeaponY(szName)
{


}

CTankPlayerY::~CTankPlayerY()
{

}

void CTankPlayerY::Init()
{
	SetHp(2);
	SetSpritePosition(0.f,0.f);
	SetSpriteWorldLimit(WORLD_LIMIT_NULL,-32,-27.4,32,27.4);
	SetSpriteCollisionActive(1,1);//设置为可以接受和发生碰撞
	SetSpriteVisible(true);
}

void CTankPlayerY::OnMove(int iKey,bool bPress)
{
	if(bPress)
	{
		switch(iKey)
		{
		case KEY_W:
			SetDir(0);
			SetSpeedX(0);
			SetSpeedY(-20);
			break;
		case KEY_D:
			SetDir(1);
			SetSpeedX(20);
			SetSpeedY(0);
			break;
		case KEY_S:
            SetDir(2);
			SetSpeedX(0);
			SetSpeedY(20);
			break;
		case KEY_A:
			SetDir(3);
			SetSpeedX(-20);
			SetSpeedY(0);
			break;
		}
		SetSpriteRotation(float (90*GetDir()));//用方向值乘以九十得到精灵旋转度数
		SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
	}
	else
	{
		if(iKey==KEY_W||iKey==KEY_A||iKey==KEY_S||iKey==KEY_D)
		{
			SetSpeedX(0);
			SetSpeedY(0);
			SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
		}
	}
		
}

void CTankPlayerY::OnFire()
{
	float x,y;
	x=GetSpritePositionX();
	y=GetSpritePositionY();
	switch(GetDir())
	{
	case 0:
		y=y-GetSpriteHeight()/2-2;
		break;
	case 1:
		x=x+GetSpriteWidth()/2+2;
		break;
	case 2:
		y=y+GetSpriteHeight()/2+2;
		break;
	case 3:
		x=x-GetSpriteHeight()/2-2;
		break;
    }
	g_GameMainY.AddBullet(GetDir(),x,y,1);
}

void CTankPlayerY::OnSpriteColSprite(CWeaponY* pSprite)
{
	if(pSprite==NULL)
	{
	
		return;
	}
	else if(strstr(pSprite->GetName(),"bullet")!=NULL)
	{
		SetHp(0);
		
	}
	else if(strstr(pSprite->GetName(),"wall")!=NULL||strstr(pSprite->GetName(),"enemy")!=NULL||strstr(pSprite->GetName(),"ironWall")!=NULL)
	{
		SetSpeedX(0);
		SetSpeedY(0);
		SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
	}
}
