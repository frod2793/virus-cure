#include "DXUT.h"
#include "playBtn.h"

void playBtn::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	collider->SetRange(vPos, 200, 210);
	OBJECT->AddCollsion(collider);
}

void playBtn::Update()
{
	this->collider->SetRange(vPos, 197, 210);
}

void playBtn::Render()
{
	IMAGE->FindImage("Play")->CenterRender(vPos);

	if (isCo)
	{
		IMAGE->FindImage("Play")->CenterRender(vPos, 0, Vector2(1.2f, 1.2f));
	}
}

void playBtn::Release()
{
	SAFE_DELETE(collider);
}

void playBtn::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case MOUSE:
		isCo = true;
		if (INPUT->KeyDown(VK_LBUTTON))
			SCENE->ChangeScene("test");
		break;
	}
}

void playBtn::onCollisionExit(Object* obj)
{
	isCo = false;
}
