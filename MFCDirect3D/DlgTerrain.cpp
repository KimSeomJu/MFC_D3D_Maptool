// DlgTerrain.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "DlgTerrain.h"
#include "afxdialogex.h"


// CDlgTerrain ��ȭ �����Դϴ�.

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
	ON_EN_CHANGE(IDC_EDIT1, &CDlgTerrain::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CDlgTerrain::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTerrain::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgTerrain::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgTerrain::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CDlgTerrain �޽��� ó�����Դϴ�.


void CDlgTerrain::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}


void CDlgTerrain::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}

//X * Y �����ϱ�
void CDlgTerrain::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}


//Up Brush
void CDlgTerrain::OnBnClickedRadio1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

//Down Brush
void CDlgTerrain::OnBnClickedRadio2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
