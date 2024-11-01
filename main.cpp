#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetOutApplicationLogValidFlag(FALSE);             //Log.txt���o�͂��Ȃ�
	ChangeWindowMode(TRUE);                           // �E�B���h�E���[�h��ύX
	SetGraphMode(GameWidth, GameHeight, GameColor);
	SetWindowSize(GameWidth, GameHeight);
	SetMainWindowText(GameTitle);
	SetBackgroundColor(0, 0, 0);
	SetWaitVSyncFlag(TRUE);
	SetAlwaysRunFlag(TRUE);

	//SetWindowIconID();�@�A�C�R����������΂ǂ���
	
	SetDrawScreen(DX_SCREEN_BACK); //�_�u���o�b�t�@�����O

	Game game;
	bool success = game.Initialize();

	if (success) {

		game.RunLoop();
	}

	game.Shutdown();

	return 0;
}