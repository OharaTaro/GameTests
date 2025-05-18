#pragma once
#include "SceneBase.h"
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

private:
	int m_arrowHandle;
};

