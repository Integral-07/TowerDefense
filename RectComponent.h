#pragma once
#include "Component.h"
#include "VECTOR2.h"

class RectComponent : public Component
{
public:
	RectComponent(Actor* owner, int order);
	const VECTOR2& GetCenter() const;

	void Update() override;
	void SetWidth(float w) { mWidth = w; }
	void SetHeight(float h) { mHeight = h; }
	float GetWidth() const { return mWidth; }
	float GetHeight() const { return mHeight; }

private:
	float mWidth, mHeight;
};

bool Intersect(const RectComponent* a, const RectComponent* b);