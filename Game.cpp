#include "Game.h"
#include "BGSpriteComponent.h"
#include "Dxlib.h"
#include "iter.h"
#include "fps.h"

bool Game::Initialize()
{
    if (DxLib_Init() == -1) {

        return false;
    }

    auto a = new Actor(this);
    auto bgsc = new BGSpriteComponent(a, 50);
    bgsc->SetScrollSpeed(0);
    bgsc->AddImage(LoadGraph("./assets/bg.png"));

    fps::initDeltaTime();
    return true;
}

void Game::RunLoop()
{
    while (ProcessMessage() == 0) {

        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::Shutdown()
{
    while (!mActors.empty()) {

        delete mActors.back();
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


void Game::RemoveActor(Actor* actor)
{
    auto iter = std::find(mActors.begin(), mActors.end(), actor);
    if (iter != mActors.end()) {

        auto iter_end = mActors.end() - 1;
        iter_swap(iter, iter_end);
        mActors.pop_back();
    }
}

void Game::ProcessInput()
{
    mUpdatingActors = true;
    for (auto actor : mActors) {

        actor->ProcessInput();
    }

    mUpdatingActors = false;
}

void Game::UpdateGame()
{
    fps::setDeltaTime();

    mUpdatingActors = true;
    for (auto actor : mActors) {

        actor->Update();
    }

    mUpdatingActors = false;

    //‰„Šú‚µ‚½Actor‚ğ’Ç‰Á
    for (auto pending : mPendingActors) {

        mActors.emplace_back(pending);
    }

    mPendingActors.clear();


    //EDead‚ÌActor‚ğÁ‹‚·‚é
    std::vector<class Actor*> deadActors;
    for (auto actor : mActors) {

        if (actor->GetState() == Actor::EDead) {

            deadActors.emplace_back(actor);
        }
    }

    for (auto actor : deadActors) {

        delete actor;
    }
}

void Game::GenerateOutput()
{
   
   for (auto sprite : mSprites) {

        sprite->Draw();
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

        auto iter_end = mEnemies.end() - 1;
        iter_swap(iter, iter_end);
        mEnemies.pop_back();
    }
}
