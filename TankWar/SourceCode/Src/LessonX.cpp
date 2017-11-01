/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonX.h"
#include <ctime>
#include <iostream>
#include <fstream>
////////////////////////////////////////////////////////////////////////////////
//
//
CGameMainX		g_GameMainX;	
//���ݴ洢�ṹ��
#define N 100
struct Score
{
	int num;
	int fen;
};
Score course[N];

//��ͼ
int g_iMap[28][33]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1},
	{1,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,3,0,0,0,1},
	{1,0,0,0,3,3,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,0,1},
	{2,0,0,3,3,3,0,0,0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,3,3,0,0,0,3,0,1,0,1},
	{2,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1},
	{2,3,3,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1},
	{1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1},
	{1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,1},
	{1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
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
CGameMainX::CGameMainX()
{
	m_iGameState			=	0;
	count=0;
	m_pTitle= new CSprite("Title");
	m_pGameOver = new CSprite("gameover");
	//m_pScoreTitle= new CSprite("scoretitle");//�������⾫��
	//m_pHightTitle=new CSprite("highttitle");//��߷ֱ��⾫��
	m_pBGM	=	new CSound("BGM",true,1);
	m_iBulletNum = 0;
	m_fTankEnemyTime = 0.f;
	m_iTankEnemyNumber = 0;
	m_pScore= new CTextSprite("score");
	m_pHight= new CTextSprite("hight");
	m_pScoreA=new CTextSprite("scoreA");
	m_pScoreB=new CTextSprite("scoreB");
	m_pTime= new CTextSprite("time");
	m_fGameTime= 0.f;
	m_iHight=OutputHight();
	//��ȡ��ǰʱ��
	
}
//==============================================================================
//
// ��������
CGameMainX::~CGameMainX()
{

	delete m_pTitle;
	delete m_pTankPlayer;
	delete m_pGameOver;
	delete m_pTankEnemy;
	delete m_pBGM;
	delete m_pEffect;
	
}

//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬. 
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void CGameMainX::GameMainLoop( float	fDeltaTime )
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
void CGameMainX::GameInit()
{
	m_pTitle->SetSpriteVisible(false);
	//m_pScoreTitle->SetSpriteVisible(false);//�������⾫��
	//m_pHightTitle->SetSpriteVisible(false);//��߷ֱ��⾫��
	

	
	m_pTankPlayer=new CTankPlayer("myPlayer");//�½�һ��������myPlayer���ҷ�̹�˶���
    m_pTankPlayer->CloneSprite("player");//�ҷ�̹�˿�¡��funcodeģ����е�����Ϊplayer��̹�ˣ���ʾ�½���̹�˶��������ھ������������
    m_pTankPlayer->Init();
	m_pTankEnemy = new CTankEnemy("enemy");
	m_pTankEnemy->CloneSprite("enemy");
	m_pTankEnemy->Init();
	LoadMap();
	m_vWeapon.push_back(m_pTankPlayer);
	m_vWeapon.push_back(m_pTankEnemy);
	{
	time_t now_time;
	now_time = time(NULL);
	m_fTime0= now_time;
	}
	m_pBGM->PlaySound();
	m_pEffect  =  new CEffect("enemyExplosion","Bomb",3.0f);
}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMainX::GameRun( float fDeltaTime )
{
	//��ʾ��ǰʱ��
		time_t now_time1;
		now_time1 = time(NULL);
		m_fGameTime=now_time1-m_fTime0;


	
	//m_pScore->SetTextValue(m_fGameTime);
	//m_pHight->SetTextValue(m_iHight);

	m_pTime->SetTextValue(60-m_fGameTime); 
	if(m_fGameTime>=60) GameEnd();
	static int TankPlayerNumber=0;//��ʾ�ҷ�̹����������
	static int TankEnemyNumber=0;//��ʾ�з�̹����������
	m_pScoreA->SetTextValue(TankEnemyNumber);
	m_pScoreB->SetTextValue(TankPlayerNumber);
	for(int i=0;i<m_vWeapon.size();i++)
	{
		if(!m_vWeapon[i]->IsDead())
		{
			m_vWeapon[i]->OnMove(fDeltaTime);
			m_vWeapon[i]->OnFire(fDeltaTime);
		}
		else if(m_pTankPlayer->IsDead()&&TankPlayerNumber<10)
		{
			m_pEffect->PlayEffect(m_pTankPlayer->GetSpritePositionX(),m_pTankPlayer->GetSpritePositionY(), m_pTankPlayer->GetTankEnemyRotation());
			m_pTankPlayer->Init();
			TankPlayerNumber++;
		}
		else if(TankPlayerNumber==10)
		{
			GameEnd();
		}
		else if(m_pTankEnemy->IsDead()&&TankEnemyNumber<10)
		{
	      	m_pEffect->PlayEffect(m_pTankEnemy->GetSpritePositionX(),m_pTankEnemy->GetSpritePositionY(), m_pTankEnemy->GetTankEnemyRotation());
			m_pTankEnemy->Init();
			TankEnemyNumber++;

		}
		else if(TankEnemyNumber==10)
		{
			GameEnd();
		}
		else
		{
			DeleteWeaponByName(m_vWeapon[i]->GetName());
		}
	}
}
//=============================================================================
//
// ������Ϸ����
void CGameMainX::GameEnd()
{
	m_pGameOver->SetSpritePosition(0,0);
	m_pGameOver->SetSpriteVisible(true);
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
void CGameMainX::OnMouseMove( const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMainX::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMainX::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void CGameMainX::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
	

	if(m_iGameState==2)
	{
		m_pTankPlayer->OnMove(iKey,true);
		if(iKey == KEY_J)//�жϰ��µ��Ƿ�ΪJ��
		{
			m_pTankPlayer->OnFire();
		}
	}
	if(m_iGameState==2)
	{
		m_pTankEnemy->OnMove(iKey,true);
		if(iKey == KEY_SPACE)//�жϰ��µ��Ƿ�Ϊ�ո��
		{
			m_pTankEnemy->OnFire();
		}
	}

}
//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void CGameMainX::OnKeyUp( const int iKey )
{
	if(0==GetGameState())
	{
		if(iKey==KEY_2)
		{
			m_iGameState=1;
		}
	}
	if(m_iGameState==2)
	{
		m_pTankPlayer->OnMove(iKey,false);
	}
	if(m_iGameState==2)
	{
		m_pTankEnemy->OnMove(iKey,false);
	}
	
	
}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void CGameMainX::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	CWeapon* tarSprite = FindWeaponByName(szTarName);
	if(strstr(szSrcName,"bullet")!=NULL)//������ײΪ�ӵ�
	{
		CBullet* tmpBullet=(CBullet*)FindWeaponByName(szSrcName);
		tmpBullet->OnSpriteColSprite(tarSprite);

	}
	else if(strcmp(szSrcName,"myPlayer")==0)//������ײΪ�ҷ�̹��
	{
		m_pTankPlayer->OnSpriteColSprite(tarSprite);
	}
	else if(strcmp(szSrcName,"enemy")==0)//������ײΪ�з�̹��
	{
		m_pTankEnemy->OnSpriteColSprite(tarSprite);
	}
	
}
//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void CGameMainX::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	if(strstr(szName,"myPlayer")!=NULL)//�ж���������߽��̹���Ƿ�Ϊ�ҷ�̹��
	{
		m_pTankPlayer->SetSpriteLinearVelocity(0,0);
	}
	if(strstr(szName,"enemy")!=NULL)//�ж���������߽��̹���Ƿ�Ϊ�з�̹��
	{
		m_pTankEnemy->SetSpriteLinearVelocity(0,0);
	}
	//����������߽���ӵ�����
	else if(strstr(szName,"bullet")!=NULL)
	{
			CWeapon* pBullet = FindWeaponByName(szName);
			pBullet->SetHp(0);

	}
}

void CGameMainX::AddBullet(float fPosX,float fPosY, int iOwner)
{
	char* szName=CSystem::MakeSpriteName("bullet",m_iBulletNum);//�����ӵ�����
	CBullet* pBullet = new CBullet(szName);
	pBullet->CloneSprite("bullet");
    pBullet->SetSpriteWorldLimit(WORLD_LIMIT_NULL,-32,-27.4,32,27.4);//���ñ߽�
	pBullet->SetSpritePosition(fPosX,fPosY);
	pBullet->SetSpriteCollisionSend(true);
	pBullet->OnMove(iOwner);
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

void CGameMainX::LoadMap()
{
	char* szName;
	int i,j;
	float x,y;
	for(i=0;i<28;i++)
	{
		for(j=0;j<33;j++)
		{
			if(g_iMap[i][j]==1)
			{
				szName=CSystem::MakeSpriteName("wall",j+i*13+i);//��������
				CWeapon* pWall = new CWeapon(szName);//�½�����
				pWall->CloneSprite("wall");//��¡ǽ��
				pWall->SetSpriteCollisionActive(0,1);//����Ϊ������ײ
				pWall->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
				x=float(-32+2*j);
				y=float(-27+2*i);
				pWall->SetSpritePosition(x,y);
				m_vWeapon.push_back(pWall);
			}
		}
	}
}

CWeapon* CGameMainX::FindWeaponByName(const char* szName)
{
	for(int i=0;i<m_vWeapon.size();i++)
	{
		if(strcmp(szName,m_vWeapon[i]->GetName())==0)
		{
			return m_vWeapon[i];
		}
	}
}

void CGameMainX::DeleteWeaponByName(const char* szName)
{
	for(vector<CWeapon*>::iterator it=m_vWeapon.begin();it!=m_vWeapon.end();)
	{
		CWeapon* cw = *it;
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
void CGameMainX::InputToFile()
{
	ofstream fs;
	fs.open("score1.txt",ios::app);
	fs<<m_fGameTime<<endl;
	fs.close();
}
int CGameMainX::OutputHight()
{
	ifstream onfile;
	onfile.open("score1.txt");
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


