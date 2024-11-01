#pragma once
#include "UIScreen.h"
class UIResult :
    public UIScreen
{
public:
    UIResult(class Game* game, bool win_flag);


    void Update() override;
    void Draw() override;


    void SetImg(int handle) { mImgHandle = handle; }
    int GetHadnle() const { return mImgHandle; }

private:

    int mImgHandle;
};

