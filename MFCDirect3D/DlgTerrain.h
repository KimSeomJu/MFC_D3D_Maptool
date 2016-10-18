#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDlgTerrain 대화 상자입니다.

class cTerrainC;

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




private:
	cTerrainC* _cTerrainC;

public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	CString m_TerrainX;
	afx_msg void OnChangeEditOne();
	CString m_TerrainY;

//	CComboBox m_CB_landPallet;
	afx_msg void OnCbnSelchangeCombo1();

	CString m_CBS_landList;

	virtual BOOL OnInitDialog();
	CComboBox m_CB_landList;
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox m_CB_landBrush;
	CString m_CBS_landBrush;
	CString m_S_heightMapPath;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CComboBox m_CB_HeightBrush;
	CString m_CBS_HeightBrush;

	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_SC_BrushSize;
	CString m_BrushSize;
//	afx_msg void OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit4();

	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_SC_BrushPower;
	CString m_BrushPower;
	afx_msg void OnEnChangeEdit5();
	CScrollBar m_SB_TerrainScroll;
//	afx_msg void OnHScroll(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
//	int m_RB_Upbrush;
	afx_msg void OnBnClickedRadio1();
	int m_RB_Brush;

	afx_msg void SetRadioStatus(UINT value);
};
