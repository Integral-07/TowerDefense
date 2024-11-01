#pragma once
#include"Actor.h"
#include "RectComponent.h"
#include "MoveComponent.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

class Enemy : public Actor
{
public:
	Enemy(Game* game, CharaProperty* chara_property);
	~Enemy();

	void UpdateActor()override;
	void ActorInput() override;

	void SetScale(const VECTOR2& scale);
	void SetRectSize(const VECTOR2& rect_size) {

		mRc->SetWidth(rect_size.x);
		mRc->SetHeight(rect_size.y);
	}

	void SetAnimId(int id) { mAsc->SetAnimId(id); }

	RectComponent* GetRect()const { return mRc; }

	enum StateId {

		EWait, EWalk, EAttack
	};

private:

	MoveComponent* mMc;
	RectComponent* mRc;
	AnimSpriteComponent* mAsc;

	Game* mGame;

	float mDamageTimer;
	float mDamageInterval;

	int mAttack;
	float mSpeed;

};

