#pragma once
#include "afxcmn.h"


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

	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	CTreeCtrl m_ObjectTreeCtrl;
	virtual BOOL OnInitDialog();
	int m_RB_objectBrush;
	afx_msg void SetRadioStatus(UINT value);


	CSliderCtrl m_objectBrushSize;
	CString m_S_objectBrushSize;
	afx_msg void OnNMCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_S_Scale;
	CString m_S_RotationX;
	CString m_S_RotationY;
	CString m_S_RotationZ;
	CSliderCtrl m_SC_Scale;
	CSliderCtrl m_SC_RotationX;
	CSliderCtrl m_SC_RotationY;
	CSliderCtrl m_SC_RotationZ;
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult);
};
