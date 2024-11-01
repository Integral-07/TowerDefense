#include "UIResult.h"
#include "Game.h"

UIResult::UIResult(Game* game, bool win_flag):UIScreen(game)
{
	game->SetGameState(Game::EResult);

	if (win_flag) {

		SetImg(LoadGraph("./assets/win.png"));
	}
	else {

		SetImg(LoadGraph("./assets/lose.png"));
	}
}

void UIResult::Update()
{
}

void UIResult::Draw()
{
	//DrawBox(400, 400, GameWidth - 400, GameHeight - 400, GetColor(100, 100, 100), true);
	DrawExtendGraph(300, 50, GameWidth - 300, GameHeight - 170, mImgHandle, true);
}
