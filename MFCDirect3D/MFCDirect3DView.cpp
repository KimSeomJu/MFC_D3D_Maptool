
// MFCDirect3DView.cpp : CMFCDirect3DView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CMFCDirect3DView 생성/소멸

CMFCDirect3DView::CMFCDirect3DView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	
}

CMFCDirect3DView::~CMFCDirect3DView()
{
	m_MainGame.Release();
}

BOOL CMFCDirect3DView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCDirect3DView 그리기

void CMFCDirect3DView::OnDraw(CDC* /*pDC*/)
{
	CMFCDirect3DDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
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


// CMFCDirect3DView 진단

#ifdef _DEBUG
void CMFCDirect3DView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDirect3DView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDirect3DDoc* CMFCDirect3DView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDirect3DDoc)));
	return (CMFCDirect3DDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDirect3DView 메시지 처리기


// Direct 환경 초기화
void CMFCDirect3DView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	CRect rc;

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	g_hWnd = this->GetSafeHwnd();
	
	//this->GetClientRect(&rc);
	m_MainGame.Init(this->m_hWnd);
}

// View 클래스 속성들어가서 메세지 추가
// 메세지 함수를 아래처럼 수정해야 배경을 그려주고 지워주는걸 막을 수 있다.
BOOL CMFCDirect3DView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return FALSE;
	//return CView::OnEraseBkgnd(pDC);
}
