
// MFCDirect3DView.h : CMFCDirect3DView 클래스의 인터페이스
//

#pragma once
//다이렉트 메인프레임
#include "cMainGame.h"


class CMFCDirect3DView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCDirect3DView();
	DECLARE_DYNCREATE(CMFCDirect3DView)

// 특성입니다.
public:
	CMFCDirect3DDoc* GetDocument() const;
	cMainGame m_MainGame;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMFCDirect3DView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // MFCDirect3DView.cpp의 디버그 버전
inline CMFCDirect3DDoc* CMFCDirect3DView::GetDocument() const
   { return reinterpret_cast<CMFCDirect3DDoc*>(m_pDocument); }
#endif

