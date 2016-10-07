#include "StdAfx.h"
#include "cScene_Terrain.h"
#include "cTerrain.h"
#include "cCamera.h"
#include "cLight_Direction.h"


cScene_Terrain::cScene_Terrain(void)
{
}


cScene_Terrain::~cScene_Terrain(void)
{
}


HRESULT cScene_Terrain::Scene_Init()
{
	m_pTerrain = new cTerrain();
	m_pTerrain->Init(
		"../../MapToolResource/Resources/Testures/MyHeight512.bmp",
		"../../MapToolResource/Resources/Testures/terrain1.jpg",
		"../../MapToolResource/Resources/Testures/terrain2.png",
		"../../MapToolResource/Resources/Testures/terrain3.png",
		"../../MapToolResource/Resources/Testures/terrain4.png",
		"../../MapToolResource/Resources/Testures/Sheep_Splat.bmp",
		1.0f,
		100.0f,
		3,
		100);

	m_hitPos = D3DXVECTOR3(0, 0, 0);

	m_pTrans = new cTransform();

	m_pDirLight = new cLight_Direction();

	return S_OK;
}

void cScene_Terrain::Scene_Release()
{
	m_pTerrain->Release();
	SAFE_DELETE(m_pTerrain);
	SAFE_DELETE(m_pTrans);

	SAFE_DELETE(m_pDirLight);
}

void cScene_Terrain::Scene_Update(float timDelta)
{
	if (KEY_MGR->IsOnceDown(VK_LBUTTON))
	{
		Ray ray;
		
		POINT ptMousePos = GetMousePos();
		if (!(ptMousePos.x > WINSIZE_X || ptMousePos.y > WINSIZE_Y ||
			ptMousePos.y < 109))
		{
			D3DXVECTOR2 screenPos(ptMousePos.x, ptMousePos.y);
			this->pMainCamera->ComputeRay(&ray, &screenPos);


			//Terrain �̶� Rayüũ
			this->m_pTerrain->IsIntersectRay(&m_hitPos, &ray);
		}

		

	}

	//�Ÿ��� ���Ѵ�.
	D3DXVECTOR3 dirToTarget = this->m_hitPos - this->m_pTrans->GetWorldPosition();
	float dist = D3DXVec3Length(&dirToTarget);

	//�̵���
	float deltaMove = 3.0f * timDelta;
	float t = Clamp01(deltaMove / dist);

	D3DXVECTOR3 pos = VecLerp(this->m_pTrans->GetWorldPosition(), this->m_hitPos, t);

	//���� ��´�.
	pos.y = this->m_pTerrain->GetHeight(pos.x, pos.z);

	this->m_pTrans->SetWorldPosition(pos);


	//�߷�ó��
	D3DXVECTOR3 sliding;
	m_pTerrain->GetSlant(&sliding, 9.81f, pos.x, pos.z);

	//���� sliding ��ŭ ���� �̵���Ŵ

	this->m_pTrans->MovePositionWorld(sliding * timDelta);



	this->m_pDirLight->pTransform->DefaultControl2(timDelta);





}

void cScene_Terrain::Scene_Render1()
{

	m_pTerrain->Render(this->pMainCamera, m_pDirLight);

	//���׼��� 0xff806A12
	Device->SetRenderState(D3DRS_FOGENABLE, TRUE);						//���� ��뿩��
	Device->SetRenderState(D3DRS_FOGCOLOR, 0xffff0000);					//���� ����

	Device->SetRenderState(D3DRS_FOGSTART, FloatToDWORD(0.5f));		//���� ���� �Ÿ�
	Device->SetRenderState(D3DRS_FOGEND, FloatToDWORD(100.0f));			//���� ���� �Ÿ�
	Device->SetRenderState(D3DRS_FOGTABLEMODE, D3DFOG_LINEAR);			//���׼��� ���
	//Device->SetRenderState(D3DRS_FOGDENSITY, FloatToDWORD(1));
	//Device->SetRenderState(D3DRS_RANGEFOGENABLE, TRUE);

	//Device->SetRenderState( D3DRS_FOGENABLE, false );
	Ray ray;
	POINT ptMousePos = GetMousePos();
	D3DXVECTOR2 screenPos = D3DXVECTOR2(ptMousePos.x, ptMousePos.y);
	D3DXVECTOR3 worldPos;

	this->pMainCamera->ComputeRay(&ray, &screenPos);
	this->pMainCamera->GetWorldPosToScreenPos(&screenPos, &ray.origin);

	//Hit ��ġ�� ��
	GIZMO_MGR->WireSphere(this->m_hitPos, 0.5f, 0xffff0000);
	GIZMO_MGR->WireSphere(ray.origin, 0.5f, 0xffff0000);

	//Trans ��ġ�� ��
	GIZMO_MGR->WireSphere(this->m_pTrans->GetWorldPosition(), 1.0f, 0xffffffff);
	this->m_pTrans->RenderGimozo();

}
