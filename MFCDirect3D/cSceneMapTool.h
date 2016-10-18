#pragma once
#include "cScene.h"

#include "cSkyBox.h"


class cCamera;
class cBaseObject;

class cSceneMapTool : public cScene
{
private:
	//cSkyBox* _cSkyBox;

	bool _isAcceptSkybox;

public:
	cSceneMapTool();
	~cSceneMapTool();

	HRESULT Scene_Init();
	void Scene_Release();
	void Scene_Update(float timDelta);
	void Scene_Render1();
	void Scene_RenderSprite();


};

