#pragma once


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
};
