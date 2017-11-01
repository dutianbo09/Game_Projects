// Bullet.cpp: implementation of the CBullet class.
//
//////////////////////////////////////////////////////////////////////

#include "Bullet.h"
#include "LessonX.h"
#include <iostream>
#include <fstream>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBullet::CBullet(const char* szName):CWeapon(szName)
{

	m_iOwner=0;

}

CBullet::~CBullet()
{

}

void CBullet::OnMove(int iOwner)
{
	if(iOwner==1)
	{
	SetSpriteRotation(g_GameMainX.GetTankPlayerRotation());
	SetSpeedX(50*sin(GetSpriteRotation()/180*3.14));
	SetSpeedY(-50*cos(GetSpriteRotation()/180*3.14));
	SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
	}
	else if(iOwner==0)
	{
	SetSpriteRotation(g_GameMainX.GetTankEnemyRotation());
	SetSpeedX(50*sin(GetSpriteRotation()/180*3.14));
	SetSpeedY(-50*cos(GetSpriteRotation()/180*3.14));
	SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
	}
}

void CBullet::OnSpriteColSprite(CWeapon *pSprite)
{
	if(GetOwner()==1&&strstr(pSprite->GetName(),"enemy")!=NULL)//我方坦克子弹与敌方相撞
	{
		SetHp(0);
		pSprite->SetHp(0);
		return;
	}
	if(GetOwner()==0&&strstr(pSprite->GetName(),"myplayer")!=NULL)//敌方坦克子弹与我方相撞
	{
		SetHp(0);
		pSprite->SetHp(0);
		return;
	}
	if(GetOwner()==0&&strstr(pSprite->GetName(),"enemy")!=NULL)//敌方坦克子弹与敌方相撞
	{
		SetHp(0);
		pSprite->SetHp(0);
		return;

	}
	if(GetOwner()==1&&strstr(pSprite->GetName(),"myPlayer")!=NULL)//我方坦克子弹与我方相遇
	{
		SetHp(0);
		return;
	}
	if(GetOwner()==1&&strstr(pSprite->GetName(),"wall")!=NULL)//我方坦克子弹与墙相遇
	{
		SetHp(GetHp()-1);
		Reflect(pSprite,GetSpritePositionX(),GetSpritePositionY());
		return;
	}
    if(GetOwner()==0&&strstr(pSprite->GetName(),"wall")!=NULL)//敌方坦克子弹与墙相遇
	{
	    SetHp(GetHp()-1);
		Reflect(pSprite,GetSpritePositionX(),GetSpritePositionY());
		return;
	
	}
	SetHp(0);
	pSprite->SetHp(0);
}

void CBullet::Reflect(CWeapon* pSprite,float x,float y)
{
	float vx=GetSpeedX(),vy=GetSpeedY();
	if(vx>0 && vy<0) //子弹向右上角飞去
	{
		 if(pSprite->IsPointInSprite(x,y-1))
		{
	     		SetSpeedY(-GetSpeedY());
			
			
		}
		else if(pSprite->IsPointInSprite(x+1,y))
		{
				SetSpeedX(-GetSpeedX());
				
		}
		else if(pSprite->IsPointInSprite(x+1,y-1))
		{
				SetSpeedX(-GetSpeedX());
				SetSpeedY(-GetSpeedY());
			

		}
	}
	if(vx>0 && vy>0) //子弹向右下角飞去
	{
		 if(pSprite->IsPointInSprite(x,y+1))
		{
				SetSpeedY(-GetSpeedY());
				
		
		}
		else if(pSprite->IsPointInSprite(x+1,y))
		{
				SetSpeedX(-GetSpeedX());
				
			
		}
		else if(pSprite->IsPointInSprite(x+1,y+1))
		{
				SetSpeedX(-GetSpeedX());
				SetSpeedY(-GetSpeedY());
			

		}
		
	}
	if(vx<0 && vy>0) //子弹向左下角飞去
	{
		 if(pSprite->IsPointInSprite(x,y+1))
			{
				SetSpeedY(-GetSpeedY());
				
			
			}
		else if(pSprite->IsPointInSprite(x-1,y))
			{
				SetSpeedX(-GetSpeedX());
				
			
			}
		else if(pSprite->IsPointInSprite(x-1,y+1))
		{
				SetSpeedX(-GetSpeedX());
				SetSpeedY(-GetSpeedY());
			

		}
	
	}

	if(vx<0 && vy<0) //子弹向左上角飞去
	{
		if(pSprite->IsPointInSprite(x,y-1))
			{
				SetSpeedY(-GetSpeedY());
				
			
			}
		else if(pSprite->IsPointInSprite(x-1,y))
			{
				SetSpeedX(-GetSpeedX());
				
			
			}
		else if(pSprite->IsPointInSprite(x-1,y-1))
		{
				SetSpeedX(-GetSpeedX());
				SetSpeedY(GetSpeedY());
			
		}
	
	}
	if(vx==0||vy==0)//子弹垂直飞行
	{
		if(pSprite->IsPointInSprite(x,y-1))
		{
			SetSpeedY(-GetSpeedY());

		}
		else if(pSprite->IsPointInSprite(x-1,y))
		{
			SetSpeedX(-GetSpeedX());
		}
		else if(pSprite->IsPointInSprite(x,y+1))
			{
				SetSpeedY(-GetSpeedY());
				
			
			}
		else if(pSprite->IsPointInSprite(x+1,y))
			{
				SetSpeedX(-GetSpeedX());
				
			}
	}
	SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());

}
