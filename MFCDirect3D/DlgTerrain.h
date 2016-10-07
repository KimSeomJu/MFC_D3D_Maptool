#pragma once


// CDlgTerrain 대화 상자입니다.

class CDlgTerrain : public CDialog
{
	DECLARE_DYNAMIC(CDlgTerrain)

public:
	CDlgTerrain(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgTerrain();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_TERRAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};
