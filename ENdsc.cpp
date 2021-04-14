#include "DXUT.h"
#include "ENdsc.h"

void ENdsc::Init()
{
	CAMERA->Reset();
	IMAGE->drawText("CLEAR", Vector2(WINSIZEX / 2, WINSIZEY / 2), 100, D3DCOLOR_XRGB(255, 255, 255), true);
}

void ENdsc::Update()
{
}

void ENdsc::Render()
{
	IMAGE->FindImage("back")->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 });
	IMAGE->drawText("CLEAR", Vector2(WINSIZEX / 2, WINSIZEY / 2), 50, D3DCOLOR_XRGB(255, 255, 255), true);
}

void ENdsc::Release()
{
}
