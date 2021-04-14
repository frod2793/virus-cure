#include "DXUT.h"
#include "player.h"
#include "Gmanager.h"
#include "boss.h" 

void player::Init()
{
	collider = new Collider;
	collider->lpGameObject = this;
	collider->SetRange(vPos, 197, 210);
	OBJECT->AddCollsion(collider);
	OBJECT->Player = this;
	
	m_sprite = IMAGE->FindImage("back");
	filledPercent = 0;

}

void player::Update()
{
	r.left = vPos.x - 10;
	r.right = vPos.x + 10;
	r.top = vPos.y - 10;
	r.bottom = vPos.y + 10;
	this->collider->SetRange(vPos, 197, 210);
	if (!LineMove)
		movement();
	else
		LineDraw();
	Vector2 B_Pos = OBJECT->Boss->bPos;
	i = ceil(vPos.x / 10);
	j = ceil(vPos.y / 10); 
	g = ceil(OBJECT->Boss->vPos.x / 10);
	h = ceil(OBJECT->Boss->vPos.y / 10);

	D3DLOCKED_RECT lr;
	m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD);

	DWORD* textureColor = (DWORD*)lr.pBits;
	for (int j = 90; j < 980; ++j) {
		for (int i = 90; i < 1820; ++i) {


			if (GAME->map[i / 10][j / 10] == 3)
			{
				int idx = (j)*m_sprite->info.Width + (i);
				D3DXCOLOR targetPixel = textureColor[idx];
				targetPixel.a = 0;
				targetPixel.r = 0;
				targetPixel.g = 0;
				targetPixel.b = 0;
				textureColor[idx] = targetPixel;
			}
		}
	}

	m_sprite->texturePtr->UnlockRect(0);

	//텍스쳐의 색깔 정보를 불러온다
	creLine();
	inLine();

	/*DleLine();*/

	if (GAME->map[g][h] == 2)
	{
		Init();
		DleLine();
	}

	//if (flood == true && GAME->map[i][j] == 1)
	//{
	//	removeline();
	//	FloodFill(g, h);
	//	change();
	//	removeline();
	//	inLine();
	//	removeTX();

	//	flood = false;
	//}

	if (DXUTIsKeyDown(VK_F5))
	{
	
		SCENE->ChangeScene("endsc"); 
		
		
		
		removeTX();
		for (int j = 90; j < 980; ++j) {
			for (int i = 90; i < 1820; ++i) {
				if (GAME->map[i / 10][j / 10] == 3)
				{

					GAME->map[i / 10][j / 10] = 0;
				}

				if (GAME->map[i / 10][j / 10] == 4)
				{

					GAME->map[i / 10][j / 10] = 0;
				}
				if (GAME->map[i / 10][j / 10] == 1)
				{

					GAME->map[i / 10][j / 10] = 0;
				}
			}
		}
		
	}

	

	if (DXUTIsKeyDown(VK_F4))
	{
		SCENE->ChangeScene("stage2");
		removeTX();
		for (int j = 90; j < 980; ++j) {
			for (int i = 90; i < 1820; ++i) {
				if (GAME->map[i / 10][j / 10] == 3)
				{

					GAME->map[i / 10][j / 10] = 0;
				}

				if (GAME->map[i / 10][j / 10] == 4)
				{

					GAME->map[i / 10][j / 10] = 0;
				}
				if (GAME->map[i / 10][j / 10] == 1)
				{

					GAME->map[i / 10][j / 10] = 0;
				}
			}
		}
	}
}




void player::DleLine()
{

	
		D3DLOCKED_RECT lr;
		m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD);
		DWORD* textureColor = (DWORD*)lr.pBits;

		for (int j = 0; j < 1080; ++j) {
			for (int i = 0; i < 1920; ++i) {

				{
					if (GAME->map[i / 10][j / 10] == 2)
					{
						//NowPer++;
						GAME->map[i / 10][j / 10] = 0;
					}
					if (GAME->map[i / 10][j / 10] == 0)
					{
						int idx = (j)*m_sprite->info.Width + (i);
						D3DXCOLOR targetPixel = textureColor[idx];
						targetPixel.a = 1;
						targetPixel.r = 0;
						targetPixel.g = 0;
						targetPixel.b = 0;
						textureColor[idx] = targetPixel;
					}
				}
			}
			//DrawLine = false;
			vPos = StartPos;
			//DrawTile();
			LineMove = false;

		}
		
		m_sprite->texturePtr->UnlockRect(0);
}

void player::ClearLine()
{
	D3DLOCKED_RECT lr;
	m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD);
	DWORD* textureColor = (DWORD*)lr.pBits;
	for (int j = 0; j < 1080; ++j) {
		for (int i = 0; i < 1920; ++i) {

			if (GAME->map[i / 10][j / 10] == 1 && GAME->map[i + 1][j] == 3 && GAME->map[i - 1][j] == 3)
			{

				int idx = (j)*m_sprite->info.Width + (i);
				D3DXCOLOR targetPixel = textureColor[idx];
				targetPixel.a = 0;
				targetPixel.r = 0;
				targetPixel.g = 0;
				targetPixel.b = 0;
				textureColor[idx] = targetPixel;
			}


		}


	}

	m_sprite->texturePtr->UnlockRect(0);

}

void player::inLine()
{
	D3DLOCKED_RECT lr;
	m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD);
	DWORD* textureColor = (DWORD*)lr.pBits;
	for (int j = 0; j < 1080; ++j) {
		for (int i = 0; i < 1920; ++i) {

			if (GAME->map[i / 10][j / 10] == 1)
			{
				int idx = j * m_sprite->info.Width + i;
				D3DXCOLOR targetPixel = textureColor[idx];
				targetPixel.a = 1;
				targetPixel.r = 0;
				targetPixel.g = 0;
				targetPixel.b = 1;
				textureColor[idx] = targetPixel;
			}
		}
	}
	m_sprite->texturePtr->UnlockRect(0);
}

void player::creLine()
{
	D3DLOCKED_RECT lr;
	m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD);
	DWORD* textureColor = (DWORD*)lr.pBits;
	for (int j = r.top; j < r.bottom; ++j) {
		for (int i = r.left; i < r.right; ++i) {
			if (GAME->map[i / 10][j / 10] == 2)
			{
				int idx = (j)*m_sprite->info.Width + (i);
				D3DXCOLOR targetPixel = textureColor[idx];
				targetPixel.a = 1;
				targetPixel.r = 255;
				targetPixel.g = 0;
				targetPixel.b = 0;
				textureColor[idx] = targetPixel;
			}
		}
	}
	m_sprite->texturePtr->UnlockRect(0);
}

void player::removeline()//테두리로 변경
{
	for (int j = 0; j < 1080; ++j) {
		for (int i = 0; i < 1920; ++i) {

			if (GAME->map[i / 10][j / 10] == 2)
			{
				GAME->map[i / 10][j / 10] = 1;
			}
		}
	}

}

void player::countt()
{
	count = 0;

	for (int j = 0; j < 980 /10; j++)
	{
		for (int i = 0; i < 1820 /10 ; i++)
		{
			if (GAME->map[i][j] == 0)
			{
				count++;
			}
		}
	}
	count = 1820/10  * 980/10  - count;
	filledPercent = 100 / ((float)1820 / 10 * (float)980 / 10) * count;

	if (filledPercent > 80)
	{
		SCENE->ChangeScene("end");
	}
}

void player::removeTX()
{

	D3DLOCKED_RECT lr;
	m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD);
	DWORD* textureColor = (DWORD*)lr.pBits;
	for (int j = 90; j < 980; ++j) {
		for (int i = 90; i < 1820; ++i) {

			if (GAME->map[i / 10][j / 10] == 0)
			{
				int idx = j * m_sprite->info.Width + i;
				D3DXCOLOR targetPixel = textureColor[idx];
				targetPixel.a = 1;
				targetPixel.r = 0;
				targetPixel.g = 0;
				targetPixel.b = 0;
				textureColor[idx] = targetPixel;
			}
		}
	}
	m_sprite->texturePtr->UnlockRect(0);
}

void player::change()
{
	for (int i = 0; i < WINSIZEX / 10; i++)
	{
		for (int j = 0; j < WINSIZEY / 10; j++)
		{
			if (GAME->map[i][j] == 0)
			{
				GAME->map[i][j] = 3;
			}
			if (GAME->map[i][j] == 4)
			{
				GAME->map[i][j] = 0;
			}
			if (GAME->map[i][j] == 2)
			{
				GAME->map[i][j] = 1;

			}
		}
	}
	inLine();

}
void player::FloodFill(int i, int j)
{

	if (GAME->map[i][j] == 0)
	{
	GAME->map[i][j] = 4;
		FloodFill(i + 1, j);
		FloodFill(i, j + 1);
		FloodFill(i - 1, j);
		FloodFill(i, j - 1);
	}
}

void player::Render()
{

	
	m_sprite->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });
	IMAGE->FindImage("MousePoint")->CenterRender(vPos);
	IMAGE->drawText(to_string((int)(filledPercent)) + "%", {960,50}, 50, D3DCOLOR_XRGB(255, 255, 255), false);

	/*for (int j = 0; j < WINSIZEY / 10; j++)
	{
		for (int i = 0; i < WINSIZEX / 10; i++)
		{
			if (GAME->map[i][j] == 4)
			{
				IMAGE->FindImage("MousePoint")->CenterRender({ (float)i * 10, (float)j * 10 });
			}
		}
	}*/
	//0  = 면
	//1 = 태두리
	//2 = 지나간 선
	//3 = 
	//4 = 플러드필 


	/*for  (int i = 0; i  < 192; i++)
	{
		for (int j = 0; j < 108; j++)

		{

		}
	}*/



}


void player::Release()
{
	SAFE_DELETE(collider);

}

void player::onCollisionStay(Object* obj)
{
	switch (obj->m_Tag)
	{
	case EBULLET:
		if(GAME->map[i][j] !=1)
		DleLine();
		break;

	case MOB:
		if (GAME->map[i][j] != 1)
		DleLine();

		break;
	}
	
}

void player::onCollisionExit(Object* obj)
{
}
void player::movement()
{

	if (DXUTIsKeyDown(VK_RIGHT))
	{
		if (vPos.x <= 1820 && GAME->map[i + 1][j] == 1)
		{
			vPos.x += 10;
		}
		if (vPos.x <= 1820 && GAME->map[i + 1][j] == 0)
		{
			if (DXUTWasKeyPressed(VK_SPACE))
			{
				LineMove = true;
				StartPos = vPos;
			}
		}
	}
	else
		if (DXUTIsKeyDown(VK_LEFT))
		{


			if (vPos.x >= 90 && GAME->map[i - 1][j] == 1)
			{
				vPos.x -= 10;
			}
			if (vPos.x >= 90 && GAME->map[i - 1][j] == 0)
			{
				if (DXUTWasKeyPressed(VK_SPACE))
				{
					LineMove = true;
					StartPos = vPos;
				}
			}
		}
		else
			if (DXUTIsKeyDown(VK_UP))
			{

				if (vPos.y >= 90 && GAME->map[i][j - 1] == 1)
				{
					vPos.y -= 10;
				}
				if (vPos.y >= 90 && GAME->map[i][j - 1] == 0)
				{
					if (DXUTWasKeyPressed(VK_SPACE))
					{
						LineMove = true;
						StartPos = vPos;
					}
				}
			}
			else
				if (DXUTIsKeyDown(VK_DOWN))
				{

					if (vPos.y <= 980 && GAME->map[i][j + 1] == 1)
					{
						vPos.y += 10;
					}
					if (vPos.y <= 980 && GAME->map[i][j + 1] == 0)
					{
						if (DXUTWasKeyPressed(VK_SPACE))
						{
							LineMove = true;
							StartPos = vPos;
						}
					}

				}
}

void player::LineDraw()
{
	if (DXUTIsKeyDown(VK_RIGHT)&& GAME->map[i + 1][j] != 2)
	{
		if (vPos.x <= 1820 && GAME->map[i + 1][j] == 0)
		{

			GAME->map[i][j] = 2;
		}
		else if (vPos.x <= 1820 && GAME->map[i + 1][j] == 1)
		{
			GAME->map[i][j] = 2;
			LineMove = false;
			FloodFill(g, h);
			change();
			countt();
			creLine();
		}
		vPos.x += 10;
	}
	else if (DXUTIsKeyDown(VK_LEFT)&&GAME->map[i - 1][j] != 2)
	{
		if (vPos.x >= 90 && GAME->map[i - 1][j] == 0)
		{

			GAME->map[i][j] = 2;
		}
		else if (vPos.x >= 90 && GAME->map[i - 1][j] == 1)
		{
			GAME->map[i][j] = 2;
			LineMove = false;
			FloodFill(g, h);
			change();
			countt();
			creLine();
		}
		vPos.x -= 10;
	}
	else if (DXUTIsKeyDown(VK_UP) && GAME->map[i][j -1] != 2)
	{
		if (vPos.y >= 90 && GAME->map[i][j - 1] == 0)
		{
			GAME->map[i][j] = 2;
		}
		else if (vPos.y >= 90 && GAME->map[i][j - 1] == 1)
		{
			GAME->map[i][j] = 2;
			LineMove = false;
			FloodFill(g, h);
			change();
			countt();
			creLine();
		}
		vPos.y -= 10;
	}
	else if (DXUTIsKeyDown(VK_DOWN) && GAME->map[i][j + 1] != 2)
	{
		if (vPos.y <= 980 && GAME->map[i][j + 1] == 0)
		{
			GAME->map[i][j] = 2;
		}
		else if (vPos.y <= 980 && GAME->map[i][j + 1] == 1)
		{
			GAME->map[i][j] = 2;
			LineMove = false;
			FloodFill(g,h);
			change();
			countt();
			creLine();
		}
		vPos.y += 10;
	}
}

