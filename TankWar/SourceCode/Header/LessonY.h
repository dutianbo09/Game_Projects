/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_Y_H_
#define _LESSON_Y_H_
//
#include <Windows.h>
#include "TankPlayerY.h"
#include "BulletY.h"
#include "TankEnemyY.h"
#include "WeaponY.h"
#include <vector>
using namespace std;


/////////////////////////////////////////////////////////////////////////////////
//


// 游戏总管类。负责处理游戏主循环、游戏初始化、结束等工作
class	CGameMainY
{
private:
	int				m_iGameState;// 游戏状态，0：结束或者等待开始；1：初始化；2：游戏进行中
	CSprite*		m_pTitle;//标题图片精灵
	CSprite*		m_pGameOver;//结束图片精灵
	CSprite*		m_pRankBackground;//排行榜精灵
	CSound*			m_pBGM;//背景音乐精灵
	CSound*         m_pBomb;//爆炸音
	CSound*         m_pBiu;//开火音
	CTankPlayerY*	m_pTankPlayer;//我方坦克精灵
    CEffect*        m_pEffect;//子弹击中目标的特效
	int				m_iBulletNum;//子弹数量
	vector<CWeaponY*> m_vWeapon;
	float			m_fTankEnemyTime;//地方坦克时间
	int				m_iTankEnemyNumber;//地方坦克数量
	int				m_fGameTime;//游戏进行时间显示精灵
	int				m_fTime0;//初始时间显示
	CTextSprite*	m_pScore;//分数显示精灵
	CTextSprite*	m_pHight;//最高分显示精灵
	CTextSprite*	m_pTime;//时间显示精灵
	CTextSprite*	m_pRank;//排名显示精灵
	int				m_iHight;//最高分
	CWeaponY*       m_pAim_nor;//表示我方军营
	int				m_iEnemyDeath;//敌方死亡次数
	int				count;//存档计数
public:
	CGameMainY();            //构造函数
	~CGameMainY();           //析构函数  

	// Get方法
	int				GetGameState()											{ return m_iGameState; }
	// Set方法
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }
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
	void			AddBullet(int iDir,float fPosX,float fPosY, int iOwner);//增加子弹
	void			LoadMap();//载入地图
	CWeaponY*		FindWeaponByName(const char* szName);//根据名字查找到对象
	void			DeleteWeaponByName(const char* szName);//根据名字把精灵从容器中删除
	void			AddTankEnemy(float fDeltaTime);//不断产生敌方坦克
	void			InputToFile();//将本次游戏得分写入文件
	int				OutputHight();//将历史最高分从文件中找出并显示
};

/////////////////////////////////////////////////////////////////////////////////
// 
extern CGameMainY	g_GameMainY;


#endif // _LESSON_X_H_