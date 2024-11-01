#include "Actor.h"
#include "Game.h"
#include "Component.h"


Actor::Actor(Game* game)
	:mGame(game), mState(EActive), mRotation(0.0f)
{
	mPosition = VECTOR2(0, 0);
	mScale = VECTOR2(0, 0);
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);

	while (!mComponents.empty())
	{	
		delete mComponents.back();
	}
}

void Actor::ProcessInput()
{
	if (mState == EActive) {

		for (auto component : mComponents) {

			component->ProcessInput();
		}

		ActorInput();
	}
}

void Actor::Update()
{
	if (mState == EActive) {

		for (auto component : mComponents) {

			component->Update();
		}

		UpdateActor();
	}
}

void Actor::AddComponent(Component* component)
{
	//ƒ\[ƒgÏ‚Ý”z—ñ‚Ì‘}“üêŠ‚ð’T‚·
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); iter++) {

		if (myOrder < (*iter)->GetUpdateOrder()) {

			break;
		}
	}

	mComponents.insert(iter, component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end()) {

		mComponents.erase(iter);
	}
}

void Actor::Damage(int damage)
{
	if (mCurHp - damage > 0) {

		mCurHp -= damage;
	}
	else {

		SetState(EDead);
	}
}
