#pragma once
#include <vector>
#include "setting.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include "VECTOR3.h"
#include "UITitle.h"
#include "Tower.h"

class CharaProperty;

class Game
{
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
	void RemoveAllActors();

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	enum SceneId {

		Prolog, Battle, Conversation
	};

	void SetScene(class BattleScene* scene) { mBScene = scene; }
	BattleScene* GetScene()const { return mBScene; }


	// UI
	void PushUI(class UIScreen* uiScreen);
	void RemoveAllUIs();
	enum GameState {

		ETitle, EPlay, EPaused, EQuit, EResult
	};
	GameState GetGameState() const { return mGameState; }
	void SetGameState(GameState state) { mGameState = state; }


	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	void SetUITitle(UITitle* title) { mTitle = title; }
	UITitle* GetUITitle()const { return mTitle; }

	int GetBgmHandle()const { return mBgmHandle; }
private:
	std::vector<class Actor*> mActors;
	std::vector<class SpriteComponent*> mSprites;

	// UI
	std::vector<class UIScreen*>mUIStack;
	GameState mGameState;

	UITitle* mTitle;
	BattleScene* mBScene;

	bool mUpdatingActors;
	std::vector<class Actor*> mPendingActors; //’Ç‰Á‚ð‰„Šú‚µ‚½Actor

	int mBgmHandle;
public:

	void AddEnemy(class Enemy* enemy);
	void RemoveEnemy(class Enemy* enemy);
	std::vector<class Enemy*>& GetEnemies() { return mEnemies; }

	void AddAlly(class Chara* ally);
	void RemoveAlly(class Chara* ally);
	std::vector<class Chara*>& GetAllies() { return mAllies; }
	

	std::vector<CharaProperty*> Charas;


	void SetElixer(int elixer) { mElixer = elixer; }
	int GetElixer() const { return mElixer; }

	void SetAllyTower(Tower* tower) { mAllyTower = tower; }
	void SetEnemyTower(Tower* tower) { mEnemyTower = tower; }

	Tower* GetAllyTower()const { return mAllyTower; }
	Tower* GetEnemyTower()const { return mEnemyTower; }
private:

	std::vector<class Enemy*> mEnemies;
	std::vector<class Chara*> mAllies;

	Tower* mAllyTower;
	Tower* mEnemyTower;

	int mElixer;
	int mElixerGenSpeed;
	int mCurTime;

};

class CharaProperty {

public:
	const char* NAME;
	std::vector<int> IMGS;
	int HP;
	int ATTACK;
	float SPEED;
	int COST;
	float mAnimInterval_whenWalk;
	float mAnimInterval_whenAttack;

	float mDamageInterval;

	VECTOR2 mAnimSize;
	VECTOR2 mRectSize;

	std::vector<VECTOR3> mAnimIdxs;

public:
	CharaProperty(class Game* game, const char* name, int hp, int attack, float speed, int cost) {

		NAME = name; HP = hp; ATTACK = attack; SPEED = speed; COST = cost;
		game->Charas.push_back(this);
	}

	void SetDamageInterval(float interval) { mDamageInterval = interval; }
	float GetDamageInterval() const { return mDamageInterval; }

	void SetRectSize(const VECTOR2& rect_size) { mRectSize = rect_size; }
	VECTOR2 GetRectSize() const { return mRectSize; }

	void SetAnimSize(const VECTOR2& size) { mAnimSize = size; }
	const VECTOR2& GetAnimSize()const { return mAnimSize; }

	const std::vector<VECTOR3>& GetAnimIdxs() { return mAnimIdxs; }

	void SetAnim(int startIdx, int endIdx, int loopMode){
	
		mAnimIdxs.emplace_back(VECTOR3(startIdx, endIdx, loopMode));
	}

	void SetAnimInterval_whenWalk(float interval) { mAnimInterval_whenWalk = interval; }
	float GetAnimInterval_whenWalk ()const { return mAnimInterval_whenWalk; }

	void SetAnimInterval_whenAttack(float interval) { mAnimInterval_whenAttack = interval; }
	float GetAnimInterval_wheAttack()const { return mAnimInterval_whenAttack; }

	void SetImg(int img) { IMGS.push_back(img); }

	const char* GetName() const { return NAME; }
	std::vector<int>& GetImages() { return IMGS; }
	int GetHitPoint() const { return HP; }
	int GetAttack() const { return ATTACK; }
	float GetSpeed() const { return SPEED; }
};