#include "DXUT.h"
#include "mob.h"

void mob::move()
{
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
}

void mob::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	collider->SetRange(vPos, 50, 50);
	OBJECT->AddCollsion(collider);
	Destroy = false;
	Speedx = 400;
	Speedy = 500;
}

void mob::Update()
{
	
	this->collider->SetRange(vPos, 192, 200);
	i = ceil(vPos.x / 10);
	j = ceil(vPos.y / 10);

	move();
	 
	if (GAME->map[i][j] == 3)
	{
		isDestroy = true;
	}

}

void mob::Render()
{
	IMAGE->FindImage("mob")->CenterRender(vPos);
}

void mob::Release()
{
	SAFE_DELETE(collider);
}

void mob::onCollisionStay(Object* obj)
{
}

void mob::onCollisionExit(Object* obj)
{
}
