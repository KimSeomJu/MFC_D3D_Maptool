// Dlg_SkyBox.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCDirect3D.h"
#include "Dlg_SkyBox.h"
#include "afxdialogex.h"


// CDlg_SkyBox ��ȭ �����Դϴ�.

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


// CDlg_SkyBox �޽��� ó�����Դϴ�.

//���Ϻҷ�����
void CDlg_SkyBox::OnBnClickedButton1()
{
	//CFileDialog dlg(
	//	TRUE(�б�) / FALSE(����),
	//	�⺻Ȯ����,
	//	�⺻���ϸ�,
	//	������->MSDN ����,
	//	����â �Ʒ��ʿ� ������ ���͸�
	//)

	CFileDialog ins_dlg(TRUE); //ture = ���Ͽ��� , false = ����

	//char szFilter[] = "PCMON (*.CFG) | All Files(*.*)|*.*||";
	//CFileDialog ins_dlg(TRUE,NULL,"sample",OFN_HIDEREADONLY,szFilter);
	
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
		m_EditOne = strPathName;
		//D3D�� �ѱ� �������� ���ϰ��
		g_skyBoxName = strPathName;

		UpdateData(FALSE);

	}
}

//�����ϱ�
void CDlg_SkyBox::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_EditOne != L"null")//�ʱ�ȭ�Ǿ����� ������,�� ������ �ε�Ǿ�����
		g_isCkActBtnSkyBox = true;
}

//�ҷ�������
void CDlg_SkyBox::OnEnChangeEdit1()
{
	//http://code7.tistory.com/entry/%EC%97%90%EB%94%94%ED%84%B0%EC%83%81%EC%9E%90Edit-Control
	//BOOL UpdateData(BOOL bSaveAndValidate = TRUE)
	//BOOL bSaveAndValidate �� 
	//TRUE ���� ���� ��Ʈ�ѿ� �ִ� ���� ������ ������ ������ �ϴ� ���Դϴ�.
	//FALSE ���� ���� ������ �ִ� ���� ��Ʈ�ѿ� ������ ������ �ϴ� ���Դϴ�.
}


void CDlg_SkyBox::OnChangeEditOne()
{

}


void CDlg_SkyBox::OnButtClean(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;


}
