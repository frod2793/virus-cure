#pragma once
#include "Object.h"
class mob :
    public Object
{private:

    float dx;
    float dy;
    float Speedx;
    float Speedy;
    int i = 0, j = 0;
    bool Destroy = false;
    void move();
public:
    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

