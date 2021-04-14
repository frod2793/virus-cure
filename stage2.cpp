#include "DXUT.h"
#include "stage2.h"
#include "Mouse.h"
#include "player.h"
#include "Gmanager.h"
#include "boss.h"
#include "mob.h"
#include "Shmob.h"
void stage2::Init()
{
	CAMERA->Reset();
	OBJECT->AddObject("Player", new player, Vector2(90, 90), PLAYER);
	//OBJECT->AddObject("Mouse", new Mouse, INPUT->GetMousePos(), MOUSE);
	OBJECT->AddObject("Boss", new boss, Vector2(500, 500), MOB);

	ENsp = new Timer;
	ENsp->setTimer(1.5f);


	srand(time(NULL));
	textTime = 0;

}

void stage2::Update()
{
	Vector2 B_Pos = OBJECT->Boss->bPos;
	g = ceil(OBJECT->Boss->vPos.x);
	h = ceil(OBJECT->Boss->vPos.y);

	//SPpos = bPos;

	if (ENsp->Update())
	{
		//OBJECT->AddObject("mob",new mob, Vector2(g, h), MOB);
		OBJECT->AddObject("smob", new Shmob, Vector2(g, h), MOB);
	}

}

void stage2::Render()
{
	IMAGE->FindImage("back1")->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });

	if (textTime < 2)
	{
		IMAGE->drawText("STAGE 2", Vector2(WINSIZEX / 2, WINSIZEY / 2), 50, color, true);
	}
}

void stage2::Release()
{

	SAFE_DELETE(ENsp);
}
