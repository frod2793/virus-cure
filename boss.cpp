#include "DXUT.h"
#include "boss.h"
#include "Buboss.h"

void boss::move()
{
	if (GAME->map[i - 1][j] == 1 || GAME->map[i - 1][j] == 3) {
		b_bullet = true;
		Speedx = Speedx * -1;
	}
	if (GAME->map[i + 1][j] == 1 || GAME->map[i + 1][j] == 3) {
		b_bullet = true;
		Speedx = Speedx * -1;
	}
	if (GAME->map[i][j - 1] == 1 || GAME->map[i][j - 1] == 3) {
		b_bullet = true;
		Speedy = Speedy * -1;
	}
	if (GAME->map[i][j + 1] == 1 || GAME->map[i][j + 1] == 3) {
		b_bullet = true;
		Speedy = Speedy * -1;
	}
	vPos.x += -Speedx * D_TIME;
	vPos.y += -Speedy * D_TIME;

}

void boss::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	collider->SetRange(vPos, 192, 200);
	OBJECT->AddCollsion(collider);
	OBJECT->Boss = this;
	Speedx = 300;
	Speedy = 500;
}

void boss::Update()
{
	this->collider->SetRange(vPos, 192, 200);
	i = ceil(vPos.x / 10);
	j = ceil(vPos.y / 10);

	
	move();


	if (b_bullet == true)
	{
		for (int rad = 0; rad < 360; rad = rad + 10)
		{
		OBJECT->AddObject("Bullet", new Buboss(Vector2(cos(D3DXToRadian(rad)), sin(D3DXToRadian(rad)))), vPos, EBULLET);

		}
		b_bullet = false;
	}


}

void boss::Render()
{
	IMAGE->FindImage("Jong")->CenterRender(vPos);
}

void boss::Release()
{
	SAFE_DELETE(collider);
}

void boss::onCollisionStay(Object* obj)
{
}

void boss::onCollisionExit(Object* obj)
{
}
