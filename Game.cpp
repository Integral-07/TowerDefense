#include <algorithm>
#include "Game.h"
#include "BGSpriteComponent.h"
#include "Dxlib.h"
#include "iter.h"
#include "fps.h"
#include "Chara.h"
#include "UIPause.h"
#include "Key.h"
#include "UITitle.h"
#include "BattleScene.h"

bool Game::Initialize()
{
    if (DxLib_Init() == -1) {

        return false;
    }


    int mElixer = 100;
    int mElixerGenSpeed = 700000000;

    mTitle = new UITitle(this);
    fps::initDeltaTime();
    mBgmHandle = LoadSoundMem("./assets/music/bgm.mp3");
    KeyInit();
    return true;
}

void Game::RunLoop()
{
    while (ProcessMessage() == 0 && mGameState != EQuit) {

        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }


}

void Game::Shutdown()
{
    while (!mActors.empty()) {

        mActors.pop_back();
    }
}

void Game::AddActor(Actor* actor)
{
    if (mUpdatingActors) {

        mPendingActors.emplace_back(actor);
    }
    else {

        mActors.emplace_back(actor);
    }
}

void Game::AddSprite(SpriteComponent* sprite)
{
    int myDrawOrder = sprite->GetDrawOrder();
    auto iter = mSprites.begin();
    for (; iter != mSprites.end(); iter++) {

        if (myDrawOrder < (*iter)->GetDrawOrder()) {

            break;
        }
    }

    mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
    auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
    mSprites.erase(iter);
}

void Game::PushUI(UIScreen* uiScreen)
{
    mUIStack.emplace_back(uiScreen);
}

void Game::RemoveAllUIs()
{
    while (!mUIStack.empty()) {

        mUIStack.pop_back();
    }
}

void Game::RemoveActor(Actor* actor)
{
    auto iter = std::find(mActors.begin(), mActors.end(), actor);
    if (iter != mActors.end()) {

        std::iter_swap(iter, mActors.end() - 1);
        mActors.pop_back();
    }
}

void Game::RemoveAllActors()
{
    for (auto actor : mActors){

        actor->SetState(Actor::EDead);
    }
}

void Game::ProcessInput()
{
    if (mGameState == EPlay)
    {
        mUpdatingActors = true;
        for (auto actor : mActors)
        {
            actor->ProcessInput();
        }
        mUpdatingActors = false;

        //Pause
        if (KeyClick(KEY_INPUT_SPACE))
        {
            new UIPause(this);
        }

        //Title back
        if (KeyClick(KEY_INPUT_ESCAPE)) {

            delete mBScene;
            mTitle = new UITitle(this);
        }
    }
    else if (mGameState == ETitle) {

        if (KeyClick(KEY_INPUT_SPACE)) {

            mTitle->CloseMe();
            mBScene = new BattleScene(this);
        }

        if (KeyClick(KEY_INPUT_Q)) {

            SetGameState(EQuit);
        }
    }
    else if (mGameState == EResult) {

        if (KeyClick(KEY_INPUT_SPACE)) {

            delete mBScene;
            mBScene = new BattleScene(this);
        }
        
        if (KeyClick(KEY_INPUT_ESCAPE)) {

            delete mBScene;
            mTitle = new UITitle(this);
        }
    }
    else if (!mUIStack.empty())
    {
        mUIStack.back()->ProcessInput();
    }

    KeyUpdate();
}

void Game::UpdateGame()
{
    fps::setDeltaTime();

    if (mGameState == EPlay)
    {
        if (mElixerGenSpeed > mCurTime) {

            mCurTime += fps::DeltaTime;
        }
        else {

            mCurTime = 0;
            SetElixer(GetElixer() + 1);
        }
        // mActors更新(更新中にnewされたActorはmPendingActorsに追加される)
        mUpdatingActors = true;
        for (auto actor : mActors)
        {
            actor->Update();
        }
        mUpdatingActors = false;

        // 追加を延期したActorをmActorsに追加する
        for (auto pending : mPendingActors)
        {
            mActors.emplace_back(pending);
        }
        mPendingActors.clear();

        // Dead状態のActorを直下のdeadActorsに抽出する
        std::vector<Actor*> deadActors;
        for (auto actor : mActors)
        {
            if (actor->GetState() == Actor::EDead)
            {
                deadActors.emplace_back(actor);
            }
        }
        // deadActorsを消去する(mActorsからも取り除かれる)
        for (auto actor : deadActors)
        {
            delete actor;
        }
    }
    else if (mGameState == ETitle) {

    }

    // UI更新
    for (auto ui : mUIStack)
    {
        if (ui->GetState() == UIScreen::EActive)
        {
            ui->Update();
        }
    }
    // UIのdelete
    auto iter = mUIStack.begin();
    while (iter != mUIStack.end())
    {
        if ((*iter)->GetState() == UIScreen::EClosing)
        {
            delete* iter;
            iter = mUIStack.erase(iter);
        }
        else
        {
            ++iter;
        }
    }

    //ゲーム終了
    if (mGameState == EQuit)
    {
        Shutdown();
    }
}

void Game::GenerateOutput()
{
   
   for (auto sprite : mSprites) {

        sprite->Draw();
    }

   for (auto ui : mUIStack)
   {
       ui->Draw();
   }

   if (mGameState == EPlay) {

        SetFontSize(50);
        DrawFormatString(50,50,GetColor(0,0,0), "Elixer: %d", GetElixer());
   
        SetFontSize(30);
        DrawString(0, GameHeight - 80, "　ポーズ:[SPACE]\n　タイトルに戻る:[ESC]", GetColor(0, 0, 0));
   }
   else if (mGameState == EPaused) {

       SetFontSize(30);
       DrawString(0, GameHeight - 80, "　　再開:[SPACE]\n　タイトルに戻る:[ESC]", GetColor(0, 0, 0));
   }
   else if(mGameState == EResult){

       SetFontSize(30);
       DrawString(0, GameHeight - 80, "　コンティニュー:[SPACE]\n　タイトルに戻る:[ESC]", GetColor(0, 0, 0));
   }


   ScreenFlip();
   
}


void Game::AddEnemy(Enemy* enemy)
{
    mEnemies.emplace_back(enemy);
}

void Game::RemoveEnemy(Enemy* enemy)
{
    auto iter = std::find(mEnemies.begin(), mEnemies.end(), enemy);
    if (iter != mEnemies.end()) {

        std::iter_swap(iter, mEnemies.end() - 1);
        mEnemies.pop_back();
    }
}

void Game::AddAlly(Chara* ally)
{
    mAllies.emplace_back(ally);
}

void Game::RemoveAlly(Chara* ally)
{
    auto iter = std::find(mAllies.begin(), mAllies.end(), ally);
    if (iter != mAllies.end()) {

        std::iter_swap(iter, mAllies.end() - 1);
        mAllies.pop_back();
    }
}
