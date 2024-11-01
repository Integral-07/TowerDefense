#include "Hpbar.h"
#include "Chara.h"
#include "Enemy.h"

Hpbar::Hpbar(Actor* owner):SpriteComponent(owner)
{
	mBarWidth = 100;
	mBarHeight = 10;
}

void Hpbar::Update()
{

	int maxHp = mOwner->GetMaxHp();
	int curHp = mOwner->GetCurHp();


	// HPŠ„‡‚ğŒvZ
	mHpPercent = static_cast<float>(curHp) / maxHp;
}

void Hpbar::Draw()
{
	int x = mOwner->GetPosition().x;
	int y = mOwner->GetPosition().y;
	DrawBox(x, y, x + mBarWidth, y + mBarHeight, GetColor(255, 255, 255), true);
	DrawBox(x, y, (x + mBarWidth) * mHpPercent, y + mBarHeight, GetColor(100, 100, 100), true);
}
