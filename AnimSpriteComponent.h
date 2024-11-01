#pragma once
#include "SpriteComponent.h"

class AnimSpriteComponent :
    public SpriteComponent
{
public:
    AnimSpriteComponent(Actor* owner, int drawOrder = 100);
    void AddImage(int img);
    void Update() override;
    void Draw() override;
    void SetInterval(float interval) { mInterval = interval; }

    //�A�j���[�V�����̐؂�ւ��n
    void SetAnim(int startIdx, int endIdx, int loopMode);
    void SetAnimId(int id) { mAnimId = id; }
    int GetAnimId() const { return mAnimId; }
    bool GetAnimEnd() { return mAnimEnd; }

private:
    std::vector<int> mImgs;
    int mCurIdx;
    float mTimer;
    float mInterval;

    //�A�j���[�V�����̐؂�ւ��n
    int mAnimId;
    int mPreAnimId;
    struct Anim
    {
        int startIdx;
        int endIdx;
        int loopMode;
        Anim(int s, int e, int m):startIdx(s), endIdx(e), loopMode(m){}
    };
    
    std::vector<Anim> mAnims;

    //�A�j���[�V�����I���t���O
    bool mAnimEnd;
};

