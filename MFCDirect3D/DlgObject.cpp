// DlgObject.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "DlgObject.h"
#include "afxdialogex.h"


// CDlgObject ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgObject, CDialog)

CDlgObject::CDlgObject(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgObject::IDD, pParent)
	, m_RB_objectBrush(0)
	, m_S_objectBrushSize(_T(""))
	, m_S_Scale(_T(""))
	, m_S_RotationX(_T(""))
	, m_S_RotationY(_T(""))
	, m_S_RotationZ(_T(""))
{

}

CDlgObject::~CDlgObject()
{
}

void CDlgObject::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_ObjectTreeCtrl);
	DDX_Radio(pDX, IDC_RADIO1, (int &)m_RB_objectBrush);
	DDX_Control(pDX, IDC_SLIDER5, m_objectBrushSize);
	DDX_Text(pDX, IDC_EDIT1, m_S_objectBrushSize);
	DDX_Text(pDX, IDC_EDIT2, m_S_Scale);
	DDX_Text(pDX, IDC_EDIT3, m_S_RotationX);
	DDX_Text(pDX, IDC_EDIT4, m_S_RotationY);
	DDX_Text(pDX, IDC_EDIT5, m_S_RotationZ);
	DDX_Control(pDX, IDC_SLIDER1, m_SC_Scale);
	DDX_Control(pDX, IDC_SLIDER2, m_SC_RotationX);
	DDX_Control(pDX, IDC_SLIDER3, m_SC_RotationY);
	DDX_Control(pDX, IDC_SLIDER4, m_SC_RotationZ);
}


BEGIN_MESSAGE_MAP(CDlgObject, CDialog)
	
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CDlgObject::OnTvnSelchangedTree1)

	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO1, IDC_RADIO2, SetRadioStatus)

	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER5, &CDlgObject::OnNMCustomdrawSlider5)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CDlgObject::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CDlgObject::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &CDlgObject::OnNMCustomdrawSlider3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER4, &CDlgObject::OnNMCustomdrawSlider4)
END_MESSAGE_MAP()


// CDlgObject �޽��� ó�����Դϴ�.




//������Ʈ Ʈ�� ��ü�� �������� �� �߻��Ǵ� �̺�Ʈ
void CDlgObject::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	HTREEITEM hItemRoot;
	HTREEITEM hItemParent;
	HTREEITEM hItemCurrent;

	CString strRoot;
	CString strParent;
	CString strCurrent;
	CString strTxt;

	//���� ������ Ʈ���� ��, �θ�, ��Ʈ���� ��ġ�� ����
	hItemCurrent = pNMTreeView->itemNew.hItem;
	hItemParent = this->m_ObjectTreeCtrl.GetParentItem(hItemCurrent);
	hItemRoot = this->m_ObjectTreeCtrl.GetParentItem(hItemParent);

	//������ ��ġ�� �ؽ�Ʈ �����͸� ������ ����
	strRoot = m_ObjectTreeCtrl.GetItemText(hItemRoot);
	strParent = m_ObjectTreeCtrl.GetItemText(hItemParent);
	strCurrent = m_ObjectTreeCtrl.GetItemText(hItemCurrent);


	if (strParent == L"TREES")
	{
		g_TREE_Object = trees;
		
		if (strCurrent == L"Tree1")
		{
			g_TREE_ObjectTree = tree1;
			AfxMessageBox(L"selected tree1");
		}
		else if (strCurrent == L"Tree2")
		{
			g_TREE_ObjectTree = tree2;
			AfxMessageBox(L"selected tree2");
		}
		else if (strCurrent == L"Tree3")
		{
			g_TREE_ObjectTree = tree3;
			AfxMessageBox(L"selected tree3");
		}
	}
	else if (strParent == L"ROCKS")
	{
		g_TREE_Object = rocks;

		if (strCurrent == L"Rock1")
			g_TREE_ObjectRock = rock1;
		else if (strCurrent == L"Rock2")
			g_TREE_ObjectRock = rock2;
		else if (strCurrent == L"Rock3")
			g_TREE_ObjectRock = rock3;
	}
	else if (strParent == L"BUILDS")
	{
		g_TREE_Object = builds;

		if (strCurrent == L"Build1")
			g_TREE_ObjectBuild = build1;
		else if (strCurrent == L"Build2")
			g_TREE_ObjectBuild = build2;
		else if (strCurrent == L"Build3")
			g_TREE_ObjectBuild = build3;
	}

	//strTxt.Append(_T("/") + strRoot);
	//strTxt.Append(_T("/") + strParent);
	//strTxt.Append(_T("/") + strCurrent);
	
	*pResult = 0;
}


BOOL CDlgObject::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	HTREEITEM  rObject;

	HTREEITEM  rKindTree;
	HTREEITEM  rKindRock;
	HTREEITEM  rKindBuild;

	HTREEITEM  rTree1;
	HTREEITEM  rTree2;
	HTREEITEM  rTree3;

	HTREEITEM  rRock1;
	HTREEITEM  rRock2;
	HTREEITEM  rRock3;

	HTREEITEM  rBuild1;
	HTREEITEM  rBuild2;
	HTREEITEM  rBuild3;

	rObject = m_ObjectTreeCtrl.InsertItem(L"OBJECT",  TVI_ROOT, TVI_LAST);

	rKindTree = m_ObjectTreeCtrl.InsertItem(L"TREES",  rObject, TVI_LAST);
	rKindRock = m_ObjectTreeCtrl.InsertItem(L"ROCKS",  rObject, TVI_LAST);
	rKindBuild = m_ObjectTreeCtrl.InsertItem(L"BUILDS", rObject, TVI_LAST);

	rTree1 = m_ObjectTreeCtrl.InsertItem(L"Tree1", rKindTree, TVI_LAST);
	rTree2 = m_ObjectTreeCtrl.InsertItem(L"Tree2", rKindTree, TVI_LAST);
	rTree3 = m_ObjectTreeCtrl.InsertItem(L"Tree3", rKindTree, TVI_LAST);

	rRock1 = m_ObjectTreeCtrl.InsertItem(L"Rock1", rKindRock, TVI_LAST);
	rRock2 = m_ObjectTreeCtrl.InsertItem(L"Rock2", rKindRock, TVI_LAST);
	rRock3 = m_ObjectTreeCtrl.InsertItem(L"Rock3", rKindRock, TVI_LAST);

	rBuild1 = m_ObjectTreeCtrl.InsertItem(L"Build1", rKindBuild, TVI_LAST);
	rBuild1 = m_ObjectTreeCtrl.InsertItem(L"Build2", rKindBuild, TVI_LAST);
	rBuild1 = m_ObjectTreeCtrl.InsertItem(L"Build3", rKindBuild, TVI_LAST);


	//object brush size=======================================
	m_objectBrushSize.SetRange(0, 100);
	m_objectBrushSize.SetRangeMin(0);		//�ּҰ�
	m_objectBrushSize.SetRangeMax(100);		//�ִ밪
	m_objectBrushSize.SetPos(50);			//�ʱⰪ

	// �Ӽ��� Tick Marks�� Auto Ticks�� True�� �Ǿ� �־�� �Ѵ�.
	m_objectBrushSize.SetTicFreq(10);		//���ݰ���
	// Ű������ PgUp, PgDnŰ�� �����ų� ���콺�� �����̴��� ������ Ŭ���� ������ ũ�� 
	m_objectBrushSize.SetPageSize(10);
	
	g_objectBrushSize = m_objectBrushSize.GetPos();

	//object control Scale==================================
	m_SC_Scale.SetRange(0, 100);
	m_SC_Scale.SetRangeMin(0);		//�ּҰ�
	m_SC_Scale.SetRangeMax(100);		//�ִ밪
	m_SC_Scale.SetPos(50);			//�ʱⰪ

	// �Ӽ��� Tick Marks�� Auto Ticks�� True�� �Ǿ� �־�� �Ѵ�.
	m_SC_Scale.SetTicFreq(10);			//���ݰ���
	// Ű������ PgUp, PgDnŰ�� �����ų� ���콺�� �����̴��� ������ Ŭ���� ������ ũ�� 
	m_SC_Scale.SetPageSize(10);

	g_objectCtrlScale = m_SC_Scale.GetPos();

	//object control RX======================================
	m_SC_RotationX.SetRange(0, 359);
	m_SC_RotationX.SetRangeMin(0);		//�ּҰ�
	m_SC_RotationX.SetRangeMax(359);		//�ִ밪
	m_SC_RotationX.SetPos(0);			//�ʱⰪ

									// �Ӽ��� Tick Marks�� Auto Ticks�� True�� �Ǿ� �־�� �Ѵ�.
	m_SC_RotationX.SetTicFreq(10);			//���ݰ���
	// Ű������ PgUp, PgDnŰ�� �����ų� ���콺�� �����̴��� ������ Ŭ���� ������ ũ�� 
	m_SC_RotationX.SetPageSize(10);

	g_objectCtrlRX = m_SC_RotationX.GetPos();

	//object control RY======================================
	m_SC_RotationY.SetRange(0, 359);
	m_SC_RotationY.SetRangeMin(0);		//�ּҰ�
	m_SC_RotationY.SetRangeMax(359);		//�ִ밪
	m_SC_RotationY.SetPos(0);			//�ʱⰪ

										// �Ӽ��� Tick Marks�� Auto Ticks�� True�� �Ǿ� �־�� �Ѵ�.
	m_SC_RotationY.SetTicFreq(10);			//���ݰ���
											// Ű������ PgUp, PgDnŰ�� �����ų� ���콺�� �����̴��� ������ Ŭ���� ������ ũ�� 
	m_SC_RotationY.SetPageSize(10);

	g_objectCtrlRY = m_SC_RotationY.GetPos();

	//object control RZ=====================================
	m_SC_RotationZ.SetRange(0, 359);
	m_SC_RotationZ.SetRangeMin(0);		//�ּҰ�
	m_SC_RotationZ.SetRangeMax(359);		//�ִ밪
	m_SC_RotationZ.SetPos(0);			//�ʱⰪ

										// �Ӽ��� Tick Marks�� Auto Ticks�� True�� �Ǿ� �־�� �Ѵ�.
	m_SC_RotationZ.SetTicFreq(10);			//���ݰ���
											// Ű������ PgUp, PgDnŰ�� �����ų� ���콺�� �����̴��� ������ Ŭ���� ������ ũ�� 
	m_SC_RotationZ.SetPageSize(10);

	g_objectCtrlRZ = m_SC_RotationZ.GetPos();


	UpdateData(FALSE);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgObject::SetRadioStatus(UINT value)
{
	UpdateData(TRUE);

	switch (m_RB_objectBrush)
	{
		//manybrush
	case 0:
		AfxMessageBox(L"selected many");
		//�ķ�Ʈũ�� ���� Ȱ��ȭ
		m_objectBrushSize.EnableWindow(TRUE);
		g_RB_ObjectBrushKind = manybrush;
		break;

		//onebrush
	case 1:
		AfxMessageBox(L"selected one");
		//1���귯���϶�, manybrush �ķ�Ʈũ�� ��Ȱ��ȭ
		m_objectBrushSize.EnableWindow(FALSE);
		g_RB_ObjectBrushKind = onebrush;

		break;
	default:
		break;
	}
}



//object brush size
void CDlgObject::OnNMCustomdrawSlider5(NMHDR *pNMHDR, LRESULT *pResult)
{	
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
	UpdateData(TRUE);
	m_S_objectBrushSize.Format(_T("%d"), m_objectBrushSize.GetPos());
	g_objectBrushSize = m_objectBrushSize.GetPos();

	UpdateData(FALSE);
		
	*pResult = 0;
}

//scale
void CDlgObject::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_S_Scale.Format(_T("%d"), m_SC_Scale.GetPos());
	g_objectCtrlScale = m_SC_Scale.GetPos();

	UpdateData(FALSE);


	*pResult = 0;
}

//rotationX
void CDlgObject::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_S_RotationX.Format(_T("%d"), m_SC_RotationX.GetPos());
	g_objectCtrlRX = m_SC_RotationX.GetPos();
	UpdateData(FALSE); 
	
	*pResult = 0;
}


void CDlgObject::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_S_RotationY.Format(_T("%d"), m_SC_RotationY.GetPos());
	g_objectCtrlRY = m_SC_RotationY.GetPos();
	UpdateData(FALSE); 
	
	*pResult = 0;
}


void CDlgObject::OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_S_RotationZ.Format(_T("%d"), m_SC_RotationZ.GetPos());
	g_objectCtrlRZ = m_SC_RotationZ.GetPos();
	UpdateData(FALSE); 
	
	*pResult = 0;
}
