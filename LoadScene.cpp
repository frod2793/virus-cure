#include "DXUT.h"
#include "LoadScene.h"
#define maxcount 1

LoadScene::LoadScene()
{
}


LoadScene::~LoadScene()
{
}

void LoadScene::Init()
{
	CAMERA->Reset();


#pragma region FirstLoading // 로딩씬 리소스 로딩
#pragma endregion
	//이미지 로드 
#pragma region SecondLoading // 게임 리소스 로딩
	ImageLoad("MousePoint", "Ui/Mouse");
	ImageLoad("Jong", "Back/jong");
	ImageLoad("back1", "Back/back1");
	ImageLoad("back", "Back/back");
	ImageLoad("Title", "Back/Title");
	ImageLoad("Play", "Ui/Play");
	ImageLoad("mob", "Back/mob");
	ImageLoad("bullet", "Back/Bullet1");
	ImageLoad("bbt", "Back/Bullet");
	


#pragma endregion
}

void LoadScene::Update()
{


	if (!Imagelist.empty())
	{
		auto info = Imagelist.front();
		IMAGE->AddImage(info.m_Key, info.m_Path);
		Imagelist.pop_front();
		ImageCount++;
	}
	if (!Anilist.empty())
	{
		auto info = Anilist.front();
		IMAGE->ADDVECIMAGE(info.m_Key, info.m_Path, info.m_Size);
		Anilist.pop_front();
		ImageCount++;
	}
	if (Anilist.empty() && Imagelist.empty())
	{
		SCENE->ChangeScene("Intro"); 
	}

}

void LoadScene::Render()
{
}

void LoadScene::Release()
{
}

void LoadScene::ImageLoad(const string & _Key, const string & _Path, int size)
{
	if (size == 0)
	{
		Imagelist.push_back(Load(_Key, _Path));
		maxImageCount++;
	}
	else
	{
		Anilist.push_back(Load(_Key, _Path, size));
		maxImageCount++;
	}
}
