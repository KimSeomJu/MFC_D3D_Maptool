#pragma once


// CDlgTerrain ��ȭ �����Դϴ�.

class CDlgTerrain : public CDialog
{
	DECLARE_DYNAMIC(CDlgTerrain)

public:
	CDlgTerrain(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgTerrain();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_TERRAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};
