#pragma once
#include<vector>

class Component
{
public:
	//updateOrderが小さい順に更新される
	Component(class Actor* owner, int updateOrder = 100);
	virtual ~Component();

	//このコンポーネントの更新処理
	virtual void Update(){}

	virtual void ProcessInput(){}

	int GetUpdateOrder() const { return mUpdateOrder; }
protected:

	class Actor* mOwner;

	int mUpdateOrder;
};
