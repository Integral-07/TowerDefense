#pragma once
#include"Actor.h"

class Tower : public Actor{

public:
	Tower(Game* game, bool am_i_enemy);
	~Tower(){}

	void UpdateActor() override;
	void ActorInput() override;

private:
		
	Game* mGame;
	float mTimer;
	float mInterval;

	bool mAmIEnemy;
	//class MoveComponent* mMc;
	class RectComponent* mRc;

	int mCharaIdx = 3;
};
