#pragma once

class cImage;			//�̷�Ŭ������ �ִ�
class cScene;

class cMainGame
{
private:	
	cScene*					m_pNowScene;


public:
	cMainGame(void);
	~cMainGame(void);

	//����
	HRESULT Init(void);
	HRESULT Init(HWND ghwnd);

	//����
	void Release();

	//������Ʈ
	void Update();

	//��ο�
	void Draw();

	
public:

	//���ν���
	LRESULT MainProc( HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam );

};
