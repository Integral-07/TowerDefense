#pragma once
#include"Actor.h"
#include "RectComponent.h"
#include "MoveComponent.h"

class Enemy : Actor
{
public:
	Enemy(Game* game);

	void UpdateActor()override;
	void ActorInput() override;

	void Damage(int damage) { mHp -= damage; }

	RectComponent* GetRect()const { return mRc; }

private:

	MoveComponent* mMc;
	RectComponent* mRc;

	int mHp;
	int mAttack;

};

