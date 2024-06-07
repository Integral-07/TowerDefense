#pragma once
#include <vector>
#include "setting.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include "Enemy.h"

class Game
{
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

private:

	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	std::vector<class Actor*> mActors;
	std::vector<class SpriteComponent*> mSprites;
		
	

	enum GameState {

		ETitle, EPaused, EResult
	};

	GameState GetGameState() const { return mGameState; }
	void SetGameState(GameState state) { mGameState = state; }

	bool mUpdatingActors;
	std::vector<class Actor*> mPendingActors; //’Ç‰Á‚ð‰„Šú‚µ‚½Actor

	GameState mGameState;


public:

	void AddEnemy(class Enemy* enemy);
	void RemoveEnemy(class Enemy* enemy);
	std::vector<class Enemy*>& GetEnemies() { return mEnemies; }

private:

	std::vector<class Enemy*> mEnemies;

};

