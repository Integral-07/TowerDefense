#include "AnimSpriteComponent.h"
#include "fps.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
: SpriteComponent(owner, drawOrder), mCurIdx(0), mTimer(0.0f), mInterval(0.0f), mAnimId(0){
}

void AnimSpriteComponent::AddImage(int img)
{
	mImgs.emplace_back(img);
}

void AnimSpriteComponent::SetAnim(int startIdx, int endIdx, int loopMode)
{
	mAnims.emplace_back(startIdx, endIdx, loopMode);
}

void AnimSpriteComponent::Update()
{
	//�A�j���[�V�����؂�ւ����̏�����
	if (mPreAnimId != mAnimId) {

		mCurIdx = mAnims[mAnimId].startIdx;
		mTimer = 0;
		mAnimEnd = false;
	}
	mPreAnimId = mAnimId;

	//SpriteComponent::Update();

	mTimer += fps::DeltaTime;
	if (mTimer > mInterval) {

		mCurIdx++;
		if (mCurIdx > mAnims[mAnimId].endIdx) {

			if (mAnims[mAnimId].loopMode) {

				//���[�v���邽�߂ɃC���f�b�N�X���ŏ��ɖ߂�
				mCurIdx = mAnims[mAnimId].startIdx;
			}

			else {

				//���[�v�����Ȃ��̂ōŌ�̃C���f�b�N�X�̂܂�
				mCurIdx = mAnims[mAnimId].endIdx;
				mAnimEnd = true;
			}
		}

		mTimer -= mInterval;
		//mCurIdx %= mImgs.size();
	}
}

void AnimSpriteComponent::Draw()
{
	SpriteComponent::SetImage(mImgs[mCurIdx]);
	SpriteComponent::Draw();
}



