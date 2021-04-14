#include "DXUT.h"
#include "Shmob.h"
#include "EBullet.h"

void Shmob::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	collider->SetRange(vPos, 50, 50);
	OBJECT->AddCollsion(collider);

	Speedx = 400;
	Speedy = 500;

	Busp = new Timer;
	Busp->setTimer(2.0f);

	srand(time(NULL));
}

void Shmob::Update()
{
	this->collider->SetRange(vPos, 192, 200);
	i = ceil(vPos.x / 10);
	j = ceil(vPos.y / 10);
	Vector2 B_Pos = OBJECT->Smob->bPos;


	if (GAME->map[i - 1][j] == 1 || GAME->map[i - 1][j] == 3) {
		Speedx = Speedx * -1;
	}
	if (GAME->map[i + 1][j] == 1 || GAME->map[i + 1][j] == 3) {
		Speedx = Speedx * -1;
	}
	if (GAME->map[i][j - 1] == 1 || GAME->map[i][j - 1] == 3) {
		Speedy = Speedy * -1;
	}
	if (GAME->map[i][j + 1] == 1 || GAME->map[i][j + 1] == 3) {
		Speedy = Speedy * -1;
	}
	vPos.x += -Speedx * D_TIME;
	vPos.y += -Speedy * D_TIME;


	

	if (Busp->Update())
	{
		OBJECT->AddObject("bullet", new EBullet, Vector2(i * 10, j *10 ), EBULLET);
	}

	if (GAME->map[i][j] == 3)
	{
		isDestroy = true;
	}
}

void Shmob::Render()
{
	IMAGE->FindImage("mob")->CenterRender(vPos);
}

void Shmob::Release()
{
	SAFE_DELETE(collider);
	SAFE_DELETE(Busp);
}

void Shmob::onCollisionStay(Object* obj)
{
}

void Shmob::onCollisionExit(Object* obj)
{
}
