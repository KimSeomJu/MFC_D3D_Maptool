// MenuFormView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "MenuFormView.h"


// CMenuFormView

IMPLEMENT_DYNCREATE(CMenuFormView, CFormView)

// �ǿ� ����� ���̾�α� 2��(������ ������Ʈ) ������ NULL�� �ʱ�ȭ
CMenuFormView::CMenuFormView()
	: CFormView(CMenuFormView::IDD)
{
	m_pDlgTerrain = NULL;
	m_pDlgObject = NULL;
}

// �ǿ� ����� ���̾�α� 2��(������ ������Ʈ) ���� �޸� ����
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


// CMenuFormView �����Դϴ�.

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


// CMenuFormView �޽��� ó�����Դϴ�.


void CMenuFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
