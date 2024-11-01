#pragma once
#include "Component.h"


class SpriteComponent :
    public Component
{
public:
    SpriteComponent(class Actor*, int drawOrder = 100);
    ~SpriteComponent();

    virtual void Draw();
    virtual void SetImage(int img);

    int GetDrawOrder() const { return mDrawOrder; }

private:

    Actor* mOwner;
    int mImg;
    int mDrawOrder;
};
