#include "stdafx.h"
#include "cSceneMapTool.h"


cSceneMapTool::cSceneMapTool()
{
}


cSceneMapTool::~cSceneMapTool()
{
}

HRESULT cSceneMapTool::Scene_Init()
{
	//������� �غ�
	D3DXMATRIXA16 matView;
	D3DXVECTOR3 lookAtPos(0, 0, 0);		//0, 0, 0,  ��ġ�� ����.
	D3DXVECTOR3 eyePos(5, 10, -20);		//���� ��ġ�� 0, 1, -10 �̴�.
	D3DXVECTOR3 up(0, 1, 0);				//�������� ���� ����.

	D3DXMatrixLookAtLH(
		&matView,			//���� ����� 
		&eyePos,			//����ġ ����
		&lookAtPos,			//�ٶ� ��ġ
		&up					//��� ���� ( ���� ��Ȯ���� �ʾƵ��ȴ� )
	);
	//����� ����
	Device->SetTransform(D3DTS_VIEW, &matView);


	//������� �غ�
	D3DXMATRIXA16 matProjection;
	D3DXMatrixPerspectiveFovLH(
		&matProjection,
		60.0f * ONE_RAD,		//ȭ�� ( 60.0 �� )
		static_cast<float>(WINSIZE_X) / static_cast<float>(WINSIZE_Y),		//ȭ�� ��Ⱦ��,
		0.01f,					//�ٰŸ� ��� �Ÿ� ( �̰��� 0 �̸� ���� ���δ� 0 ���� �������ƶ� )
		100.0f);					//���Ÿ� ��� �Ÿ�
									//������� ����
	Device->SetTransform(D3DTS_PROJECTION, &matProjection);


	//������ �÷� ������ ����ϱ� ���ؼ��� Device �� �⺻ ������ 
	//����� �����ؾ� �Ѵ�
	//��а� �������� ��������� ������ �������� ����.
	Device->SetRenderState(
		D3DRS_LIGHTING,			//�������Ҳ���?
		FALSE					//���ð��� ��� �Ǵ�?
	);

	//=========================================================

	//_cSkyBox->init();
	_isAcceptSkybox = false;
	return S_OK;
}

void cSceneMapTool::Scene_Release()
{
	//_cSkyBox->release();
}

void cSceneMapTool::Scene_Update(float timDelta)
{
	//_cSkyBox->update();

	//ť����� �ѹ� ����Ǹ�, ������Ʈ ���� ����.
	if (g_isCkActBtnSkyBox )
	{
		_isAcceptSkybox = true;

		//CString -> string
		CT2CA pszConvertedAnsiString(g_skyBoxName);
		std::string string(pszConvertedAnsiString);
		this->SetEnvironment(string);
	}

	

}

void cSceneMapTool::Scene_Render1()
{
	char szTemp[128];

	wsprintfA(szTemp, "X : %d    Y : %d", g_terrainX,g_terrainY);
	DXFONT_MGR->PrintTextOutline(szTemp, 0, 70, 0xffffff00, 0xff000000);


	//_cSkyBox->render();
	
}

void cSceneMapTool::Scene_RenderSprite()
{
}
