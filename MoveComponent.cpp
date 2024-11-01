#include "MoveComponent.h"
#include "Actor.h"
#include "fps.h"

MoveComponent::MoveComponent(Actor* owner, int order):Component(owner, order), mOwner(owner), mSpeed(0.0f){

}

void MoveComponent::Update() {

	if (mSpeed != 0.0f) {

		VECTOR2 pos = mOwner->GetPosition();
		pos.x += mDirection.x * mSpeed *fps::DeltaTime;
		pos.y += mDirection.y * mSpeed *fps::DeltaTime;
		mOwner->SetPosition(VECTOR2(pos.x, pos.y));
	}
}