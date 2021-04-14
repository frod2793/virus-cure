#pragma once
#include "Scene.h"
class Intro :
    public Scene
{
private:

    int alpha = 0;
    texture* m_sprite;
    Timer* timer ;
    int fade = 0;
public:
    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

