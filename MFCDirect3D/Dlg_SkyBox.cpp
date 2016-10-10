// Dlg_SkyBox.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "Dlg_SkyBox.h"
#include "afxdialogex.h"


// CDlg_SkyBox 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_SkyBox, CDialog)

CDlg_SkyBox::CDlg_SkyBox(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_SkyBox::IDD, pParent)
{

}

CDlg_SkyBox::~CDlg_SkyBox()
{
}

void CDlg_SkyBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg_SkyBox, CDialog)
END_MESSAGE_MAP()


// CDlg_SkyBox 메시지 처리기입니다.
