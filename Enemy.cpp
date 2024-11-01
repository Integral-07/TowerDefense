#include "Enemy.h"
#include "Game.h"
#include "AnimSpriteComponent.h"
#include "Chara.h"
#include "UIResult.h"
#include "fps.h"

Enemy::Enemy(Game* game, CharaProperty* chara_property) :Actor(game), mGame(game), mAttack(0)
{
	game->AddEnemy(this);

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

	mAsc->SetAnimId(EWalk);

	mMc = new MoveComponent(this);
	mMc->SetSpeed(chara_property->SPEED);
	mSpeed = chara_property->SPEED;
	mMc->SetDirection(VECTOR2(1, 0));

	mRc = new RectComponent(this, 300);
	mRc->SetWidth(chara_property->GetRectSize().x);
	mRc->SetHeight(chara_property->GetRectSize().y);

	//new Hpbar(this);

	mDamageInterval = 1;
}

Enemy::~Enemy()
{
	mGame->RemoveEnemy(this);
}

void Enemy::SetScale(const VECTOR2& scale) {

	Actor::SetScale(scale);
}

void Enemy::UpdateActor()
{

	if (GetPosition().x >= mGame->GetAllyTower()->GetPosition().x) {

		new UIResult(mGame, false);
	}

	mMc->SetSpeed(mSpeed);
	mAsc->SetAnimId(EWalk);

	for (auto ally : GetGame()->GetAllies()) {

		if (Intersect(mRc, ally->GetRect())) {

			mMc->SetSpeed(0);
			mAsc->SetAnimId(EAttack);

			mDamageTimer += fps::DeltaTime;
			if (mDamageTimer > mDamageInterval) {

				ally->Damage(mAttack);
				mDamageTimer -= mDamageInterval;
			}
			break;
		}
		else {

			mMc->SetSpeed(mSpeed);
			mAsc->SetAnimId(EWalk);
		}
	}
}

void Enemy::ActorInput()
{
}
