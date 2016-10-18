
// MFCDirect3DView.h : CMFCDirect3DView Ŭ������ �������̽�
//

#pragma once
//���̷�Ʈ ����������
#include "cMainGame.h"


class CMFCDirect3DView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFCDirect3DView();
	DECLARE_DYNCREATE(CMFCDirect3DView)

// Ư���Դϴ�.
public:
	CMFCDirect3DDoc* GetDocument() const;
	cMainGame m_MainGame;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CMFCDirect3DView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // MFCDirect3DView.cpp�� ����� ����
inline CMFCDirect3DDoc* CMFCDirect3DView::GetDocument() const
   { return reinterpret_cast<CMFCDirect3DDoc*>(m_pDocument); }
#endif

