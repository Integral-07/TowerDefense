#pragma once
#include "Actor.h"
#include "MoveComponent.h"
#include "RectComponent.h"
#include "AnimSpriteComponent.h"
#include "Hpbar.h"
#include "Game.h"

class Chara : public Actor
{
public:
	Chara(Game* game, CharaProperty* chara_property);
	~Chara();

	void UpdateActor()override;
	void ActorInput() override;

	void SetScale(const VECTOR2& scale);
	void SetRectSize(const VECTOR2& rect_size) {
		
		mRc->SetWidth(rect_size.x);
		mRc->SetHeight(rect_size.y);
	}

	void SetDamageInterval(float damage) { mDamageInterval = damage; }
	
	void SetAnimInterval(float whenWalk, float whenAttack) { mAnimInterval_whenWalk = whenWalk; mAnimInterval_whenAttack = whenAttack; }
	float GetAnimInterval_whenWalk() const { return mAnimInterval_whenWalk; }
	float GetAnimInterval_whenAttack() const { return mAnimInterval_whenAttack; }

	void SetAnimId(int id) { mAsc->SetAnimId(id); }

	RectComponent* GetRect()const { return mRc; }


	enum StateId {

		EWait, EWalk, EAttack
	};

private:

	MoveComponent* mMc;
	RectComponent* mRc;
	AnimSpriteComponent* mAsc;
	Hpbar* mHpbar;

	Game* mGame;

	int mAttack;
	float mSpeed;
	int mCost;


	float mAnimInterval_whenWalk;
	float mAnimInterval_whenAttack;

	float mDamageTimer;
	float mDamageInterval;
};

