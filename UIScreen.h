#pragma once
#include<functional>
#include<string>
#include<vector>
#include"VECTOR2.h"

class UIScreen
{
public:
	UIScreen(class Game* game);
	virtual ~UIScreen();
	// �h���N���X�ŃI�[�o�[���C�h�\
	virtual void ProcessInput();
	virtual void Update() {};
	virtual void Draw();
	// UI�X�e�[�g�B�A�N�e�B�u���A���邩
	enum UIState
	{
		EActive,
		EClosing
	};
	// UI�X�e�[�g��Closing�ɐݒ�
	void CloseMe();
	// UI�X�e�[�g���擾
	UIState GetState() const { return mState; }
	// UI�^�C�g����ݒ�
	void SetTitle(const char* text) { mTitle = text; }
	// �{�^����ǉ�
	void AddButton(const std::string& name, std::function<void()> onClick);
protected:
	class Game* mGame;

	// �X�e�[�g
	UIState mState;

	//�w�i�摜
	int mBackImg;
	VECTOR2 mBackPos;

	//�^�C�g�������Ƃ��̑���
	std::string mTitle;
	unsigned int  mTitleColor;
	VECTOR2 mTitlePos;
	float mTextSize;

	//�{�^���Ƃ��̑���
	std::vector<class Button*> mButtons;
	VECTOR2 mNextButtonPos;
	int mButtonOnImg;
	int mButtonOffImg;

};