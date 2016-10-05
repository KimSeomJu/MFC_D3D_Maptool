// MenuFormView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "MenuFormView.h"


// CMenuFormView

IMPLEMENT_DYNCREATE(CMenuFormView, CFormView)

// 탭에 등록할 다이얼로그 2개(지형과 오브젝트) 변수를 NULL로 초기화
CMenuFormView::CMenuFormView()
	: CFormView(CMenuFormView::IDD)
{
	m_pDlgTerrain = NULL;
	m_pDlgObject = NULL;
}

// 탭에 등록할 다이얼로그 2개(지형과 오브젝트) 변수 메모리 해제
CMenuFormView::~CMenuFormView()
{
	SAFE_DELETE(m_pDlgTerrain);
	SAFE_DELETE(m_pDlgObject);
}

void CMenuFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_ctrlTabTerrain);
}

BEGIN_MESSAGE_MAP(CMenuFormView, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMenuFormView::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CMenuFormView 진단입니다.

#ifdef _DEBUG
void CMenuFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMenuFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMenuFormView 메시지 처리기입니다.


void CMenuFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_ctrlTabTerrain.DeleteAllItems();
	m_ctrlTabTerrain.InsertItem(0, L"Terrain");
	m_ctrlTabTerrain.InsertItem(1, L"Object");
	
	CRect rect;

	m_pDlgTerrain = new CDlgTerrain;
	m_pDlgTerrain->Create(IDD_DLG_TERRAIN, &m_ctrlTabTerrain);
	m_pDlgTerrain->GetWindowRect(&rect);
	m_pDlgTerrain->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDlgTerrain->ShowWindow(SW_SHOW);

	m_pDlgObject = new CDlgObject;
	m_pDlgObject->Create(IDD_DLG_OBJECT, &m_ctrlTabTerrain);
	m_pDlgObject->GetWindowRect(&rect);
	m_pDlgObject->MoveWindow(5, 25, rect.Width(), rect.Height());
	m_pDlgObject->ShowWindow(SW_HIDE);

	UpdateData(FALSE);
}


void CMenuFormView::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int select = m_ctrlTabTerrain.GetCurSel();

	switch (select)
	{
	case 0:
		m_pDlgTerrain->ShowWindow(SW_SHOW);
		m_pDlgObject->ShowWindow(SW_HIDE);
	break;
	case 1:
		m_pDlgTerrain->ShowWindow(SW_HIDE);
		m_pDlgObject->ShowWindow(SW_SHOW);
	break;
	}
	*pResult = 0;
}
