#include "DXUT.h"
#include "MainGame.h"
#include "LoadScene.h"
#include "test.h"
#include "Title.h"
#include "Intro.h"
#include "Endsc.h"
#include "stage2.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	Release();
}

void MainGame::Init()
{
	ShowCursor(false);

	CAMERA->Reset();

	SCENE->AddScene("loading", new LoadScene);
	SCENE->AddScene("test", new test);
	SCENE->AddScene("Title", new Title);
	SCENE->AddScene("Intro", new Intro);
	SCENE->AddScene("endsc", new ENdsc);
	SCENE->AddScene("stage2", new stage2);

	SCENE->ChangeScene("loading");

}

void MainGame::Update()
{

	CAMERA->Update();
	SCENE->Update();
	OBJECT->Update();
	INPUT->Update();
	GAME->Update();
}

void MainGame::Render()
{
	CAMERA->SetTransform();
	IMAGE->Begin();

	SCENE->Render();
	OBJECT->Render();

	IMAGE->End();
}

void MainGame::Release()
{
	ShowCursor(true);
	Gmanager::ReleaseInstance();
	SceneManager::ReleaseInstance();
	InputManager::ReleaseInstance();
	CameraManager::ReleaseInstance();
	ImageManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	Math::ReleaseInstance();
	SoundManager::ReleaseInstance();
}

void MainGame::LostDevice()
{
	IMAGE->LostDevice();
}

void MainGame::ResetDevice()
{
	IMAGE->ResetDevice();

}
