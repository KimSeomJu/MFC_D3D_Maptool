
// MFCDirect3DView.cpp : CMFCDirect3DView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFCDirect3D.h"
#endif

#include "MFCDirect3DDoc.h"
#include "MFCDirect3DView.h"

HWND		g_hWnd;
HINSTANCE	g_hInst;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDirect3DView

IMPLEMENT_DYNCREATE(CMFCDirect3DView, CView)

BEGIN_MESSAGE_MAP(CMFCDirect3DView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMFCDirect3DView ����/�Ҹ�

CMFCDirect3DView::CMFCDirect3DView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	
}

CMFCDirect3DView::~CMFCDirect3DView()
{
	m_MainGame.Release();
}

BOOL CMFCDirect3DView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFCDirect3DView �׸���

void CMFCDirect3DView::OnDraw(CDC* /*pDC*/)
{
	CMFCDirect3DDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}

void CMFCDirect3DView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	//ClientToScreen(&point);
	//OnContextMenu(this, point);
}

void CMFCDirect3DView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCDirect3DView ����

#ifdef _DEBUG
void CMFCDirect3DView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDirect3DView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDirect3DDoc* CMFCDirect3DView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDirect3DDoc)));
	return (CMFCDirect3DDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDirect3DView �޽��� ó����


// Direct ȯ�� �ʱ�ȭ
void CMFCDirect3DView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	CRect rc;

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	g_hWnd = this->GetSafeHwnd();
	
	//this->GetClientRect(&rc);
	m_MainGame.Init(this->m_hWnd);
}

// View Ŭ���� �Ӽ����� �޼��� �߰�
// �޼��� �Լ��� �Ʒ�ó�� �����ؾ� ����� �׷��ְ� �����ִ°� ���� �� �ִ�.
BOOL CMFCDirect3DView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	return FALSE;
	//return CView::OnEraseBkgnd(pDC);
}
