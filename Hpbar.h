#pragma once
#include "SpriteComponent.h"
class Hpbar :
    public SpriteComponent
{
public:

    Hpbar(class Actor* owner);


    void Update() override;
    void Draw() override;
private:

    Actor* mOwner;

    float mHpPercent;

    float mBarWidth;
    float mBarHeight;
};

