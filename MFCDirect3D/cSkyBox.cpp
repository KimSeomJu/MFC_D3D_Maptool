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
	//ť����� �ѹ� ����Ǹ�, ������Ʈ ���� ����.
	if (g_isCkActBtnSkyBox) return;
	


	
	
}

void cSkyBox::release()
{
}

void cSkyBox::render()
{
	//ť����� �������������, �׸��� ����
	if (!g_isCkActBtnSkyBox) return;

}

void cSkyBox::setSkyBox(CString filepath)
{


}
