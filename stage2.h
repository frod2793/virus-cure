#pragma once
#include "Scene.h"
class stage2 :
    public Scene
{
private:

    char text[10] = { "Stage2" };
	int g, h;
	Timer* ENsp;
	float SPpos;
	D3DXCOLOR color;
	float textTime;
    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

