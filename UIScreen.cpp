#include "UIScreen.h"
#include "key.h"
#include "Game.h"
#include "UIButton.h"

UIScreen::UIScreen(Game* game)
	:mGame(game)
	, mState(EActive)
	, mBackImg(-1)
	, mTextSize(40)
	, mTitlePos(GameWidth / 2, 100.0f)
	, mNextButtonPos(GameWidth / 2, 170.0f)
{
	// GameのUIStackに追加
	mGame->PushUI(this);
	// ボタン画像
	mButtonOnImg = LoadGraph("Assets/ButtonYellow.png");
	mButtonOffImg = LoadGraph("Assets/ButtonBlue.png");
}

UIScreen::~UIScreen()
{
	for (auto b : mButtons)
	{
		delete b;
	}
	mButtons.clear();
}

void UIScreen::ProcessInput()
{
	// ボタンがあるなら
	if (!mButtons.empty())
	{
		// マウスの位置を取得
		POINT MousePoint;
		GetCursorPos(&MousePoint);
		VECTOR2 mousePos(MousePoint.x, MousePoint.y);
		// 全ボタンのチェック
		for (auto b : mButtons)
		{
			// ロールオーバーしていたらハイライト
			if (b->ContainsPoint(mousePos))
			{
				b->SetHighlighted(true);
				if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
				{
					b->OnClick();
				}
			}
			else
			{
				b->SetHighlighted(false);
			}
		}
	}
}
void UIScreen::Draw()
{
	//背景画像表示
	if (mBackImg >= 0)
	{
		DrawExtendGraph(mBackPos.x, mBackPos.y, mBackPos.x + 10, mBackPos.y + 10, mBackImg, true);
	}

	// タイトル表示（もしあったら）
	SetFontSize(mTextSize);
	if (mTitle.c_str())
	{
		DrawFormatString(
			mTitlePos.x - mTitle.length() * mTextSize / 4,//半角文字のみ対応
			mTitlePos.y + mTextSize / 2,
			mTitleColor,
			mTitle.c_str()
		);
	}

	// ボタン表示（もしあったら）
	for (auto b : mButtons)
	{
		// ボタン画像表示
		int buttonImg = b->GetHighlighted() ? mButtonOnImg : mButtonOffImg;
		VECTOR2 pos = b->GetPosition();
		DrawGraph(pos.x, pos.y, buttonImg, true);
		// ボタン文字表示
		pos.x -= b->GetName().length() * mTextSize / 4;//半角文字のみ対応
		pos.y += mTextSize / 2 - 2;
		DrawFormatString(pos.x, pos.y, GetColor(0,0,0), b->GetName().c_str());
	}
}

void UIScreen::CloseMe()
{
	mState = EClosing;
}

void UIScreen::AddButton(const std::string& name, std::function<void()> onClick)
{
	VECTOR2 dims(10, 10);//getTextureSize(mButtonOnImg);
	Button* b = new Button(name.c_str(), onClick, mNextButtonPos, dims);
	mButtons.emplace_back(b);

	// 次に追加されるボタンの位置を計算しておく（画像の高さ＋間隔）
	mNextButtonPos.y += dims.y + 20.0f;
}