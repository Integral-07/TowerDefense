
#include "tower.h"
#include"SpriteComponent.h"
#include"Chara.h"
#include "key.h"
#include "CharactorProperty.h"

Tower::Tower(Game* game) : Actor(game), mGame(game),mInterval(0.0f), mTimer(0.0f){

	auto sc = new SpriteComponent(this);
	sc->SetImage(LoadGraph("path"));

	//mMove = new MoveComponent(this, 50);
	//mRect = new RectCmoponent(this, 110);
}

void Tower::UpdateActor() {

}

void Tower::ActorInput() {

	if (KeyClick(KEY_INPUT_RETURN)) {

		//auto chara = new Chara(mGame, );
	}
}
