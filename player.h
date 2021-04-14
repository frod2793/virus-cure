#pragma once
class player :
    public Object
{
private:
    void movement();
    void LineDraw();
    bool clear = false;
  /*  Vector3 Vec3;
    ID3DXLine * ild3dline;*/
    float filledPercent;
    int i=0;
    int g, h;
    int j=0;
    int count;
    D3DLOCKED_RECT lr;
    DWORD* textureColor;
    D3DXCOLOR targetPixel;
    RECT r;
    texture* m_sprite;
    Vector2 StartPos;

    bool flood = false;
    bool Playhit = false;
    bool line = false;
public:
    void DleLine();
    void ClearLine();
    void inLine();
    void creLine();
    void removeline();
  
    void countt();
    void removeTX();
    void change();
    void FloodFill(int i, int j);
    // Object을(를) 통해 상속됨
    bool LineMove = false;

    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void onCollisionStay(Object* obj) override;
    virtual void onCollisionExit(Object* obj) override;
};

