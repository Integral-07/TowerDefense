#pragma once
#include "Actor.h"
#include "RectComponent.h"

class Window :
    public Actor
{
public:
    
    Window(class Game* game,const char* path, const VECTOR2& rect_size);
    ~Window() override;

    void UpdateActor() override;
    void ActorInput() override;

    const VECTOR2& GetRectSize() { return mRectSize; }

private:

    RectComponent* mRc;

    const VECTOR2& mRectSize;
};

