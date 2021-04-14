#include "DXUT.h"
#include "Buboss.h"

void Buboss::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	collider->SetRange(vPos, 12, 8);
	OBJECT->AddCollsion(collider);
	m_image = IMAGE->FindImage("bbt");
}

void Buboss::Update()
{
	this->collider->SetRange(vPos,12, 8);
	vPos += m_dir * 1200 * D_TIME;

 	i = vPos.x;
	j = vPos.y;
	if (GAME->map[i][j] == 1 || GAME->map[i][j] == 3)
	{
		isDestroy = true;
	}
}

void Buboss::Render()
{
	IMAGE->FindImage("bbt")->CenterRender(vPos);
}

void Buboss::Release()
{
	SAFE_DELETE(collider);
}

void Buboss::onCollisionStay(Object* obj)
{
}

void Buboss::onCollisionExit(Object* obj)
{
}
