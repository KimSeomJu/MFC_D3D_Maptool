// DlgObject.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "DlgObject.h"
#include "afxdialogex.h"


// CDlgObject ��ȭ �����Դϴ�.

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
END_MESSAGE_MAP()


// CDlgObject �޽��� ó�����Դϴ�.


void CDlgObject::OnBnClickedRadio1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
