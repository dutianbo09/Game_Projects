/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonY.h"
#include <ctime>
#include <iostream>
#include <fstream>
////////////////////////////////////////////////////////////////////////////////
//
//
CGameMainY		g_GameMainY;	
//��ͼ
int g_iMapY[28][33]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{2,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,1,0,1},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{2,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1},
	{1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1},
	{1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,1},
	{1,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,1,1,1,1,1,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,2,2,2,2,2,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1},
	{1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,1,1,0,0,0,0,2,2,2,2,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,3,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,2,2,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1},
	{1,0,0,0,1,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};


//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
CGameMainY::CGameMainY()
{
	m_iGameState			=	0;
	m_iEnemyDeath			=	0;
	count=0;
	m_pTitle = new CSprite("Title");
	m_pGameOver = new CSprite("gameover");
	m_pRankBackground = new CSprite("rankbackground");
	m_pBGM	=	new CSound("BGM",true,1);
	m_pBomb  =  new CSound("baozha",false,1);
	m_pBiu  =  new CSound("paizi",false,1);
	m_iBulletNum = 0;
	m_fTankEnemyTime = 0.f;
	m_iTankEnemyNumber = 0;
	m_pScore= new CTextSprite("score");
	m_pHight= new CTextSprite("hight");
	m_pTime= new CTextSprite("time");
	m_pRank= new CTextSprite("rank");
	m_fGameTime= 0.f;
	m_iHight=OutputHight();
}
//==============================================================================
//
// ��������
CGameMainY::~CGameMainY()
{

	delete m_pTitle;
	delete m_pTankPlayer;
	delete m_pGameOver;	
}

//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬. 
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void CGameMainY::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
		{
			GameInit();
			SetGameState(2); // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
		}
		break;

		// ��Ϸ�����У����������Ϸ�߼�
	case 2:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;

		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void CGameMainY::GameInit()
{
	m_pTitle->SetSpriteVisible(false);
	m_pBGM->PlaySound();
	m_pTankPlayer=new CTankPlayerY("myPlayer");//�½�һ��������myPlayer���ҷ�̹�˶���
    m_pTankPlayer->CloneSprite("player");//�ҷ�̹�˿�¡��funcodeģ����е�����Ϊplayer��̹�ˣ���ʾ�½���̹�˶��������ھ������������
    m_pTankPlayer->Init();
	LoadMap();
	m_vWeapon.push_back(m_pTankPlayer);
	{
	time_t now_time;
	now_time = time(NULL);
	m_fTime0= now_time;
	}
	m_pBGM->PlaySound();
    m_pEffect  =  new CEffect("enemyExplosion","Bomb",3.0f);
	m_pAim_nor  =  new CWeaponY("myaim_nor");
	m_pAim_nor->CloneSprite("aim_nor");
	m_vWeapon.push_back(m_pAim_nor);
	m_pAim_nor->SetSpriteCollisionReceive(true);
	m_pAim_nor->SetSpritePosition(0,26.f);


}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMainY::GameRun( float fDeltaTime )
{
	//��ʾ��ǰʱ��
		time_t now_time1;
		now_time1 = time(NULL);
		m_fGameTime=now_time1-m_fTime0;
	
	if(m_fGameTime<=30)
		m_pTime->SetTextValue(30-m_fGameTime); 
	else 
		m_pTime->SetTextValue(0);
	if(m_fGameTime>=30)
		{
		GameEnd();
		}
	
	m_pScore->SetTextValue(m_iEnemyDeath);
	m_pHight->SetTextValue(m_iHight);
	AddTankEnemy(fDeltaTime);
	static int TankPlayerNumber=0;

	for(int i=0;i<m_vWeapon.size();i++)
	{
		m_vWeapon[i]->OnMove(fDeltaTime);
		m_vWeapon[i]->OnFire(fDeltaTime);
	}
	for(i=0;i<m_vWeapon.size();i++)
	{
		
		if(!m_vWeapon[i]->IsDead())
		{
			m_vWeapon[i]->OnMove(fDeltaTime);
			m_vWeapon[i]->OnFire(fDeltaTime);
		}
		else if(m_pTankPlayer->IsDead()&&TankPlayerNumber<3)
		{
			
			m_pTankPlayer->SetSpritePositionX(0);
			m_pTankPlayer->SetSpritePositionY(0);
			m_pTankPlayer->Init();
			TankPlayerNumber++;
		}
			else if(TankPlayerNumber==3)
					{
					GameEnd();
					}
				else if(m_pAim_nor->IsDead())
					{
					GameEnd();
					}
					else
						{
						if(strstr(m_vWeapon[i]->GetName(),"enemy")!=NULL)
							m_iEnemyDeath++;
						DeleteWeaponByName(m_vWeapon[i]->GetName());
						}
		
	}
}
//=============================================================================
//
// ������Ϸ����
void CGameMainY::GameEnd()
{
	m_pGameOver->SetSpritePosition(0,0);
	m_pGameOver->SetSpriteVisible(true);
	m_pRankBackground->SetSpritePosition(0,0);
	m_pRankBackground->SetSpriteVisible(true);
	if(count==0)
	{
		InputToFile();	
		count++;
	}
}
//==========================================================================
//
// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMainY::OnMouseMove( const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMainY::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMainY::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void CGameMainY::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
	

	if(m_iGameState==2)
	{
		m_pTankPlayer->OnMove(iKey,true);
		if(iKey == KEY_J)//�жϰ��µ��Ƿ�ΪJ��
		{
			m_pTankPlayer->OnFire();
		}
	}

}
//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void CGameMainY::OnKeyUp( const int iKey )
{
	if(0==GetGameState())
	{
		if(iKey==KEY_1)
		{
			m_iGameState=1;
		}
	}
	if(m_iGameState==2)
	{
		m_pTankPlayer->OnMove(iKey,false);
	}
	
}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void CGameMainY::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	CWeaponY* tarSprite = FindWeaponByName(szTarName);
	if(strstr(szSrcName,"bullet")!=NULL)//������ײΪ�ӵ�
	{
		CBulletY* tmpBullet=(CBulletY*)FindWeaponByName(szSrcName);
		tmpBullet->OnSpriteColSprite(tarSprite);
		if(strstr(tarSprite->GetName(),"enemy")!=NULL)
		{
		m_pEffect->PlayEffect(tarSprite->GetSpritePositionX(),tarSprite->GetSpritePositionY(),0.f);
		m_pBomb->PlaySound();
		}

	}
	else if(strcmp(szSrcName,"myPlayer")==0)//������ײΪ�ҷ�̹��
	{
		m_pTankPlayer->OnSpriteColSprite(tarSprite);
	}
	else if(strstr(szSrcName,"enemy")!=NULL)//������ײΪ�з�̹��
	{
		CTankEnemyY* tmpEnemy=(CTankEnemyY*)FindWeaponByName(szSrcName);
		tmpEnemy->OnSpriteColSprite(tarSprite);

	}
	
}
//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void CGameMainY::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{

	for(int i=0;i<m_vWeapon.size();i++)
	{
		//�ҷ�̹�������߽�Ĵ�����
		if(strstr((FindWeaponByName("myPlayer")->GetName()),szName)!=NULL)
		{
				m_pTankPlayer->SetSpriteLinearVelocity(0,0);

		}
		//�з�̹�������߽�Ĵ�����
		else if(strstr(szName,"enemy")!=NULL)
		{
			CWeaponY* tmpWeapon= FindWeaponByName(szName);
			if(iColSide==0&&tmpWeapon->GetSpritePositionX()<0.f)
			{
				tmpWeapon->OnMove();
			tmpWeapon->SetSpritePositionX(tmpWeapon->GetSpritePositionX()+0.01f);
			}
		    if(iColSide==1&&tmpWeapon->GetSpritePositionX()>=0.f)
			{
				tmpWeapon->OnMove();
			    tmpWeapon->SetSpritePositionX(tmpWeapon->GetSpritePositionX()-0.01f);
			}
		    if(iColSide==2&&tmpWeapon->GetSpritePositionY()<0.f)
			{
				tmpWeapon->OnMove();
		        tmpWeapon->SetSpritePositionY(tmpWeapon->GetSpritePositionY()+0.01f);
			}
	     	if(iColSide==3&&tmpWeapon->GetSpritePositionY()>=0.f)
			{
				tmpWeapon->OnMove();
			    tmpWeapon->SetSpritePositionY(tmpWeapon->GetSpritePositionY()-0.01f);
			}
		   
		}
		//����������߽���ӵ�����
		else if(strstr(szName,"bullet")!=NULL)
		{
			CWeaponY* pBullet = FindWeaponByName(szName);
			pBullet->SetHp(0);

		}
	}	
}

void CGameMainY::AddBullet(int iDir,float fPosX,float fPosY, int iOwner)
{
	m_pBiu->PlaySound();
	char* szName=CSystem::MakeSpriteName("bullet",m_iBulletNum);//�����ӵ�����
	CBulletY* pBullet = new CBulletY(szName);
	pBullet->CloneSprite("bullet");
    pBullet->SetSpriteWorldLimit(WORLD_LIMIT_NULL,-32,-27.4,32,27.4);//���ñ߽�
	pBullet->SetSpritePosition(fPosX,fPosY);
	pBullet->SetSpriteCollisionSend(true);
	pBullet->OnMove(iDir);
	m_iBulletNum++;//�ӵ�������һ
	if(iOwner==1)
	{
		pBullet->SetOwner(1);//1��ʾ�ҷ�̹�˷�����ӵ�

	}
	else
	{
		pBullet->SetOwner(0);//0��ʾ�з�̹�˷�����ӵ�

	}

	m_vWeapon.push_back(pBullet);
	

}

void CGameMainY::LoadMap()
{
	char* szName;
	int i,j;
	float x,y;
	for(i=0;i<28;i++)
	{
		for(j=0;j<33;j++)
		{
			if(g_iMapY[i][j]==1)
			{
				szName=CSystem::MakeSpriteName("wall",j+i*13+i);//��������
				CWeaponY* pWall = new CWeaponY(szName);//�½�����
				pWall->CloneSprite("wall");//��¡ǽ��
				pWall->SetSpriteCollisionActive(0,1);//����Ϊ������ײ
				pWall->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
				x=float(-32.5+2*j);
				y=float(-27+2*i);
				pWall->SetSpritePosition(x,y);
				m_vWeapon.push_back(pWall);
				
			}
			if(g_iMapY[i][j]==2)
			{
				szName=CSystem::MakeSpriteName("ironWall",j+i*13+i);//��������
				CWeaponY* pWall = new CWeaponY(szName);//�½�����
				pWall->CloneSprite("ironwall");//��¡ǽ��
				pWall->SetSpriteCollisionActive(0,1);//����Ϊ������ײ
				pWall->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
				x=float(-32.5+2*j);
				y=float(-27+2*i);
				pWall->SetSpritePosition(x,y);
				m_vWeapon.push_back(pWall);
			}
			if(g_iMapY[i][j]==3)
			{
				szName=CSystem::MakeSpriteName("Grass",j+i*13+i);//��������
				CWeaponY* pWall = new CWeaponY(szName);//�½�����
				pWall->CloneSprite("grass");//��¡ǽ��
				pWall->SetSpriteCollisionActive(0,1);//����Ϊ������ײ
				pWall->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
				x=float(-32.5+2*j);
				y=float(-27+2*i);
				pWall->SetSpritePosition(x,y);
				m_vWeapon.push_back(pWall);
			}
		}
	}	
}

CWeaponY* CGameMainY::FindWeaponByName(const char* szName)
{
	for(int i=0;i<m_vWeapon.size();i++)
	{
		if(strcmp(szName,m_vWeapon[i]->GetName())==0)
		{
			return m_vWeapon[i];
		}
	}
}

void CGameMainY::DeleteWeaponByName(const char* szName)
{
	for(vector<CWeaponY*>::iterator it=m_vWeapon.begin();it!=m_vWeapon.end();)
	{
		CWeaponY* cw = *it;
		if(strcmp(szName,cw->GetName())==0)
		{
			m_vWeapon.erase(it);
			cw->DeleteSprite();
			delete cw;
			break;
		}
		else
		{
			it++;
		}
	}
}

void CGameMainY::AddTankEnemy(float fDeltaTime)
{
	m_fTankEnemyTime+=fDeltaTime;
	if(m_fTankEnemyTime>5.0f)
	{
		char szName[128];
		sprintf(szName,"enemy%d",m_iTankEnemyNumber);
		CTankEnemyY* m_pTankEnemy = new CTankEnemyY(szName);
		m_pTankEnemy->CloneSprite("enemy");
		m_pTankEnemy->Init();
		m_iTankEnemyNumber++;
		m_vWeapon.push_back(m_pTankEnemy);//�Ѵ����ĵз�̹�˲��뵽��������
		m_fTankEnemyTime = 0.f;
	}
}
void CGameMainY::InputToFile()
{
	ofstream fs;
	fs.open("score2.txt",ios::app);
	fs<<m_iEnemyDeath<<endl;
	fs.close();
}
int CGameMainY::OutputHight()
{
	ifstream onfile;
	onfile.open("score2.txt");
	int a[100]={0};
	int i=0;
	while(onfile.good())
	{
		int temp;
		onfile>>temp;
		a[i]=temp;
		i++;
	}

	int max=a[0];
	for(i=0;a[i]!=0;i++)
		{
			if(a[i]>=max)
				max=a[i];
		}
	onfile.close();
	return max;
}
