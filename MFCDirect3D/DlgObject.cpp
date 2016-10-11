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
	ON_BN_CLICKED(IDC_RADIO1, &CDlgObject::OnBnClickedRadio1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CDlgObject::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// CDlgObject 메시지 처리기입니다.


void CDlgObject::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CDlgObject::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
