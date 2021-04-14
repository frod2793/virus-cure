#include "DXUT.h"
#include "Intro.h"

void Intro::Init()
{
	m_sprite = IMAGE->FindImage("back");
	alpha = 255;
    fade = 0;
    timer = new Timer;
    timer->setTimer(10.5f);
}

void Intro::Update()
{
    switch (fade)
    {
    case 0:
        alpha -= 1;

        if (alpha == 0) {

            fade++;
        }
        break;
    case 1:
        alpha += 3;

        if (alpha == 255)
        {
         
          SCENE->ChangeScene("Title");
          
        }
        break;
    
   

    }
		
	
}

void Intro::Render()
{
    IMAGE->FindImage("back")->   CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	IMAGE->FindImage("Jong")->CenterRender(Vector2(WINSIZEX/2,WINSIZEY /2 ));
	m_sprite->CenterRender(Vector2(WINSIZEX / 2, WINSIZEY / 2), 0, { 1,1 }, D3DCOLOR_RGBA(0, 0, 0, alpha));
}

void Intro::Release()
{ 
}
