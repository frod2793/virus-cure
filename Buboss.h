#pragma once
#include "Object.h"
class Buboss :
    public Object
{
public:
    Buboss(Vector2 dir) : m_dir(dir) {};

    Vector2 m_dir;
    int  i =0, j =0;
    texture* m_image=0;
    bool del = false;
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

