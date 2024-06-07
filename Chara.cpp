#include "Chara.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

Chara::Chara(Game* game, CharaProperty* chara_property) :Actor(game) {

	mHp = chara_property->HP;
	mAttack = chara_property->ATTACK;

	auto asc = new AnimSpriteComponent(this, 50);
	for (int i = 0; i < chara_property->IMGS.size(); i++) {

		asc->AddImage(chara_property->IMGS[i]);
	}

	mMc = new MoveComponent(this);
	mMc->SetSpeed(chara_property->SPEED);

	mRc = new RectComponent(this, 110);
	mRc->SetHalfW(50);
	mRc->SetHalfH(50);
}

void Chara::UpdateActor()
{
	if (mHp <= 0) {

		SetState(EDead);
	}

	for (auto enemy : GetGame()->GetEnemies()) {

		if (Intersect(mRc, enemy->GetRect())) {

			mMc->SetSpeed(0.0f);
			SetState(EAttack);
		}
		else {

			if (GetState() == EAttack) {

				SetState(EActive);
			}
		}
	}
}

void Chara::ActorInput()
{
}
