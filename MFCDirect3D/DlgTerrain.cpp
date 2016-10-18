// DlgTerrain.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "DlgTerrain.h"
#include "afxdialogex.h"


// CDlgTerrain 대화 상자입니다.

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

	//라디오버튼
	ON_WM_VSCROLL()
	//ON_CONTROL_RANGE(이벤트,그룹시작,그룹끝,호출함수)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO1, IDC_RADIO2, SetRadioStatus)
	//ON_BN_CLICKED(IDC_RADIO1, &CDlgTerrain::OnBnClickedRadio1)
END_MESSAGE_MAP()


// CDlgTerrain 메시지 처리기입니다.

//X
void CDlgTerrain::OnEnChangeEdit1()
{
	//실시간으로 입력되는 숫자값을 갱신
	UpdateData(TRUE);
}

//Y
void CDlgTerrain::OnEnChangeEdit2()
{
	//실시간으로 입력되는 숫자값을 갱신
	UpdateData(TRUE);
}

//X * Y 적용하기 버튼
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	//콤보박스 리스트 초기화
	m_CB_landList.AddString(_T("unselect"));
	m_CB_landList.AddString(_T("grass"));
	m_CB_landList.AddString(_T("land"));
	m_CB_landList.AddString(_T("stone"));	
	
	m_CB_landList.SetCurSel(0);			//초기 콤보박스값 정의

	//terrain land brush==============================
	m_CB_landBrush.AddString(_T("unselect"));
	m_CB_landBrush.AddString(_T("sample1"));
	m_CB_landBrush.AddString(_T("sample2"));
	m_CB_landBrush.AddString(_T("sample3"));

	m_CB_landBrush.SetCurSel(0);		//초기 콤보박스값 정의

	//terrain bursh size=============================
	m_SC_BrushSize.SetRange(0, 100);	//범위
	m_SC_BrushSize.SetRangeMin(0);		//최소값
	m_SC_BrushSize.SetRangeMax(100);	//최대값
	m_SC_BrushSize.SetPos(50);			//초기값
	
    // 속성의 Tick Marks와 Auto Ticks가 True로 되어 있어야 한다.
	m_SC_BrushSize.SetTicFreq(10);		//눈금간격
	// 키보드의 PgUp, PgDn키를 누르거나 마우스로 슬라이더의 몸동을 클릭시 움직일 크기 
	m_SC_BrushSize.SetPageSize(10);

	//terrain bursh power=============================
	m_SC_BrushPower.SetRange(0, 100);	//범위
	m_SC_BrushPower.SetRangeMin(0);		//최소값
	m_SC_BrushPower.SetRangeMax(100);	//최대값
	m_SC_BrushPower.SetPos(50);			//초기값

	// 속성의 Tick Marks와 Auto Ticks가 True로 되어 있어야 한다.
	m_SC_BrushPower.SetTicFreq(10);		//눈금간격
	// 키보드의 PgUp, PgDn키를 누르거나 마우스로 슬라이더의 몸동을 클릭시 움직일 크기 
	m_SC_BrushPower.SetPageSize(10);

	//tab scrollbar
	m_SB_TerrainScroll.SetScrollRange(0, 100);
	m_SB_TerrainScroll.SetScrollPos(0);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


//terrain land combobox===============================================
void CDlgTerrain::OnCbnSelchangeCombo1()
{
	int select;

	//선택된 콤보박스 목록을 m_strCombo 변수에 넣어준다.
	select = m_CB_landList.GetCurSel();
	m_CB_landList.GetLBText(select, m_CBS_landList);
	SetDlgItemText(IDC_COMBO1, m_CBS_landList);

	//m_strCombo 에 따른 조건분기
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

	//선택된 콤보박스 목록을 m_strCombo 변수에 넣어준다.
	select = m_CB_landBrush.GetCurSel();
	m_CB_landBrush.GetLBText(select, m_CBS_landBrush);
	SetDlgItemText(IDC_COMBO2, m_CBS_landBrush);

	//m_strCombo 에 따른 조건분기
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

//heightmap 불러오기버튼
void CDlgTerrain::OnBnClickedButton2()
{
	CFileDialog ins_dlg(TRUE);

	//파일 열기창 띄움
	if (ins_dlg.DoModal() == IDOK)
	{
		//http://wyseburn.tistory.com/entry/CFileDialog-%ED%8C%8C%EC%9D%BC%EC%9D%84-%EC%9D%BD%EA%B1%B0%EB%82%98-%EC%A0%80%EC%9E%A5%ED%95%A0%EB%95%8C-%ED%8C%8C%EC%9D%BC%EC%B0%BD-%EB%9D%84%EC%9A%B0%EA%B8%B0
		CString strPathName = ins_dlg.GetPathName();
		CFile fp;
		CFileException e;
		//파일이 열리지 않았을 시, 예외처리
		if (!fp.Open(strPathName, CFile::modeRead, &e))
		{
			e.ReportError();
			return;
		}
		CString str;
		CArchive ar(&fp, CArchive::load);
		ar >> str;

		//에디트 박스에 표시될 파일경로
		m_S_heightMapPath = strPathName;
		//D3D로 넘길 전역변수 파일경로
		g_heightMapPath = strPathName;

		UpdateData(FALSE);

	}
}

// height map Accept버튼
void CDlgTerrain::OnBnClickedButton3()
{
	if (m_S_heightMapPath != L"null")
		g_isCkActBtnHeightMap = true;
}

// brush size 슬라이더
void CDlgTerrain::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_BrushSize.Format(_T("%d"), m_SC_BrushSize.GetPos());
	g_terrainBrushSize = m_SC_BrushSize.GetPos();
	UpdateData(FALSE);

	*pResult = 0;
}

void CDlgTerrain::OnEnChangeEdit4()
{	
}

//brush power 슬라이더
void CDlgTerrain::OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_BrushPower.Format(_T("%d"), m_SC_BrushPower.GetPos());
	g_terrainBrushPower = m_SC_BrushPower.GetPos();
	UpdateData(FALSE);
	*pResult = 0;
}


void CDlgTerrain::OnEnChangeEdit5()
{
}

//스크롤바 구현 (구현은 했지만 미적용)
void CDlgTerrain::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
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

//라디오버튼 1번을 클릭했을 때 실행되는 함수, 동작은 안하지만
//setRadioStatus함수와 연동되기 때문에 지우면안됨!!
void CDlgTerrain::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
