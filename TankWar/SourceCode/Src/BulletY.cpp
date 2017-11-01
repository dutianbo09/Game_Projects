// Bullet.cpp: implementation of the CBullet class.
//
//////////////////////////////////////////////////////////////////////

#include "BulletY.h"
#include "LessonY.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBulletY::CBulletY(const char* szName):CWeaponY(szName)
{
	
	m_iOwner=1;

}

CBulletY::~CBulletY()
{

}

void CBulletY::OnMove(int iDir)
{
	SetDir(iDir);
	switch(GetDir())
	{
	case 0:
		SetSpeedX(0);
		SetSpeedY(-50);
		break;
	case 1:
		SetSpeedX(50);
		SetSpeedY(0);
		break;
	case 2:
		SetSpeedX(0);
		SetSpeedY(50);
		break;
	case 3:
		SetSpeedX(-50);
		SetSpeedY(0);
		break;
	}
	SetSpriteRotation(float (90*GetDir()));
	SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
}

void CBulletY::OnSpriteColSprite(CWeaponY *pSprite)
{
	if(pSprite==NULL)
	{
		return;
	}
	
	if(GetOwner()==1&&strstr(pSprite->GetName(),"aim_nor")!=NULL)//�ҷ�̹���ӵ����Ӫ��ײ
	{
	    SetHp(0);
		return;

	}
	if(GetOwner()==0&&strstr(pSprite->GetName(),"enemy")!=NULL)//�з�̹���ӵ����ез�̹��
	{
		SetHp(0);
		return;
	}
	if(GetOwner()==0&&strstr(pSprite->GetName(),"ironWall")!=NULL)//�ҷ�̹���ӵ����и���
	{
		SetHp(0);
		return;
	}
	if(GetOwner()==1&&strstr(pSprite->GetName(),"ironWall")!=NULL)//�з�̹���ӵ����и���
	{
		SetHp(0);
		return;
	}
	if(GetOwner()==0&&strstr(pSprite->GetName(),"Grass")!=NULL)//�ҷ�̹���ӵ����вݵ�
	{
		
		return;
	}
	if(GetOwner()==1&&strstr(pSprite->GetName(),"Grass")!=NULL)//�з�̹���ӵ����вݵ�
	{
	
		return;
	}
	SetHp(0);
	pSprite->SetHp(0);

}
