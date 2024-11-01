#pragma once
#include<functional>
#include"VECTOR2.h"
#include<string>

class Button
{
public:
	Button(const char* name,
		std::function<void()> onClick,
		const VECTOR2& pos, const VECTOR2& dims);
	~Button();

	// Getters/setters
	const std::string& GetName() { return mName; }
	const VECTOR2& GetPosition() const { return mPosition; }
	void SetHighlighted(bool sel) { mHighlighted = sel; }
	bool GetHighlighted() const { return mHighlighted; }

	bool ContainsPoint(const VECTOR2& pt) const;
	void OnClick();
private:
	std::string mName;
	VECTOR2 mPosition;
	VECTOR2 mDimensions;
	bool mHighlighted;
	std::function<void()> mOnClick;
};