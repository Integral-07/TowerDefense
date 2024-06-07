#include "AnimSpriteComponent.h"
#include "fps.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
: SpriteComponent(owner, drawOrder), mCurIdx(0), mTimer(0.0f), mInterval(0.0f){
}

void AnimSpriteComponent::AddImage(int img)
{
	mImgs.emplace_back(img);
}

void AnimSpriteComponent::Update()
{
	mTimer += fps::DeltaTime;
	if (mTimer > mInterval) {

		mTimer -= mInterval;
		mCurIdx++;
		mCurIdx %= mImgs.size();
	}
}

void AnimSpriteComponent::Draw()
{
	SpriteComponent::SetImage(mImgs[mCurIdx]);
	SpriteComponent::Draw();
}


