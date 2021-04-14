#pragma once
#include "Scene.h"
class test :
    public Scene
{
private:
	
	char text[10] = {"Stage1"};
	int g, h;
	Timer* ENsp;
	float SPpos;
	D3DXCOLOR color;
	float textTime;
public:
    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

