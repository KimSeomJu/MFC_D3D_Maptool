// DlgTerrain.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "DlgTerrain.h"
#include "afxdialogex.h"


// CDlgTerrain ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgTerrain, CDialog)

CDlgTerrain::CDlgTerrain(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTerrain::IDD, pParent)
	, m_TerrainX(_T(""))
	, m_TerrainY(_T(""))
	, m_CBS_landList(_T(""))
	, m_CBS_landBrush(_T(""))
	, m_S_heightMapPath(_T(""))
	, m_CBS_HeightBrush(_T(""))
	, m_BrushSize(_T(""))
	, m_BrushPower(_T(""))
	, m_RB_Brush(0)
{

}

CDlgTerrain::~CDlgTerrain()
{
}

void CDlgTerrain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_TerrainX);
	DDX_Text(pDX, IDC_EDIT2, m_TerrainY);
	DDX_CBString(pDX, IDC_COMBO1, m_CBS_landList);
	DDX_Control(pDX, IDC_COMBO1, m_CB_landList);
	DDX_Control(pDX, IDC_COMBO2, m_CB_landBrush);
	DDX_CBString(pDX, IDC_COMBO2, m_CBS_landBrush);
	DDX_Text(pDX, IDC_EDIT3, m_S_heightMapPath);
	DDX_Control(pDX, IDC_SLIDER1, m_SC_BrushSize);
	DDX_Text(pDX, IDC_EDIT4, m_BrushSize);
	DDX_Control(pDX, IDC_SLIDER2, m_SC_BrushPower);
	DDX_Text(pDX, IDC_EDIT5, m_BrushPower);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_SB_TerrainScroll);
	DDX_Radio(pDX, IDC_RADIO1, (int &)m_RB_Brush);
}


BEGIN_MESSAGE_MAP(CDlgTerrain, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgTerrain::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CDlgTerrain::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTerrain::OnBnClickedButton1)
	//ON_EN_ERRSPACE(IDC_EDIT1, &CDlgTerrain::OnChangeEditOne)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlgTerrain::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CDlgTerrain::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTerrain::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgTerrain::OnBnClickedButton3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CDlgTerrain::OnNMCustomdrawSlider1)
	ON_EN_CHANGE(IDC_EDIT4, &CDlgTerrain::OnEnChangeEdit4)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CDlgTerrain::OnNMCustomdrawSlider2)
	ON_EN_CHANGE(IDC_EDIT5, &CDlgTerrain::OnEnChangeEdit5)
	//	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR2, &CDlgTerrain::OnHScroll)

	//������ư
	ON_WM_VSCROLL()
	//ON_CONTROL_RANGE(�̺�Ʈ,�׷����,�׷쳡,ȣ���Լ�)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO1, IDC_RADIO2, SetRadioStatus)
	//ON_BN_CLICKED(IDC_RADIO1, &CDlgTerrain::OnBnClickedRadio1)
END_MESSAGE_MAP()


// CDlgTerrain �޽��� ó�����Դϴ�.

//X
void CDlgTerrain::OnEnChangeEdit1()
{
	//�ǽð����� �ԷµǴ� ���ڰ��� ����
	UpdateData(TRUE);
}

//Y
void CDlgTerrain::OnEnChangeEdit2()
{
	//�ǽð����� �ԷµǴ� ���ڰ��� ����
	UpdateData(TRUE);
}

//X * Y �����ϱ� ��ư
void CDlgTerrain::OnBnClickedButton1()
{
	UpdateData(TRUE);

	//CString -> int 
	g_terrainX = _ttoi(m_TerrainX);
	g_terrainY = _ttoi(m_TerrainY);
	UpdateData(FALSE);

}




void CDlgTerrain::OnChangeEditOne()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

BOOL CDlgTerrain::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_TerrainX = "0";
	m_TerrainY = "0";
	m_S_heightMapPath = L"null";

	//int to CString
	m_BrushSize.Format(_T("%d"), m_SC_BrushSize.GetPos());
	g_terrainBrushSize = m_SC_BrushSize.GetPos();
	UpdateData(FALSE);

	//terrain land==============================
	//�޺��ڽ� ����Ʈ �ʱ�ȭ
	m_CB_landList.AddString(_T("unselect"));
	m_CB_landList.AddString(_T("grass"));
	m_CB_landList.AddString(_T("land"));
	m_CB_landList.AddString(_T("stone"));	
	
	m_CB_landList.SetCurSel(0);			//�ʱ� �޺��ڽ��� ����

	//terrain land brush==============================
	m_CB_landBrush.AddString(_T("unselect"));
	m_CB_landBrush.AddString(_T("sample1"));
	m_CB_landBrush.AddString(_T("sample2"));
	m_CB_landBrush.AddString(_T("sample3"));

	m_CB_landBrush.SetCurSel(0);		//�ʱ� �޺��ڽ��� ����

	//terrain bursh size=============================
	m_SC_BrushSize.SetRange(0, 100);	//����
	m_SC_BrushSize.SetRangeMin(0);		//�ּҰ�
	m_SC_BrushSize.SetRangeMax(100);	//�ִ밪
	m_SC_BrushSize.SetPos(50);			//�ʱⰪ
	
    // �Ӽ��� Tick Marks�� Auto Ticks�� True�� �Ǿ� �־�� �Ѵ�.
	m_SC_BrushSize.SetTicFreq(10);		//���ݰ���
	// Ű������ PgUp, PgDnŰ�� �����ų� ���콺�� �����̴��� ������ Ŭ���� ������ ũ�� 
	m_SC_BrushSize.SetPageSize(10);

	//terrain bursh power=============================
	m_SC_BrushPower.SetRange(0, 100);	//����
	m_SC_BrushPower.SetRangeMin(0);		//�ּҰ�
	m_SC_BrushPower.SetRangeMax(100);	//�ִ밪
	m_SC_BrushPower.SetPos(50);			//�ʱⰪ

	// �Ӽ��� Tick Marks�� Auto Ticks�� True�� �Ǿ� �־�� �Ѵ�.
	m_SC_BrushPower.SetTicFreq(10);		//���ݰ���
	// Ű������ PgUp, PgDnŰ�� �����ų� ���콺�� �����̴��� ������ Ŭ���� ������ ũ�� 
	m_SC_BrushPower.SetPageSize(10);

	//tab scrollbar
	m_SB_TerrainScroll.SetScrollRange(0, 100);
	m_SB_TerrainScroll.SetScrollPos(0);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


//terrain land combobox===============================================
void CDlgTerrain::OnCbnSelchangeCombo1()
{
	int select;

	//���õ� �޺��ڽ� ����� m_strCombo ������ �־��ش�.
	select = m_CB_landList.GetCurSel();
	m_CB_landList.GetLBText(select, m_CBS_landList);
	SetDlgItemText(IDC_COMBO1, m_CBS_landList);

	//m_strCombo �� ���� ���Ǻб�
	if (m_CBS_landList == "unselect")
	{
		g_CB_Landlist = LandUnselect;
	}
	else if (m_CBS_landList == "grass")
	{
		g_CB_Landlist = LandGrass;
	}
	else if (m_CBS_landList == "land")
	{
		g_CB_Landlist = LandLand;
	}
	else if (m_CBS_landList == "stone")
	{
		g_CB_Landlist = LandStone;
	}
}

//terrain brush combobox===============================================
void CDlgTerrain::OnCbnSelchangeCombo2()
{
	int select;

	//���õ� �޺��ڽ� ����� m_strCombo ������ �־��ش�.
	select = m_CB_landBrush.GetCurSel();
	m_CB_landBrush.GetLBText(select, m_CBS_landBrush);
	SetDlgItemText(IDC_COMBO2, m_CBS_landBrush);

	//m_strCombo �� ���� ���Ǻб�
	if (m_CBS_landBrush == "unselect")
	{
		g_CB_LandBrushList = BrushUnselect;
	}
	else if (m_CBS_landBrush == "sample1")
	{
		g_CB_LandBrushList = BrushSample1;
	}
	else if (m_CBS_landBrush == "sample2")
	{
		g_CB_LandBrushList = BrushSample2;
	}
	else if (m_CBS_landBrush == "sample3")
	{
		g_CB_LandBrushList = BrushSample3;
	}

}


//=====================================================================

//heightmap �ҷ������ư
void CDlgTerrain::OnBnClickedButton2()
{
	CFileDialog ins_dlg(TRUE);

	//���� ����â ���
	if (ins_dlg.DoModal() == IDOK)
	{
		//http://wyseburn.tistory.com/entry/CFileDialog-%ED%8C%8C%EC%9D%BC%EC%9D%84-%EC%9D%BD%EA%B1%B0%EB%82%98-%EC%A0%80%EC%9E%A5%ED%95%A0%EB%95%8C-%ED%8C%8C%EC%9D%BC%EC%B0%BD-%EB%9D%84%EC%9A%B0%EA%B8%B0
		CString strPathName = ins_dlg.GetPathName();
		CFile fp;
		CFileException e;
		//������ ������ �ʾ��� ��, ����ó��
		if (!fp.Open(strPathName, CFile::modeRead, &e))
		{
			e.ReportError();
			return;
		}
		CString str;
		CArchive ar(&fp, CArchive::load);
		ar >> str;

		//����Ʈ �ڽ��� ǥ�õ� ���ϰ��
		m_S_heightMapPath = strPathName;
		//D3D�� �ѱ� �������� ���ϰ��
		g_heightMapPath = strPathName;

		UpdateData(FALSE);

	}
}

// height map Accept��ư
void CDlgTerrain::OnBnClickedButton3()
{
	if (m_S_heightMapPath != L"null")
		g_isCkActBtnHeightMap = true;
}

// brush size �����̴�
void CDlgTerrain::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_BrushSize.Format(_T("%d"), m_SC_BrushSize.GetPos());
	g_terrainBrushSize = m_SC_BrushSize.GetPos();
	UpdateData(FALSE);

	*pResult = 0;
}

void CDlgTerrain::OnEnChangeEdit4()
{	
}

//brush power �����̴�
void CDlgTerrain::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_BrushPower.Format(_T("%d"), m_SC_BrushPower.GetPos());
	g_terrainBrushPower = m_SC_BrushPower.GetPos();
	UpdateData(FALSE);
	*pResult = 0;
}


void CDlgTerrain::OnEnChangeEdit5()
{
}

//��ũ�ѹ� ���� (������ ������ ������)
void CDlgTerrain::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	if (pScrollBar)
	{
		if (pScrollBar == (CScrollBar*)&m_SB_TerrainScroll)
		{
			SCROLLINFO scrinfo;
			if (pScrollBar->GetScrollInfo(&scrinfo))
			{
				switch (nSBCode)
				{
				case SB_LINEUP:
					scrinfo.nPos -= scrinfo.nPage;
					break;
				case SB_LINEDOWN:
					scrinfo.nPos += scrinfo.nPage;
					break;
				case SB_PAGEUP:
					scrinfo.nPos -= scrinfo.nPage/10;
					break;
				case SB_PAGEDOWN:
					scrinfo.nPos += scrinfo.nPage/10;
					break;
				case SB_THUMBPOSITION:
				case SB_THUMBTRACK:
					scrinfo.nPos = scrinfo.nTrackPos;
					break;
				}

				pScrollBar->SetScrollPos(scrinfo.nPos);
			}
		}
	}

	else
	{
		//int ScrollPos = GetScrollPos(SB_VERT);
		//SCROLLINFO scrinfo2;
		//switch (nSBCode)
		//{
		//case SB_PAGEUP:
		//case SB_PAGEDOWN:
		//case SB_LINEUP:
		//case SB_LINEDOWN:
		//	CDialog::OnVScroll(nSBCode,nPos,pScrollBar);
		//	break;
		//case SB_THUMBPOSITION:
		//case SB_THUMBTRACK:
		//	scrinfo2.nPos = scrinfo2.nTrackPos;
		//	SetScrollPos(SB_VERT, scrinfo2.nPos);
		//	Invalidate(FALSE);
		//	break;
		//
		//default:
		//	break;
		//}
	}

}

//������ư 1���� Ŭ������ �� ����Ǵ� �Լ�, ������ ��������
//setRadioStatus�Լ��� �����Ǳ� ������ �����ȵ�!!
void CDlgTerrain::OnBnClickedRadio1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CDlgTerrain::SetRadioStatus(UINT value)
{
	UpdateData(TRUE);

	switch (m_RB_Brush)
	{
		//upbrush
	case 0:
		AfxMessageBox(L"selected upbrush");
		g_RB_TerrainBrushKind = upbrush;
		break;

		//downbrush
	case 1:
		AfxMessageBox(L"selected downbrush");
		g_RB_TerrainBrushKind = downbrush;

		break;
	default:
		break;
	}

	UpdateData(FALSE);

}
