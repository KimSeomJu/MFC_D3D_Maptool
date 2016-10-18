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
	//뷰행렬을 준비
	D3DXMATRIXA16 matView;
	D3DXVECTOR3 lookAtPos(0, 0, 0);		//0, 0, 0,  위치를 본다.
	D3DXVECTOR3 eyePos(5, 10, -20);		//눈의 위치는 0, 1, -10 이다.
	D3DXVECTOR3 up(0, 1, 0);				//상방기준은 월드 위다.

	D3DXMatrixLookAtLH(
		&matView,			//얻어올 뷰행렬 
		&eyePos,			//눈위치 벡터
		&lookAtPos,			//바라볼 위치
		&up					//상방 기준 ( 완전 정확하지 않아도된다 )
	);
	//뷰행렬 셋팅
	Device->SetTransform(D3DTS_VIEW, &matView);


	//투영행렬 준비
	D3DXMATRIXA16 matProjection;
	D3DXMatrixPerspectiveFovLH(
		&matProjection,
		60.0f * ONE_RAD,		//화각 ( 60.0 도 )
		static_cast<float>(WINSIZE_X) / static_cast<float>(WINSIZE_Y),		//화면 종횡비,
		0.01f,					//근거리 평면 거리 ( 이값이 0 이면 뎁스 꼬인다 0 으로 주지말아라 )
		100.0f);					//원거리 평명 거리
									//투영행렬 셋팅
	Device->SetTransform(D3DTS_PROJECTION, &matProjection);


	//정점의 컬러 정보를 출력하기 위해서는 Device 의 기본 라이팅 
	//기능을 해재해야 한다
	//당분간 라이팅을 사용할일이 없으니 라이팅을 끄자.
	Device->SetRenderState(
		D3DRS_LIGHTING,			//뭘셋팅할꺼니?
		FALSE					//셋팅값은 어떻게 되니?
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

	//큐브맵이 한번 적용되면, 업데이트 하지 않음.
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
