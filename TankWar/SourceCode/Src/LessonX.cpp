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
//数据存储结构体
#define N 100
struct Score
{
	int num;
	int fen;
};
Score course[N];

//地图
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
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。

//==============================================================================
//
// 构造函数
CGameMainX::CGameMainX()
{
	m_iGameState			=	0;
	count=0;
	m_pTitle= new CSprite("Title");
	m_pGameOver = new CSprite("gameover");
	//m_pScoreTitle= new CSprite("scoretitle");//分数标题精灵
	//m_pHightTitle=new CSprite("highttitle");//最高分标题精灵
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
	//获取当前时间
	
}
//==============================================================================
//
// 析构函数
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
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态. 
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void CGameMainX::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// 初始化游戏，清空上一局相关数据
	case 1:
		{
			GameInit();
			SetGameState(2); // 初始化之后，将游戏状态设置为进行中
		}
		break;

		// 游戏进行中，处理各种游戏逻辑
	case 2:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;

		// 游戏结束/等待按空格键开始
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
void CGameMainX::GameInit()
{
	m_pTitle->SetSpriteVisible(false);
	//m_pScoreTitle->SetSpriteVisible(false);//分数标题精灵
	//m_pHightTitle->SetSpriteVisible(false);//最高分标题精灵
	

	
	m_pTankPlayer=new CTankPlayer("myPlayer");//新建一个名字是myPlayer的我方坦克对象
    m_pTankPlayer->CloneSprite("player");//我方坦克克隆在funcode模版库中的名字为player的坦克，表示新建的坦克对象有现在精灵的所有属性
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
// 每局游戏进行中
void CGameMainX::GameRun( float fDeltaTime )
{
	//显示当前时间
		time_t now_time1;
		now_time1 = time(NULL);
		m_fGameTime=now_time1-m_fTime0;


	
	//m_pScore->SetTextValue(m_fGameTime);
	//m_pHight->SetTextValue(m_iHight);

	m_pTime->SetTextValue(60-m_fGameTime); 
	if(m_fGameTime>=60) GameEnd();
	static int TankPlayerNumber=0;//表示我方坦克死亡次数
	static int TankEnemyNumber=0;//表示敌方坦克死亡次数
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
// 本局游戏结束
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
// 鼠标移动
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void CGameMainX::OnMouseMove( const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// 鼠标点击
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void CGameMainX::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// 鼠标弹起
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void CGameMainX::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// 键盘按下
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
void CGameMainX::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
	

	if(m_iGameState==2)
	{
		m_pTankPlayer->OnMove(iKey,true);
		if(iKey == KEY_J)//判断按下的是否为J键
		{
			m_pTankPlayer->OnFire();
		}
	}
	if(m_iGameState==2)
	{
		m_pTankEnemy->OnMove(iKey,true);
		if(iKey == KEY_SPACE)//判断按下的是否为空格键
		{
			m_pTankEnemy->OnFire();
		}
	}

}
//==========================================================================
//
// 键盘弹起
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
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
// 精灵与精灵碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
void CGameMainX::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	CWeapon* tarSprite = FindWeaponByName(szTarName);
	if(strstr(szSrcName,"bullet")!=NULL)//发送碰撞为子弹
	{
		CBullet* tmpBullet=(CBullet*)FindWeaponByName(szSrcName);
		tmpBullet->OnSpriteColSprite(tarSprite);

	}
	else if(strcmp(szSrcName,"myPlayer")==0)//发送碰撞为我方坦克
	{
		m_pTankPlayer->OnSpriteColSprite(tarSprite);
	}
	else if(strcmp(szSrcName,"enemy")==0)//发生碰撞为敌方坦克
	{
		m_pTankEnemy->OnSpriteColSprite(tarSprite);
	}
	
}
//===========================================================================
//
// 精灵与世界边界碰撞
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
void CGameMainX::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	if(strstr(szName,"myPlayer")!=NULL)//判断碰到世界边界的坦克是否为我方坦克
	{
		m_pTankPlayer->SetSpriteLinearVelocity(0,0);
	}
	if(strstr(szName,"enemy")!=NULL)//判断碰到世界边界的坦克是否为敌方坦克
	{
		m_pTankEnemy->SetSpriteLinearVelocity(0,0);
	}
	//将碰到世界边界的子弹消除
	else if(strstr(szName,"bullet")!=NULL)
	{
			CWeapon* pBullet = FindWeaponByName(szName);
			pBullet->SetHp(0);

	}
}

void CGameMainX::AddBullet(float fPosX,float fPosY, int iOwner)
{
	char* szName=CSystem::MakeSpriteName("bullet",m_iBulletNum);//创建子弹名字
	CBullet* pBullet = new CBullet(szName);
	pBullet->CloneSprite("bullet");
    pBullet->SetSpriteWorldLimit(WORLD_LIMIT_NULL,-32,-27.4,32,27.4);//设置边界
	pBullet->SetSpritePosition(fPosX,fPosY);
	pBullet->SetSpriteCollisionSend(true);
	pBullet->OnMove(iOwner);
	m_iBulletNum++;//子弹数量加一
	if(iOwner==1)
	{
		pBullet->SetOwner(1);//1表示我方坦克发射的子弹
	}
	else
	{
		pBullet->SetOwner(0);//0表示敌方坦克发射的子弹
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
				szName=CSystem::MakeSpriteName("wall",j+i*13+i);//重新起名
				CWeapon* pWall = new CWeapon(szName);//新建对象
				pWall->CloneSprite("wall");//克隆墙块
				pWall->SetSpriteCollisionActive(0,1);//设置为接受碰撞
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


