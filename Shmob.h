#pragma once
#include "Object.h"
class Timer;
class Shmob :
    public Object
{private:
    Timer* Busp;

    float dx;
    float dy;
    float Speedx;
    float Speedy;
    int i = 0, j = 0;
    int g, h;
public:
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

