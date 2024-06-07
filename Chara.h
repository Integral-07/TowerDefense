#pragma once
#include "Actor.h"
#include "MoveComponent.h"
#include "RectComponent.h"

struct CharaProperty {

	const char* name;
	std::vector<int> IMGS;
	int HP;
	int ATTACK;
	float SPEED;
};

class Chara : public Actor
{
public:
	Chara(Game* game, CharaProperty* chara_property);

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

