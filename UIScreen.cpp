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
	// Game��UIStack�ɒǉ�
	mGame->PushUI(this);
	// �{�^���摜
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
	// �{�^��������Ȃ�
	if (!mButtons.empty())
	{
		// �}�E�X�̈ʒu���擾
		POINT MousePoint;
		GetCursorPos(&MousePoint);
		VECTOR2 mousePos(MousePoint.x, MousePoint.y);
		// �S�{�^���̃`�F�b�N
		for (auto b : mButtons)
		{
			// ���[���I�[�o�[���Ă�����n�C���C�g
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
	//�w�i�摜�\��
	if (mBackImg >= 0)
	{
		DrawExtendGraph(mBackPos.x, mBackPos.y, mBackPos.x + 10, mBackPos.y + 10, mBackImg, true);
	}

	// �^�C�g���\���i������������j
	SetFontSize(mTextSize);
	if (mTitle.c_str())
	{
		DrawFormatString(
			mTitlePos.x - mTitle.length() * mTextSize / 4,//���p�����̂ݑΉ�
			mTitlePos.y + mTextSize / 2,
			mTitleColor,
			mTitle.c_str()
		);
	}

	// �{�^���\���i������������j
	for (auto b : mButtons)
	{
		// �{�^���摜�\��
		int buttonImg = b->GetHighlighted() ? mButtonOnImg : mButtonOffImg;
		VECTOR2 pos = b->GetPosition();
		DrawGraph(pos.x, pos.y, buttonImg, true);
		// �{�^�������\��
		pos.x -= b->GetName().length() * mTextSize / 4;//���p�����̂ݑΉ�
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

	// ���ɒǉ������{�^���̈ʒu���v�Z���Ă����i�摜�̍����{�Ԋu�j
	mNextButtonPos.y += dims.y + 20.0f;
}