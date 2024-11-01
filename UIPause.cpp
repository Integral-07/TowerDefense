#include "UIPause.h"
#include "Game.h"
#include "key.h"
#include "UIQuit.h"
#include "DxLib.h"

UIPause::UIPause(Game* game)
	:UIScreen(game)
{
	mGame->SetGameState(Game::EPaused);

	mTitle = "Pause";
	mTextSize = 70;

	/*
	AddButton("Resume",
		[this]() {
			CloseMe();
		}
	);

	AddButton("Quit",
		[this]() {
			new UIQuit(mGame);
		}
	);
	*/

	StopSoundMem(mGame->GetBgmHandle());
}

UIPause::~UIPause()
{
	if (mGame->GetGameState() == Game::ETitle) {


	}
	else {

		mGame->SetGameState(Game::EPlay);
		PlaySoundMem(mGame->GetBgmHandle(), DX_PLAYTYPE_LOOP, false);
	}
}

void UIPause::ProcessInput()
{
	UIScreen::ProcessInput();

	if (KeyClick(KEY_INPUT_SPACE))
	{
		CloseMe();
	}
	if (KeyClick(KEY_INPUT_ESCAPE)) {

		CloseMe();
		delete mGame->GetScene();
		UITitle* ui = new UITitle(mGame);
		mGame->SetUITitle(ui);
	}
}

void UIPause::Draw()
{
	//DrawBox(300, 300, GameWidth - 300, GameHeight - 300, GetColor(0,0,0), true);

	UIScreen::Draw();
}