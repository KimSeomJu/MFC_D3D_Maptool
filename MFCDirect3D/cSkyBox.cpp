#include "stdafx.h"
#include "cSkyBox.h"


cSkyBox::cSkyBox()
{
}


cSkyBox::~cSkyBox()
{
}

HRESULT cSkyBox::init()
{
	//_isLoad = false;
	return S_OK;
}

void cSkyBox::update()
{
	//큐브맵이 한번 적용되면, 업데이트 하지 않음.
	if (g_isCkActBtnSkyBox) return;
	


	
	
}

void cSkyBox::release()
{
}

void cSkyBox::render()
{
	//큐브맵이 적용되지않으면, 그리지 않음
	if (!g_isCkActBtnSkyBox) return;

}

void cSkyBox::setSkyBox(CString filepath)
{


}
