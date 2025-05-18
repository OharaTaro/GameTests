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

	// �����_���ȃx�N�g������
	int m_interval;
	VECTOR m_randVec;
};

