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
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }

	class Game* GetGame() { return mGame; }

	void AddComponent(class Component*);
	void RemoveComponent(class Component*);
private:
	State mState;

	VECTOR2 mPosition;
	float mRotation;
	float mScale;

	class Game* mGame;

	std::vector<class Component*> mComponents;
};