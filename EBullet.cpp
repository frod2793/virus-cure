#include "DXUT.h"
#include "EBullet.h"
#include <math.h>

void EBullet::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	collider->SetRange(vPos, 50, 50);
	OBJECT->AddCollsion(collider);
	
	Vector2 B_Pos = OBJECT->Player->vPos;

	 Dir =Vector2(cosf( vPos.x - B_Pos.x), sinf(vPos.y - B_Pos.y));
	Dir = vPos - Dir;
	D3DXVec2Normalize(&Dir, &Dir);
		
}

void EBullet::Update()
{
	vPos -= Dir * 2;
	
	i = vPos.x;
	j = vPos.y;
	if (GAME->map[i][j] == 1 || GAME->map[i][j] == 3)
	{
		isDestroy = true;
	}
}



void EBullet::Render()
{
	IMAGE->FindImage("bullet")->CenterRender(vPos);
}

void EBullet::Release()
{
}

void EBullet::onCollisionStay(Object* obj)
{
}

void EBullet::onCollisionExit(Object* obj)
{
}
