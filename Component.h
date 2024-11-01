#pragma once
#include<vector>

class Component
{
public:
	//updateOrder�����������ɍX�V�����
	Component(class Actor* owner, int updateOrder = 100);
	virtual ~Component();

	//���̃R���|�[�l���g�̍X�V����
	virtual void Update(){}

	virtual void ProcessInput(){}

	int GetUpdateOrder() const { return mUpdateOrder; }
protected:

	class Actor* mOwner;

	int mUpdateOrder;
};
