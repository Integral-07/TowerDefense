#include "tower.h"
#include"SpriteComponent.h"
#include "Actor.h"
#include"Chara.h"
#include "key.h"
#include "Enemy.h"
#include "fps.h"
#include "RectComponent.h"
#include "UIResult.h"
#include "Hpbar.h"

Tower::Tower(Game* game, bool am_i_enemy) 
	: Actor(game), mGame(game),mInterval(0.0f), mTimer(0.0f), mAmIEnemy(am_i_enemy){

	if (am_i_enemy) {

		game->SetEnemyTower(this);
	}
	else{

		game->SetAllyTower(this);
	}

	auto sc = new SpriteComponent(this);
	if (am_i_enemy) {

		//sc->SetImage(LoadGraph("./assets/enemy_tower.png"));
	}
	else {

		sc->SetImage(LoadGraph("./assets/ally_tower.png"));
	}

	mInterval = 3;
	//mMove = new MoveComponent(this, 50);
	mRc = new RectComponent(this, 110);
	mRc->SetWidth(100);
	mRc->SetHeight(200);

	//new Hpbar(this);
}

void Tower::UpdateActor() {

	if (mAmIEnemy) {

		mTimer += fps::DeltaTime;
		if (mTimer > mInterval) {

			auto c = mGame->Charas[mCharaIdx];
			auto e = new Enemy(mGame, c);
			e->SetPosition(VECTOR2(-200,550));
			e->SetScale(mGame->Charas[mCharaIdx]->GetAnimSize());
	
			mTimer -= mInterval;
		}

		/*
		if (GetCurHp() <= 0) {

			new UIResult(mGame, true);
		}
		*/
	}

	/*
	else if (GetCurHp() <= 0) {

		new UIResult(mGame, false);
	}
	*/
}

void Tower::ActorInput() {

}
