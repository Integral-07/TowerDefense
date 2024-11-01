#pragma once
#include "Component.h"
#include"VECTOR2.h"

class MoveComponent :
    public Component
{
public:

    MoveComponent(Actor* owner, int order = 100);

    void ProcessInput(){}
    void Update()override;

    void SetDirection(const VECTOR2& direction) { mDirection = direction; }
    void SetSpeed(float speed) { mSpeed = speed; }
    float GetSpeed() const { return mSpeed; }

private:

    VECTOR2 mDirection = VECTOR2(0, 0);
    float mSpeed;
    Actor* mOwner;
};

