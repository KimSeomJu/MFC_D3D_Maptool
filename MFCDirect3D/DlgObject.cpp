// DlgObject.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "DlgObject.h"
#include "afxdialogex.h"


// CDlgObject 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgObject, CDialog)

CDlgObject::CDlgObject(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgObject::IDD, pParent)
{

}

CDlgObject::~CDlgObject()
{
}

void CDlgObject::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgObject, CDialog)
END_MESSAGE_MAP()


// CDlgObject 메시지 처리기입니다.
