/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_X_H_
#define _LESSON_X_H_
//
#include <Windows.h>
#include "TankPlayer.h"
#include "Bullet.h"
#include "TankEnemy.h"
#include "Weapon.h"
#include <vector>
using namespace std;


/////////////////////////////////////////////////////////////////////////////////
//


// 游戏总管类。负责处理游戏主循环、游戏初始化、结束等工作
class	CGameMainX
{
private:
	int				m_iGameState;				// 游戏状态，0：结束或者等待开始；1：初始化；2：游戏进行中
	CSprite*		m_pTitle;//游戏标题
	CSprite*		m_pGameOver;//游戏结束图片
	CSound*			m_pBGM;//背景音乐文件
	CEffect*        m_pEffect;//特效
	CTankPlayer*	m_pTankPlayer;//我方坦克精灵
	int				m_iBulletNum;//子弹数量
	CTankEnemy*		m_pTankEnemy;//敌方坦克精灵
	vector<CWeapon*> m_vWeapon;
	float			m_fTankEnemyTime;//敌方坦克时间
	int				m_iTankEnemyNumber;//敌方坦克数量
	int				m_fGameTime;//游戏进行时间显示精灵
	int				m_fTime0;//初始时间显示
	CTextSprite*	m_pScore;//分数显示精灵
	CTextSprite*	m_pHight;//最高分显示精灵
	CTextSprite*	m_pScoreA;//分数A显示精灵
	CTextSprite*	m_pScoreB;//分数B显示精灵
	CTextSprite*	m_pTime;//时间显示函数
	int				m_iHight;//最高分
	int				count;//存档计数
public:
	CGameMainX();            //构造函数
	~CGameMainX();           //析构函数  

	// Get方法
	int			GetGameState()											{ return m_iGameState; }
	int			GetGameTime()											{return m_fGameTime;}
	int			GetTime0()												{return m_fTime0;}
	int			GetHight()												{return m_iHight;}
	float GetTankPlayerRotation() {return m_pTankPlayer->GetSpriteRotation();}
	float GetTankEnemyRotation() {return m_pTankEnemy->GetSpriteRotation();}
	// Set方法
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }
	void			SetGameTime(int time)							{m_fGameTime	=	time;}
	void			SetHight(int hight)								{m_iHight	=	hight;}
	// 游戏主循环等
	void			GameMainLoop( float	fDeltaTime );
	void			GameInit();
	void			GameRun( float fDeltaTime );
	void			GameEnd();
	void 			OnMouseMove( const float fMouseX, const float fMouseY );
	void 			OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
	void 			OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
	void 			OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
	void 			OnKeyUp( const int iKey );
	void 			OnSpriteColSprite( const char *szSrcName, const char *szTarName );
	void 			OnSpriteColWorldLimit( const char *szName, const int iColSide );
	void			AddBullet(float fPosX,float fPosY,int iOwner);//生成子弹
	void			LoadMap();//载入地图
	CWeapon*		FindWeaponByName(const char* szName);//根据名字查找到对象
	void			DeleteWeaponByName(const char* szName);//根据名字把精灵从容器中删除
	void			AddTankEnemy(float fDeltaTime);//不断产生敌方坦克
	void			InputToFile();//输出结果到文件
	int				OutputHight();//输出最高分到文件
};

/////////////////////////////////////////////////////////////////////////////////
// 
extern CGameMainX	g_GameMainX;


#endif // _LESSON_X_H_