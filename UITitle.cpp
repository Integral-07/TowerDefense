#include "UITitle.h"
#include "DxLib.h"
#include "Game.h"
#include "BattleScene.h"

UITitle::UITitle(Game* game):UIScreen(game)
{
	game->SetGameState(Game::ETitle);
	mTitleHandle = LoadGraph("./assets/title_back.png");
	mButtonHandle = LoadGraph("./assets/button.png");

	if (CheckSoundMem(game->GetBgmHandle()) == 1) {

		StopSoundMem(game->GetBgmHandle());
	}

	mButtonPosition = VECTOR2(600, 600);
	game->SetElixer(0);
}

void UITitle::Update()
{
}

void UITitle::Draw()
{
	DrawExtendGraph(0, 0, GameWidth, GameHeight, mTitleHandle, 1);
	DrawExtendGraph(mButtonPosition.x, mButtonPosition.y, GameWidth - mButtonPosition.x, GameHeight - 200, mButtonHandle, true);
	SetFontSize(200);
	DrawString(70, 100, "たわ～でぃふぇんす", GetColor(50, 50, 50), true);
	DrawString(700, 650, "START", GetColor(255, 255, 255), false);
	SetFontSize(40);
	DrawString(0, GameHeight - 80, "　開始:[SPACE] 終了:[Q]", GetColor(255, 255, 255));
}

void UITitle::ProcessInput()
{
	// マウスの位置を取得
	POINT MousePoint;
	GetCursorPos(&MousePoint);
	VECTOR2 mousePos(MousePoint.x, MousePoint.y);

	bool range_x = mousePos.x >= mButtonPosition.x && mousePos.x <= GameWidth - mButtonPosition.x;
	bool range_y = mousePos.y >= mButtonPosition.y && mousePos.y <= GameHeight - mButtonPosition.y;
	if (range_x && range_y) {

		mGame->GetUITitle()->CloseMe();
		BattleScene* BS = new BattleScene(mGame);
	}

}
