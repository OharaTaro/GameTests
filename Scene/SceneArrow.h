#pragma once
#include "SceneBase.h"
#include "DxLib.h"

class SceneArrow : public SceneBase
{
public:
	SceneArrow();
	virtual ~SceneArrow() {}


	virtual void Init() override;
	virtual void End() override;

	virtual SceneBase* Update() override;
	virtual void Draw() override;

private:
	void DrawGrid() const;
	void CreateRandomVec();

private:
	int m_arrowHandle;

	// ランダムなベクトル生成
	int m_interval;
	VECTOR m_randVec;
};

