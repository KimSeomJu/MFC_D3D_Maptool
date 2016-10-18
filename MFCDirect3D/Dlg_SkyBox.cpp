// Dlg_SkyBox.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "Dlg_SkyBox.h"
#include "afxdialogex.h"


// CDlg_SkyBox 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlg_SkyBox, CDialog)

CDlg_SkyBox::CDlg_SkyBox(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_SkyBox::IDD, pParent)
	, m_EditOne(_T(""))
{

}

CDlg_SkyBox::~CDlg_SkyBox()
{
}

void CDlg_SkyBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);


	DDX_Text(pDX, IDC_EDIT1, m_EditOne);
	DDX_Control(pDX, IDC_BUTTON2, m_AcceptButton);
}


BEGIN_MESSAGE_MAP(CDlg_SkyBox, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg_SkyBox::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg_SkyBox::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CDlg_SkyBox::OnEnChangeEdit1)
	ON_EN_ERRSPACE(IDC_EDIT1, &CDlg_SkyBox::OnChangeEditOne)
	ON_NOTIFY(BCN_DROPDOWN, IDC_BUTTON2, &CDlg_SkyBox::OnButtClean)
END_MESSAGE_MAP()


// CDlg_SkyBox 메시지 처리기입니다.

//파일불러오기
void CDlg_SkyBox::OnBnClickedButton1()
{
	//CFileDialog dlg(
	//	TRUE(읽기) / FALSE(저장),
	//	기본확장자,
	//	기본파일명,
	//	열기모드->MSDN 참고,
	//	파일창 아래쪽에 나오는 필터링
	//)

	CFileDialog ins_dlg(TRUE); //ture = 파일열기 , false = 저장

	//char szFilter[] = "PCMON (*.CFG) | All Files(*.*)|*.*||";
	//CFileDialog ins_dlg(TRUE,NULL,"sample",OFN_HIDEREADONLY,szFilter);
	
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
		m_EditOne = strPathName;
		//D3D로 넘길 전역변수 파일경로
		g_skyBoxName = strPathName;

		UpdateData(FALSE);

	}
}

//적용하기
void CDlg_SkyBox::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_EditOne != L"null")//초기화되어있지 않으면,즉 파일이 로드되었으면
		g_isCkActBtnSkyBox = true;
}

//불러온파일
void CDlg_SkyBox::OnEnChangeEdit1()
{
	//http://code7.tistory.com/entry/%EC%97%90%EB%94%94%ED%84%B0%EC%83%81%EC%9E%90Edit-Control
	//BOOL UpdateData(BOOL bSaveAndValidate = TRUE)
	//BOOL bSaveAndValidate 에 
	//TRUE 값이 들어가면 컨트롤에 있는 값을 변수로 보내고 갱신을 하는 것입니다.
	//FALSE 값이 들어가면 변수에 있는 값을 컨트롤에 보내고 갱신을 하는 것입니다.
}


void CDlg_SkyBox::OnChangeEditOne()
{

}


void CDlg_SkyBox::OnButtClean(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;


}
