#pragma once

#include "singleton.h"
class Gmanager:
	public singleton<Gmanager>
{

public:

	void Init();
	void Update();
	void Release();

	void reLine();
	D3DLOCKED_RECT lr;
	DWORD* textureColor;
	D3DXCOLOR targetPixel;
	RECT r;
	D3DXCOLOR MainColor;

	texture* m_sprite;
	int map[WINSIZEX / 10][WINSIZEY / 10] = { 0 };


};

#define GAME Gmanager::GetInstance()
