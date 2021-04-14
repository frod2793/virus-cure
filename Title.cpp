#include "DXUT.h"
#include "Title.h"
#include "playBtn.h"
#include "Mouse.h" 

void Title::Init()
{
	OBJECT->AddObject("Mouse", new Mouse, INPUT->GetMousePos(), MOUSE);
	OBJECT->AddObject("PLAY", new playBtn, Vector2(WINSIZEX / 2, WINSIZEY / 2), UI);
}

void Title::Update()
{
}

void Title::Render()
{
	IMAGE->FindImage("Title")->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
}

void Title::Release()
{
}
