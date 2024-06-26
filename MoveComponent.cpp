#include "MoveComponent.h"
#include "Actor.h"
#include "fps.h"

MoveComponent::MoveComponent(Actor* owner, int order):Component(owner, order), mOwner(owner), mSpeed(0.0f){
}

void MoveComponent::Update() {

	if (mSpeed != 0.0f) {

		VECTOR2 pos = mOwner->GetPosition();
		pos += mDirection * mSpeed * fps::DeltaTime;
		mOwner->SetPosition(pos);
	}
}