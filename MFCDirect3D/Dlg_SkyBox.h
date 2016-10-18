#pragma once
#include "afxwin.h"


// CDlg_SkyBox 대화 상자입니다.

class CDlg_SkyBox : public CDialog
{
	DECLARE_DYNAMIC(CDlg_SkyBox)

public:
	CDlg_SkyBox(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlg_SkyBox();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_SKYBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();



private:

public:
	CString m_EditOne;
	afx_msg void OnChangeEditOne();
	CButton m_AcceptButton;
	afx_msg void OnButtClean(NMHDR *pNMHDR, LRESULT *pResult);
};
