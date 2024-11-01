#pragma once
#include "UIScreen.h"
class UITitle :
    public UIScreen
{
public:
    UITitle(class Game* game);

    void Update() override;
    void Draw() override;
    void ProcessInput() override;

private:

    int mTitleHandle;
    int mButtonHandle;
    VECTOR2 mButtonPosition;
};

