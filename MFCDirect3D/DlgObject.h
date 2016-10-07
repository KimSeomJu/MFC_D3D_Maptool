#pragma once


// CDlgObject 대화 상자입니다.

class CDlgObject : public CDialog
{
	DECLARE_DYNAMIC(CDlgObject)

public:
	CDlgObject(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgObject();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_OBJECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
};
