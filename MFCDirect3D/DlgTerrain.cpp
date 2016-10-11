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
	, m_TerrainX(_T(""))
	, m_TerrainY(_T(""))
{

}

CDlgTerrain::~CDlgTerrain()
{
}

void CDlgTerrain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_TerrainX);
	DDX_Text(pDX, IDC_EDIT2, m_TerrainY);
}


BEGIN_MESSAGE_MAP(CDlgTerrain, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgTerrain::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CDlgTerrain::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTerrain::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgTerrain::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgTerrain::OnBnClickedRadio2)
	ON_EN_ERRSPACE(IDC_EDIT1, &CDlgTerrain::OnChangeEditOne)
END_MESSAGE_MAP()


// CDlgTerrain �޽��� ó�����Դϴ�.

//X
void CDlgTerrain::OnEnChangeEdit1()
{
	//�ǽð����� �ԷµǴ� ���ڰ��� ����
	UpdateData(TRUE);
}

//Y
void CDlgTerrain::OnEnChangeEdit2()
{
	//�ǽð����� �ԷµǴ� ���ڰ��� ����
	UpdateData(TRUE);
}

//X * Y �����ϱ� ��ư
void CDlgTerrain::OnBnClickedButton1()
{
	UpdateData(TRUE);
	//CString -> int 
	m_TrinX = _ttoi(m_TerrainX);
	m_TrinY = _ttoi(m_TerrainY);
	UpdateData(FALSE);

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


void CDlgTerrain::OnChangeEditOne()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
