#include "StdAfx.h"
#include "cResourceMgr_Texture.h"


cResourceMgr_Texture::cResourceMgr_Texture(void)
{
}


cResourceMgr_Texture::~cResourceMgr_Texture(void)
{
}


//로드 방식만 재정의 
LPDIRECT3DTEXTURE9 cResourceMgr_Texture::LoadResource( std::string filePath, void* pParam )
{
	//텍스쳐 로딩
	LPDIRECT3DTEXTURE9	pNewTex = NULL;
	if( FAILED( D3DXCreateTextureFromFileA( Device, filePath.c_str(), &pNewTex ) ) )
		return NULL;

	return pNewTex;
}

//해재 방식만 재정의
void cResourceMgr_Texture::ReleaseResource( LPDIRECT3DTEXTURE9 data )
{
	
	//data->Release();
	SAFE_RELEASE( data );


}