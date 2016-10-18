#pragma once
class cSkyBox
{
private:

public:
	cSkyBox();
	~cSkyBox();

	HRESULT init();
	void release();
	void update();	
	void render();

	void setSkyBox(CString filepath);
};

