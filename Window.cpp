#include "Window.h"
#include <string>
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Game.h"

Window::Window(Game* game,const char* path, const VECTOR2& rect_size): Actor(game), mRectSize(rect_size)
{
	mRc = new RectComponent(this, 200);
	mRc->SetWidth(GetScale().x);
	mRc->SetHeight(GetScale().y);

	auto sc = new SpriteComponent(this, 300);
	sc->SetImage(LoadGraph(path));

	
	auto ic = new InputComponent(this);
	ic->SetSummonPosition(VECTOR2(game->GetAllyTower()->GetPosition().x, GameHeight - 500));
}

Window::~Window()
{
}

void Window::UpdateActor()
{
}

void Window::ActorInput()
{
}

