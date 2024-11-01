#pragma once
#include "Game.h"

class BattleScene
{
public:
    BattleScene(class Game* game);
    ~BattleScene() {

        mGame->RemoveAllActors();
        mGame->SetElixer(0);
        mGame->RemoveAllUIs();

        StopSoundMem(mGame->GetBgmHandle());
    }

private:

    class Game* mGame;
};

