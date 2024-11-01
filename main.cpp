#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetOutApplicationLogValidFlag(FALSE);             //Log.txtを出力しない
	ChangeWindowMode(TRUE);                           // ウィンドウモードを変更
	SetGraphMode(GameWidth, GameHeight, GameColor);
	SetWindowSize(GameWidth, GameHeight);
	SetMainWindowText(GameTitle);
	SetBackgroundColor(0, 0, 0);
	SetWaitVSyncFlag(TRUE);
	SetAlwaysRunFlag(TRUE);

	//SetWindowIconID();　アイコンつけたければどうぞ
	
	SetDrawScreen(DX_SCREEN_BACK); //ダブルバッファリング

	Game game;
	bool success = game.Initialize();

	if (success) {

		game.RunLoop();
	}

	game.Shutdown();

	return 0;
}