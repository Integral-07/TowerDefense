#include "InputComponent.h"
#include "Key.h"
#include "VECTOR2.h"
#include "Chara.h"
#include "fps.h"

InputComponent::InputComponent(Actor* owner)
	: MoveComponent(owner),mOwner(owner), mPreFrame(0)
{
	mMouseInterval = 1;
}

void InputComponent::ProcessInput()
{

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		mPreFrame += fps::DeltaTime;
		if (mPreFrame > mMouseInterval) {

			// マウスの位置を取得
			POINT MousePoint;
			GetCursorPos(&MousePoint);
			VECTOR2 mousePos(MousePoint.x, MousePoint.y);

			bool range_x = mousePos.x >= mOwner->GetPosition().x && mousePos.x <= mOwner->GetPosition().x + mOwner->GetScale().x;
			bool range_y = mousePos.y >= mOwner->GetPosition().y && mousePos.y <= mOwner->GetPosition().y + mOwner->GetScale().y;
			if (range_x && range_y) {

				if ((mOwner->GetGame()->GetElixer() - mOwner->GetGame()->Charas[mCharaIdx]->COST >= 0)) {
			
					auto a = new Chara(mOwner->GetGame(), mOwner->GetGame()->Charas[mCharaIdx]);
					a->SetPosition(VECTOR2(mOwner->GetPosition().x, 600));
					a->SetScale(mOwner->GetGame()->Charas[mCharaIdx]->GetAnimSize());
				}
			}

			mPreFrame -= mMouseInterval;
		}
	}

	if (KeyClick(KEY_INPUT_K)) {

		if ((mOwner->GetGame()->GetElixer() - mOwner->GetGame()->Charas[0]->COST >= 0)) {

			auto a = new Chara(mOwner->GetGame(), mOwner->GetGame()->Charas[0]);
			a->SetPosition(mSummonPosition);
			a->SetScale(mOwner->GetGame()->Charas[0]->GetAnimSize());
		}
	}
	else if (KeyClick(KEY_INPUT_W)) {

		if ((mOwner->GetGame()->GetElixer() - mOwner->GetGame()->Charas[1]->COST >= 0)) {

			auto a = new Chara(mOwner->GetGame(), mOwner->GetGame()->Charas[1]);
			a->SetPosition(mSummonPosition);
			a->SetScale(mOwner->GetGame()->Charas[1]->GetAnimSize());
		}
	}
	else if (KeyClick(KEY_INPUT_S)) {

		if ((mOwner->GetGame()->GetElixer() - mOwner->GetGame()->Charas[2]->COST >= 0)) {

			auto a = new Chara(mOwner->GetGame(), mOwner->GetGame()->Charas[2]);
			a->SetPosition(mSummonPosition);
			a->SetScale(mOwner->GetGame()->Charas[2]->GetAnimSize());
		}
	}
}
