
// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이 
// 들어 있는 포함 파일입니다.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#endif

#include "targetver.h"
using namespace std;

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 일부 CString 생성자는 명시적으로 선언됩니다.

// MFC의 공통 부분과 무시 가능한 경고 메시지에 대한 숨기기를 해제합니다.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include <afxext.h>         // MFC 확장입니다.

// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
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
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows 공용 컨트롤에 대한 MFC 지원입니다.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC의 리본 및 컨트롤 막대 지원


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
// 매크로 상수
//
#define CLIENTSIZE_X	1600				//초기 윈도우 가로 크기
#define CLIENTSIZE_Y	900					//초기 윈도우 세로 크기
#define WINSIZE_X		(CLIENTSIZE_X-336)	//초기 윈도우 가로 크기
#define WINSIZE_Y		(CLIENTSIZE_Y-109)	//초기 윈도우 세로 크기
#define WINPOS_X		0					//초기 윈도우 시작 위치 X
#define WINPOS_Y		0					//초기 윈도우 시작 위치 Y
#define WIN_CLASS		"Windows Exam"		//윈도우 클레스 이름
#define WIN_TITLE		"Windows Exam"		//윈도우 타이틀 이름
#define WIN_STYLE		WS_CAPTION | WS_SYSMENU | WS_BORDER	//윈도우 형태
//#define WIN_STYLE	WS_OVERLAPPEDWINDOW	//윈도우 형태


#define ONE_RAD 0.017453f				//라디안1 동

#define SAFE_DELETE(p)		{ if(p){ delete (p); (p) = NULL; } }
#define SAFE_DELETE_ARR(p)	{ if(p){ delete[] (p); (p) = NULL; } }
#define SAFE_RELEASE(p)		{ if(p){ (p)->Release(); (p) = NULL; } }

//
// 전역 변수
//
extern HWND			g_hWnd;		//윈도우 핸들 ( 자신의 프로그램에서 돌고있는 윈도우 번호 )
extern HINSTANCE	g_hInst;	//프로그램 인스턴스 핸들 ( OS 가 부여한 프로그램 번호 )

//===== MFC -> DirectX 전역변수=======================================================

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

//터레인 x,y값
extern int g_terrainX;
extern int g_terrainY;

enum CB_TerrainLandlist
{
	LandUnselect,
	LandGrass,
	LandLand,
	LandStone
};
extern CB_TerrainLandlist g_CB_Landlist;			//터레인콤보박스

enum CB_TerrainLandBrush
{
	BrushUnselect,
	BrushSample1,
	BrushSample2,
	BrushSample3
};
extern CB_TerrainLandBrush g_CB_LandBrushList;		//브러시콤보박스

extern CString g_heightMapPath;						//높이맵 파일경로
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

extern CString g_skyBoxName;						//큐브맵 파일경로
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
// 매니져
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
