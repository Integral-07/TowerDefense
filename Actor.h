#pragma once
#include <vector>
#include "Dxlib.h"
#include "VECTOR2.h"

class Actor
{
public:
	enum State {

		EActive, EAttack, EPause, EDead
	};

	Actor(class Game* game);
	virtual ~Actor();

	void ProcessInput();
	virtual void ActorInput() {}

	void Update();
	virtual void UpdateActor() {}

	//getter, setter
	State GetState()const { return mState; }
	void SetState(State state) { mState = state; }

	const VECTOR2& GetPosition() const { return mPosition; }
	void SetPosition(const VECTOR2& pos) { mPosition = pos; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation; }


	class Game* GetGame() { return mGame; }

	void AddComponent(class Component*);
	void RemoveComponent(class Component*);


	void SetScale(const VECTOR2& scale) { mScale = scale; }
	const VECTOR2& GetScale() const{ return mScale; }

	void Damage(int damage);

	int GetCurHp() const { return mCurHp; }
	int GetMaxHp() const { return mMaxHp; }
	void SetMaxHp(int max_hp) { mMaxHp = max_hp; mCurHp = mMaxHp; }

private:

	int mCurHp = 0;
	int mMaxHp = 0;

	State mState;

	VECTOR2 mPosition;
	float mRotation;

	class Game* mGame;

	VECTOR2 mScale;

	std::vector<class Component*> mComponents;
};