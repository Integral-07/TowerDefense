#include "UIQuit.h"
#include "Game.h"

UIQuit::UIQuit(Game* game)
	:UIScreen(game)
{
	mBackPos.set(GameWidth / 2, 350.0f);
	mTitlePos.set(GameWidth / 2, mBackPos.y - 100);
	mNextButtonPos.set(GameWidth / 2, mTitlePos.y + 70);

	mBackImg = LoadGraph("Assets/DialogBG.png");

	mTitle = "Quit";
	mTitleColor = GetColor(0, 0, 0);
	mTextSize = 30;

	AddButton("OK",
		[this]() {
			mGame->SetGameState(Game::EQuit);
		}
	);

	AddButton("Cancel",
		[this]() {
			CloseMe();
		}
	);
}

UIQuit::~UIQuit()
{
}