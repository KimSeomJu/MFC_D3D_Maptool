
// MFCDirect3D.h : MFCDirect3D ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFCDirect3DApp:
// �� Ŭ������ ������ ���ؼ��� MFCDirect3D.cpp�� �����Ͻʽÿ�.
//

class CMFCDirect3DApp : public CWinAppEx
{
public:
	CMFCDirect3DApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnIdle(LONG lCount);
};

extern CMFCDirect3DApp theApp;
