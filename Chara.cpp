#include "Chara.h"
#include "AnimSpriteComponent.h"
#include "Game.h"
#include "fps.h"
#include "Enemy.h"
#include "UIResult.h"

Chara::Chara(Game* game, CharaProperty* chara_property) :Actor(game), mGame(game), mDamageTimer(0.0f) {

	mGame->AddAlly(this);

	Actor::SetMaxHp(chara_property->HP);
	mAttack = chara_property->ATTACK;

	mAsc = new AnimSpriteComponent(this);
	mAsc->SetInterval(chara_property->GetAnimInterval_whenWalk());
	for (int i = 0; i < chara_property->IMGS.size(); i++) {

		mAsc->AddImage(chara_property->IMGS[i]);
	}

	for (auto idx : chara_property->GetAnimIdxs()) {

		mAsc->SetAnim(idx.x, idx.y, idx.z);
	}

	mAsc->SetAnimId(EWalk); //‰Šú’l‚ÍEWalk

	mCost = chara_property->COST;

	mMc = new MoveComponent(this);
	mMc->SetSpeed(chara_property->SPEED);
	mSpeed = chara_property->SPEED;
	mMc->SetDirection(VECTOR2(-1 ,0));

	mRc = new RectComponent(this, 300);
	mRc->SetWidth(chara_property->GetRectSize().x);
	mRc->SetHeight(chara_property->GetRectSize().y);

	//mHpbar = new Hpbar(this);

	mAnimInterval_whenWalk = chara_property->GetAnimInterval_whenWalk();
	mAnimInterval_whenAttack = chara_property->GetAnimInterval_wheAttack();

	game->SetElixer(game->GetElixer() - mCost);

	mDamageInterval = chara_property->GetDamageInterval();
}

Chara::~Chara()
{
	mGame->RemoveAlly(this);
}

void Chara::SetScale(const VECTOR2& scale) {

	Actor::SetScale(scale);
}

void Chara::UpdateActor()
{
	mMc->SetSpeed(mSpeed);
	mAsc->SetAnimId(EWalk);
	mAsc->SetInterval(mAnimInterval_whenWalk);

	for (auto enemy : GetGame()->GetEnemies()) {

		if (Intersect(mRc, enemy->GetRect())) {

			mMc->SetSpeed(0);
			mAsc->SetAnimId(EAttack);
			mAsc->SetInterval(mAnimInterval_whenAttack);

			mDamageTimer += fps::DeltaTime;
			if (mDamageTimer > mDamageInterval) {

				enemy->Damage(mAttack);
				mDamageTimer -= mDamageInterval;
			}
			break;
		}
	}

	if (GetPosition().x <= -200) {

		new UIResult(mGame, true);
	}
}

void Chara::ActorInput()
{
}
