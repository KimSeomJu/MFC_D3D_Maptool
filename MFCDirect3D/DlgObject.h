#pragma once


// CDlgObject ��ȭ �����Դϴ�.

class CDlgObject : public CDialog
{
	DECLARE_DYNAMIC(CDlgObject)

public:
	CDlgObject(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgObject();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_OBJECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
};
