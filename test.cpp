#include "DXUT.h"
#include "test.h"
#include "Mouse.h"
#include "player.h"
#include "Gmanager.h"
#include "boss.h"
#include "mob.h"
#include "Shmob.h"

void test::Init()
{
	CAMERA->Reset();
	OBJECT->AddObject("Player", new player, Vector2(90, 90), PLAYER);
	OBJECT->AddObject("Mouse", new Mouse, INPUT->GetMousePos(), MOUSE);
	OBJECT->AddObject("Boss", new boss, Vector2(500, 500), MOB);

	ENsp = new Timer;
	ENsp->setTimer(1.5f);

	srand(time(NULL));
	textTime = 0;

}

void test::Update()
{
	Vector2 B_Pos = OBJECT->Boss->bPos;
	g = ceil(OBJECT->Boss->vPos.x );
	h = ceil(OBJECT->Boss->vPos.y );

	//SPpos = bPos;
	  
	if (ENsp->Update())
	{
		OBJECT->AddObject("mob",new mob, Vector2(g, h), MOB);
		//OBJECT->AddObject("smob",new Shmob, Vector2(g, h), MOB);
	}
	textTime += D_TIME;
}

void test::Render()
{
	IMAGE->FindImage("back1")->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });  
	if (textTime < 2)
	{
		IMAGE->drawText(text, { 960,50 }, 100, D3DCOLOR_XRGB(255, 255, 255), false);
	}
}

void test::Release()
{
	SAFE_DELETE(ENsp);
}
