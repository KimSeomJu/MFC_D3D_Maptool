#pragma once
#include "cScene.h"

class cTerrain;
class cTransform;
class cLight_Direction;

class cScene_Terrain :
	public cScene
{
	cTerrain*		m_pTerrain;

	D3DXVECTOR3		m_hitPos;
	cTransform*		m_pTrans;
	cLight_Direction* m_pDirLight;

public:
	cScene_Terrain(void);
	~cScene_Terrain(void);


	virtual HRESULT Scene_Init();

	virtual void Scene_Release();

	virtual void Scene_Update(float timDelta);

	virtual void Scene_Render1();


};

