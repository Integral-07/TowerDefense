#include "RectComponent.h"
#include "Actor.h"

RectComponent::RectComponent(Actor* owner, int order)
:Component(owner, order),mWidth(0.0f), mHeight(0.0f){
}

const VECTOR2& RectComponent::GetCenter() const
{
	return mOwner->GetPosition();
}

void RectComponent::Update()
{
	//DrawBox(GetCenter().x, GetCenter().y, GetCenter().x + GetWidth(), GetCenter().y + GetHeight(),GetColor(255, 255, 255), true);
	
	//ScreenFlip();
}

bool Intersect(const RectComponent* a, const RectComponent* b)
{
	VECTOR2 diff = (a->GetCenter() - b->GetCenter());
	float ww = a->GetWidth() / 2 + b->GetWidth() / 2;
	if(std::abs(diff.x) < ww){
	
		float hh = a->GetHeight() / 2 + b->GetHeight() / 2;
		if(std::abs(diff.y) < hh){
		
			return true;
		}
	}	

	return false;
}
