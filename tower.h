#pragma once
#include"Actor.h"

class Tower : public Actor{

public:
	Tower(Game* game);
	~Tower(){}

	void UpdateActor() override;
	void ActorInput() override;

private:
		
	Game* mGame;
	float mTimer;
	float mInterval;

	//class MoveComponent* mMc;
	//class RectComponent* mRect;
};
