//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonClass.h"
#include "LessonX.h"
#include "LessonY.h"

///////////////////////////////////////////////////////////////////////////////////////////
//
// ���������
//
//////////////////////////////////////////////////////////////////////////////////////////
int g_iGameType = 0;
int PASCAL WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)
{

	// ��ʼ����Ϸ����
	if( !CSystem::InitGameEngine( hInstance, lpCmdLine ) )
		return 0;

	// To do : �ڴ�ʹ��API���Ĵ��ڱ���
	CSystem::SetWindowTitle("TankWar");

	// ������ѭ����������Ļͼ��ˢ�µȹ���
	while( CSystem::EngineMainLoop() )
	{
		// ��ȡ���ε���֮���ʱ�����ݸ���Ϸ�߼�����
		float	fTimeDelta	=	CSystem::GetTimeDelta();
        if(g_iGameType==1)
		// ִ����Ϸ��ѭ��
		{
			g_GameMainX.GameMainLoop( fTimeDelta );
		}
		else if(g_iGameType==2)
		// ִ����Ϸ��ѭ��
		{
			g_GameMainY.GameMainLoop( fTimeDelta );
		}
	};

	// �ر���Ϸ����
	CSystem::ShutdownGameEngine();
	return 0;
}

//==========================================================================
//
// ���沶׽����ƶ���Ϣ�󣬽����õ�������
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
void CSystem::OnMouseMove( const float fMouseX, const float fMouseY )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	if(g_iGameType==1)
	{g_GameMainX.OnMouseMove(fMouseX, fMouseY);}
	else if(g_iGameType==2)
		{g_GameMainY.OnMouseMove(fMouseX, fMouseY);}
}
//==========================================================================
//
// ���沶׽�������Ϣ�󣬽����õ�������
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
void CSystem::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	if(g_iGameType==1)
	{g_GameMainX.OnMouseClick(iMouseType, fMouseX, fMouseY);}
	else if(g_iGameType==2)
		{g_GameMainY.OnMouseClick(iMouseType, fMouseX, fMouseY);}
}
//==========================================================================
//
// ���沶׽��굯����Ϣ�󣬽����õ�������
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
void CSystem::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	if(g_iGameType==1)
	{g_GameMainX.OnMouseUp(iMouseType, fMouseX, fMouseY);}
	else if(g_iGameType==2)
		{g_GameMainY.OnMouseUp(iMouseType, fMouseX, fMouseY);}

}
//==========================================================================
//
// ���沶׽���̰�����Ϣ�󣬽����õ�������
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
//
void CSystem::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	if(g_iGameType==1)
	{g_GameMainX.OnKeyDown(iKey, bAltPress, bShiftPress, bCtrlPress);}
	else if(g_iGameType==2)
		{g_GameMainY.OnKeyDown(iKey, bAltPress, bShiftPress, bCtrlPress);}
}
//==========================================================================
//
// ���沶׽���̵�����Ϣ�󣬽����õ�������
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
//
void CSystem::OnKeyUp( const int iKey )
{
	if(g_iGameType==0)
	{
		if(iKey==KEY_2)
		{
			g_iGameType=1;
		}
		else if(iKey==KEY_1)
		{
			g_iGameType=2;
		}
	}
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	if(g_iGameType==1)
	{
	g_GameMainX.OnKeyUp(iKey);
	}
	else if(g_iGameType==2)
	{
	g_GameMainY.OnKeyUp(iKey);
	}
}

//===========================================================================
//
// ���沶׽�������뾫����ײ֮�󣬵��ô˺���
// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��鷢�ͼ�������ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
//
void CSystem::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	if(g_iGameType==1)
	{g_GameMainX.OnSpriteColSprite(szSrcName, szTarName);}
	else if(g_iGameType==2)
	{g_GameMainY.OnSpriteColSprite(szSrcName, szTarName);}
}

//===========================================================================
//
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��������߽�����
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
//
void CSystem::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	if(g_iGameType==1)
	{g_GameMainX.OnSpriteColWorldLimit(szName, iColSide);}
	else if(g_iGameType==2)
	{g_GameMainY.OnSpriteColWorldLimit(szName, iColSide);}
}

