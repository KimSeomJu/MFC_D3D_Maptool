// DlgTerrain.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "DlgTerrain.h"
#include "afxdialogex.h"


// CDlgTerrain 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgTerrain, CDialog)

CDlgTerrain::CDlgTerrain(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTerrain::IDD, pParent)
{

}

CDlgTerrain::~CDlgTerrain()
{
}

void CDlgTerrain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTerrain, CDialog)
END_MESSAGE_MAP()


// CDlgTerrain 메시지 처리기입니다.
