#include "DXUT.h"
#include "Gmanager.h"

void Gmanager::Init()
{
	m_sprite = IMAGE->FindImage("back");

	m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD);
	DWORD* textureColor = (DWORD*)lr.pBits;
	for (int j = 0; j < 1080; ++j) {
		for (int i = 0; i < 1920; ++i) {
			
				int idx = (j)*m_sprite->info.Width + (i);
				D3DXCOLOR targetPixel = textureColor[idx];
				MainColor = targetPixel;
				textureColor[idx] = targetPixel;
		}
	}
	m_sprite->texturePtr->UnlockRect(0);
}

void Gmanager::Update()
{

	for (int j = 9; j < 981 / 10; j++)
	{
		for (int i = 9; i < 1821 / 10; i++)
		{
			if (i == 90 / 10)
			{
				map[i][j] = 1;
			}
			if (i == 1821 / 10 - 1)
			{
				map[i][j] = 1;
			}
			if (j == 90 / 10)
			{
				map[i][j] = 1;
			}
			if (j == 981 / 10 - 1)
			{
				map[i][j] = 1;
			}
			if (map[i][j] == 1)
			{
				if (map[i + 1][j] == 3 && map[i - 1][j] == 3) {
						map[i][j] = 3;
				}
			}
			if (map[i][j] == 1) 
			{
				if (map[i - 1][j] == 3 && map[i + 1][j] == 3) {
					map[i][j] = 3;
				}
			}
			if (map[i][j] == 1)
			{ 
				if (map[i][j - 1] == 3 && map[i][j + 1] == 3) {
					map[i][j] = 3;
				}
			}
			if (map[i][j] == 1)
			{
				if (map[i][j + 1] == 3 && map[i][j - 1] == 3)
				{
					map[i][j] = 3;
				}
			}
		}
	}
			
		
	//reLine();
		

}

void Gmanager::Release()
{
}

void Gmanager::reLine()
{
	

	m_sprite->texturePtr->LockRect(0, &lr, nullptr, D3DLOCK_DISCARD);
	DWORD* textureColor = (DWORD*)lr.pBits;
	for (int j = r.top; j < r.bottom; ++j) {
		for (int i = r.left; i < r.right; ++i) {

			if (GAME->map[i / 10][j / 10] == 2)
			{
				int idx = (j)*m_sprite->info.Width + (i);
				D3DXCOLOR targetPixel = textureColor[idx];
				targetPixel = MainColor;
				textureColor[idx] = targetPixel;
			}
		}
		m_sprite->texturePtr->UnlockRect(0);
	}
}
