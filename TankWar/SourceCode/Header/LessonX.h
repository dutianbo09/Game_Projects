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


// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	CGameMainX
{
private:
	int				m_iGameState;				// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2����Ϸ������
	CSprite*		m_pTitle;//��Ϸ����
	CSprite*		m_pGameOver;//��Ϸ����ͼƬ
	CSound*			m_pBGM;//���������ļ�
	CEffect*        m_pEffect;//��Ч
	CTankPlayer*	m_pTankPlayer;//�ҷ�̹�˾���
	int				m_iBulletNum;//�ӵ�����
	CTankEnemy*		m_pTankEnemy;//�з�̹�˾���
	vector<CWeapon*> m_vWeapon;
	float			m_fTankEnemyTime;//�з�̹��ʱ��
	int				m_iTankEnemyNumber;//�з�̹������
	int				m_fGameTime;//��Ϸ����ʱ����ʾ����
	int				m_fTime0;//��ʼʱ����ʾ
	CTextSprite*	m_pScore;//������ʾ����
	CTextSprite*	m_pHight;//��߷���ʾ����
	CTextSprite*	m_pScoreA;//����A��ʾ����
	CTextSprite*	m_pScoreB;//����B��ʾ����
	CTextSprite*	m_pTime;//ʱ����ʾ����
	int				m_iHight;//��߷�
	int				count;//�浵����
public:
	CGameMainX();            //���캯��
	~CGameMainX();           //��������  

	// Get����
	int			GetGameState()											{ return m_iGameState; }
	int			GetGameTime()											{return m_fGameTime;}
	int			GetTime0()												{return m_fTime0;}
	int			GetHight()												{return m_iHight;}
	float GetTankPlayerRotation() {return m_pTankPlayer->GetSpriteRotation();}
	float GetTankEnemyRotation() {return m_pTankEnemy->GetSpriteRotation();}
	// Set����
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }
	void			SetGameTime(int time)							{m_fGameTime	=	time;}
	void			SetHight(int hight)								{m_iHight	=	hight;}
	// ��Ϸ��ѭ����
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
	void			AddBullet(float fPosX,float fPosY,int iOwner);//�����ӵ�
	void			LoadMap();//�����ͼ
	CWeapon*		FindWeaponByName(const char* szName);//�������ֲ��ҵ�����
	void			DeleteWeaponByName(const char* szName);//�������ְѾ����������ɾ��
	void			AddTankEnemy(float fDeltaTime);//���ϲ����з�̹��
	void			InputToFile();//���������ļ�
	int				OutputHight();//�����߷ֵ��ļ�
};

/////////////////////////////////////////////////////////////////////////////////
// 
extern CGameMainX	g_GameMainX;


#endif // _LESSON_X_H_