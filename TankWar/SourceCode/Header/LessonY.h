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


// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	CGameMainY
{
private:
	int				m_iGameState;// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2����Ϸ������
	CSprite*		m_pTitle;//����ͼƬ����
	CSprite*		m_pGameOver;//����ͼƬ����
	CSprite*		m_pRankBackground;//���а���
	CSound*			m_pBGM;//�������־���
	CSound*         m_pBomb;//��ը��
	CSound*         m_pBiu;//������
	CTankPlayerY*	m_pTankPlayer;//�ҷ�̹�˾���
    CEffect*        m_pEffect;//�ӵ�����Ŀ�����Ч
	int				m_iBulletNum;//�ӵ�����
	vector<CWeaponY*> m_vWeapon;
	float			m_fTankEnemyTime;//�ط�̹��ʱ��
	int				m_iTankEnemyNumber;//�ط�̹������
	int				m_fGameTime;//��Ϸ����ʱ����ʾ����
	int				m_fTime0;//��ʼʱ����ʾ
	CTextSprite*	m_pScore;//������ʾ����
	CTextSprite*	m_pHight;//��߷���ʾ����
	CTextSprite*	m_pTime;//ʱ����ʾ����
	CTextSprite*	m_pRank;//������ʾ����
	int				m_iHight;//��߷�
	CWeaponY*       m_pAim_nor;//��ʾ�ҷ���Ӫ
	int				m_iEnemyDeath;//�з���������
	int				count;//�浵����
public:
	CGameMainY();            //���캯��
	~CGameMainY();           //��������  

	// Get����
	int				GetGameState()											{ return m_iGameState; }
	// Set����
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }
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
	void			AddBullet(int iDir,float fPosX,float fPosY, int iOwner);//�����ӵ�
	void			LoadMap();//�����ͼ
	CWeaponY*		FindWeaponByName(const char* szName);//�������ֲ��ҵ�����
	void			DeleteWeaponByName(const char* szName);//�������ְѾ����������ɾ��
	void			AddTankEnemy(float fDeltaTime);//���ϲ����з�̹��
	void			InputToFile();//��������Ϸ�÷�д���ļ�
	int				OutputHight();//����ʷ��߷ִ��ļ����ҳ�����ʾ
};

/////////////////////////////////////////////////////////////////////////////////
// 
extern CGameMainY	g_GameMainY;


#endif // _LESSON_X_H_