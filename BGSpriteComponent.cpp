#include "BGSpriteComponent.h"
#include "setting.h"
#include "fps.h"
#include "Dxlib.h"

BGSpriteComponent::BGSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder), mScrollSpeed(0.0f)
{
}

BGSpriteComponent::~BGSpriteComponent(){
}

void BGSpriteComponent::AddImage(int img) {

	Bg bg;
	bg.img = img;
	bg.px = mBg.size() * GameWidth;

	mBg.emplace_back(bg);
}

void BGSpriteComponent::Update() {

	for (int i = 0; i < mBg.size(); i++) {

		mBg[i].px -= mScrollSpeed * fps::DeltaTime;
		if (mBg[i].px < -GameWidth) {

			mBg[i].px += GameWidth * mBg.size() + 1;
		}
	}
}

void BGSpriteComponent::Draw(){

	for (int i = 0; i < mBg.size(); i++) {

		DrawGraph(mBg[i].px, 0, mBg[i].img, true);
	}
}
