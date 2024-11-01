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
	// 派生クラスでオーバーライド可能
	virtual void ProcessInput();
	virtual void Update() {};
	virtual void Draw();
	// UIステート。アクティブか、閉じるか
	enum UIState
	{
		EActive,
		EClosing
	};
	// UIステートをClosingに設定
	void CloseMe();
	// UIステートを取得
	UIState GetState() const { return mState; }
	// UIタイトルを設定
	void SetTitle(const char* text) { mTitle = text; }
	// ボタンを追加
	void AddButton(const std::string& name, std::function<void()> onClick);
protected:
	class Game* mGame;

	// ステート
	UIState mState;

	//背景画像
	int mBackImg;
	VECTOR2 mBackPos;

	//タイトル文字とその属性
	std::string mTitle;
	unsigned int  mTitleColor;
	VECTOR2 mTitlePos;
	float mTextSize;

	//ボタンとその属性
	std::vector<class Button*> mButtons;
	VECTOR2 mNextButtonPos;
	int mButtonOnImg;
	int mButtonOffImg;

};