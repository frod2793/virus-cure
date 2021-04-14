#pragma once
#include "Object.h"
class boss :
    public Object
{
public:
    Vector2 size;
    bool b_bullet;
    float dx;
    float dy;
    float Speedx;
    float Speedy;
    int rad;
    void move();
    int i = 0, j = 0;
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

