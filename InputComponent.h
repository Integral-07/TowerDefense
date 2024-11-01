#pragma once
#include "MoveComponent.h"

class InputComponent :
    public MoveComponent
{
public:
    InputComponent(class Actor* owner);

    void ProcessInput() override;

    void SetSummonPosition(const VECTOR2& pos) { mSummonPosition = pos; }

private:

    Actor* mOwner;

    float mPreFrame;
    float mMouseInterval;

    int mCharaIdx = 0;

    VECTOR2 mSummonPosition;
};