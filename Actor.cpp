#include "Actor.h"
#include "Game.h"
#include "Component.h"


Actor::Actor(Game* game)
	:mGame(game), mState(EActive), mRotation(0.0f), mScale(1.0f)
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
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
	//ソート済み配列の挿入場所を探す
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
	auto iter = std::find(mComponents.begin(), mComponents.end() - 1, component);
	if (iter != mComponents.end()) {

		mComponents.erase(iter);
	}
}
