#include "DXUT.h"
#include "end.h"

void end::Init()
{
}

void end::Update()
{
}

void end::Render()
{
	IMAGE->FindImage("back")->CenterRender ({ WINSIZEX / 2, WINSIZEY / 2 });
	IMAGE->drawText(to_string((int)("CLEAR")) + "%", { 960,50 }, 50, D3DCOLOR_XRGB(255, 255, 255), false);
}

void end::Release()
{
}
