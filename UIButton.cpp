#include "UIButton.h"
Button::Button(const char* name, std::function<void()> onClick,
	const VECTOR2& pos, const VECTOR2& dims)
	: mName(name)
	, mOnClick(onClick)
	, mPosition(pos)
	, mDimensions(dims)
	, mHighlighted(false)
{
}

Button::~Button()
{
}

bool Button::ContainsPoint(const VECTOR2& pt) const
{
	bool no =
		pt.x < (mPosition.x - mDimensions.x / 2.0f) ||
		pt.x >(mPosition.x + mDimensions.x / 2.0f) ||
		pt.y < (mPosition.y - mDimensions.y / 2.0f) ||
		pt.y >(mPosition.y + mDimensions.y / 2.0f);
	return !no;
}

void Button::OnClick()
{
	// アタッチされた関数ハンドラがあれば呼び出す。
	if (mOnClick)
	{
		mOnClick();
	}
}