// TankEnemy.cpp: implementation of the CTankEnemy class.
//
//////////////////////////////////////////////////////////////////////

#include "TankEnemyY.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTankEnemyY::CTankEnemyY(const char* szName):CWeaponY(szName)
{

	m_fChangeDirTime=0.f;
	m_fBulletCreateTime=0.f;

}

CTankEnemyY::~CTankEnemyY()
{

}

void CTankEnemyY::Init()
{
	int iPos = CSystem::RandomRange(0,2);
	float fPosX;
    SetDir(2);
	SetHp(2);
	switch(iPos)
	{
	case 0:
		fPosX=-24.f;
		break;
	case 1:
		fPosX=0.f;
		break;
	case 2:
		fPosX=24.f;
		break;
	default:
		break;
	}
	SetSpritePosition(fPosX,-20.f);
	SetSpriteLinearVelocity(0.f,20.f);
	SetSpriteWorldLimit(WORLD_LIMIT_NULL,-32.1f,-27.8f,32.1f,27.8f);
	SetSpriteCollisionActive(1,1);//设置为可以接受和发生碰撞
	SetSpriteRotation(float(90*GetDir()));
	SetSpriteVisible(true);
}

void CTankEnemyY::OnMove()
{
	int iDir=0;
	if(GetDir()==0||GetDir()==1||GetDir()==2)
	{
		iDir=GetDir()+1;
  
	}
	else//如果方向值为3，则设为0	
	{
		iDir=0;
	}
	SetDir(iDir);
	SetSpriteRotation(float(90*GetDir()));
	switch(GetDir())
	{
	case 0:
		SetSpeedX(0);
		SetSpeedY(-20);
		break;
	case 1:
		SetSpeedX(20);
		SetSpeedY(0);
		break;
	case 2:
		SetSpeedX(0);
		SetSpeedY(20);
		break;
	case 3:
		SetSpeedX(-20);
		SetSpeedY(0);
		break;
	}
	SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());

}

void CTankEnemyY::OnMove(float fDeltaTime)
{
	m_fChangeDirTime+=fDeltaTime;
	if(m_fChangeDirTime>2.0f)
	{
		OnMove();
		
		m_fChangeDirTime=0.f;
	}


}

void CTankEnemyY::OnFire(float fDeltaTime)
{
	m_fBulletCreateTime+=fDeltaTime;
	if(m_fBulletCreateTime>1.f)
	{
		m_fBulletCreateTime=0.f;
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
		g_GameMainY.AddBullet(GetDir(),x,y,0);
	}
}

void CTankEnemyY::OnSpriteColSprite(CWeaponY* pSprite)
{
	if(pSprite==NULL)
	{
		return;
	}
	SetSpriteLinearVelocity(0.f,0.f);
	m_fChangeDirTime=1.9f;
}

