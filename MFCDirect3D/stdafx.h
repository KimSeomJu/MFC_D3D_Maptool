
// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������ 
// ��� �ִ� ���� �����Դϴ�.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
#endif

#include "targetver.h"
using namespace std;

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // �Ϻ� CString �����ڴ� ��������� ����˴ϴ�.

// MFC�� ���� �κа� ���� ������ ��� �޽����� ���� ����⸦ �����մϴ�.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC �ٽ� �� ǥ�� ���� ����Դϴ�.
#include <afxext.h>         // MFC Ȯ���Դϴ�.

// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <string>

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dx9.lib" )

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 ���� ��Ʈ�ѿ� ���� MFC �����Դϴ�.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows ���� ��Ʈ�ѿ� ���� MFC �����Դϴ�.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC�� ���� �� ��Ʈ�� ���� ����


#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

//
// ��ũ�� ���
//
#define CLIENTSIZE_X	1600				//�ʱ� ������ ���� ũ��
#define CLIENTSIZE_Y	900					//�ʱ� ������ ���� ũ��
#define WINSIZE_X		(CLIENTSIZE_X-336)	//�ʱ� ������ ���� ũ��
#define WINSIZE_Y		(CLIENTSIZE_Y-109)	//�ʱ� ������ ���� ũ��
#define WINPOS_X		0					//�ʱ� ������ ���� ��ġ X
#define WINPOS_Y		0					//�ʱ� ������ ���� ��ġ Y
#define WIN_CLASS		"Windows Exam"		//������ Ŭ���� �̸�
#define WIN_TITLE		"Windows Exam"		//������ Ÿ��Ʋ �̸�
#define WIN_STYLE		WS_CAPTION | WS_SYSMENU | WS_BORDER	//������ ����
//#define WIN_STYLE	WS_OVERLAPPEDWINDOW	//������ ����


#define ONE_RAD 0.017453f				//����1 ��

#define SAFE_DELETE(p)		{ if(p){ delete (p); (p) = NULL; } }
#define SAFE_DELETE_ARR(p)	{ if(p){ delete[] (p); (p) = NULL; } }
#define SAFE_RELEASE(p)		{ if(p){ (p)->Release(); (p) = NULL; } }

//
// ���� ����
//
extern HWND			g_hWnd;		//������ �ڵ� ( �ڽ��� ���α׷����� �����ִ� ������ ��ȣ )
extern HINSTANCE	g_hInst;	//���α׷� �ν��Ͻ� �ڵ� ( OS �� �ο��� ���α׷� ��ȣ )

//===== MFC -> DirectX ��������=======================================================

enum ToolTab
{
	TERRAIN,
	OBJECT,
	SKYBOX
};

extern ToolTab g_ToolTab;
//=================================================
//===================terrain tab===================
//=================================================

//�ͷ��� x,y��
extern int g_terrainX;
extern int g_terrainY;

enum CB_TerrainLandlist
{
	LandUnselect,
	LandGrass,
	LandLand,
	LandStone
};
extern CB_TerrainLandlist g_CB_Landlist;			//�ͷ����޺��ڽ�

enum CB_TerrainLandBrush
{
	BrushUnselect,
	BrushSample1,
	BrushSample2,
	BrushSample3
};
extern CB_TerrainLandBrush g_CB_LandBrushList;		//�귯���޺��ڽ�

extern CString g_heightMapPath;						//���̸� ���ϰ��
extern bool g_isCkActBtnHeightMap;					//isClickedAcceptButton

extern int g_terrainBrushSize;
extern int g_terrainBrushPower;

enum RB_TerrainBrushKind
{
	upbrush,
	downbrush
};
extern RB_TerrainBrushKind g_RB_TerrainBrushKind;

//=================================================
//===================object tab===================
//=================================================

enum TREE_Object
{
	objectUnselect,
	trees,
	rocks,
	builds
};
extern TREE_Object g_TREE_Object;

enum TREE_ObjectTree
{
	treeUnselect,
	tree1,
	tree2,
	tree3
};
extern TREE_ObjectTree g_TREE_ObjectTree;

enum TREE_ObjectRock
{
	rockUnselect,
	rock1,
	rock2,
	rock3
};
extern TREE_ObjectRock g_TREE_ObjectRock;

enum TREE_ObjectBuild
{
	buildUnselect,
	build1,
	build2,
	build3
};
extern TREE_ObjectBuild g_TREE_ObjectBuild;

enum RB_ObjectBrushKind
{
	manybrush,
	onebrush
};
extern RB_ObjectBrushKind g_RB_ObjectBrushKind;
//=================================================
//===================skybox tab====================
//=================================================

extern CString g_skyBoxName;						//ť��� ���ϰ��
extern bool g_isCkActBtnSkyBox;						//isClickedAcceptButton

extern int g_objectBrushSize;

extern int g_objectCtrlScale;
extern int g_objectCtrlRX;
extern int g_objectCtrlRY;
extern int g_objectCtrlRZ;


//===================================================================================
#include <vector>
#include <map>

//
// �Ŵ���
//
#include "MyUtil.h"

using namespace MyUtil;
using namespace std;


#include "cTimeMgr.h"
#include "cKeyMgr.h"
#include "cLogMgr.h"
#include "cDXFontManager.h"
#include "cGizmoManager.h"
#include "cPhysicManager.h"
#include "cSpriteManager.h"
#include "cScene_Mgr.h"
#include "cResourceMgr_Texture.h"
#include "cResourceMgr_ShaderFX.h"
#include "cResourceMgr_XStaticMesh.h"
#include "cResourceMgr_XSkinnedMesh.h"
