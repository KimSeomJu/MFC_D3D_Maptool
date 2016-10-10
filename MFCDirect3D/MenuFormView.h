#pragma once
#include "afxcmn.h"
#include "DlgTerrain.h"
#include "DlgObject.h"
#include "Dlg_SkyBox.h"

// CMenuFormView 폼 뷰입니다.

class CMenuFormView : public CFormView
{
	DECLARE_DYNCREATE(CMenuFormView)

protected:
	CMenuFormView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CMenuFormView();

public:
	enum { IDD = IDD_MENUFORMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_ctrlTabTerrain;

	CDlgTerrain *m_pDlgTerrain;
	CDlgObject *m_pDlgObject;
	CDlg_SkyBox *m_pDlg_SkyBox;

	virtual void OnInitialUpdate();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};


