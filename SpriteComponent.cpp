#include "SpriteComponent.h"
#include "Game.h"
#include "Actor.h"
#include "Dxlib.h"

SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
	:Component(owner), mOwner(owner), mImg(-1), mDrawOrder(drawOrder)
{
	mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw()
{
	VECTOR2 pos = mOwner->GetPosition();
	float scaleW = mOwner->GetScale().x;
	float scaleH = mOwner->GetScale().y;

	DrawExtendGraph(pos.x, pos.y,
		pos.x + scaleW, pos.y + scaleH, mImg, true);
}

void SpriteComponent::SetImage(int img)
{
	mImg = img;
}
