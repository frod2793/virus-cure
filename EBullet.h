#pragma once
#include "Object.h"
class EBullet :
    public Object
{
    int speed;
        int angle;
        int  x,y;
        int PI;
        int i = 0, j = 0;
        Vector2 Dir;
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

