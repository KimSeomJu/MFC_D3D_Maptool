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


// CDlgTerrain 메시지 처리기입니다.

//X
void CDlgTerrain::OnEnChangeEdit1()
{
	//실시간으로 입력되는 숫자값을 갱신
	UpdateData(TRUE);
}

//Y
void CDlgTerrain::OnEnChangeEdit2()
{
	//실시간으로 입력되는 숫자값을 갱신
	UpdateData(TRUE);
}

//X * Y 적용하기 버튼
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//Down Brush
void CDlgTerrain::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CDlgTerrain::OnChangeEditOne()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
