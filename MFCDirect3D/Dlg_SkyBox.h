#pragma once
#include "afxwin.h"


// CDlg_SkyBox ��ȭ �����Դϴ�.

class CDlg_SkyBox : public CDialog
{
	DECLARE_DYNAMIC(CDlg_SkyBox)

public:
	CDlg_SkyBox(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg_SkyBox();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_SKYBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	
	
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
