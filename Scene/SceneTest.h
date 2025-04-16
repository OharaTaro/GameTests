#pragma once
#include "SceneBase.h"
#include <memory>

class Player;
class Enemy;
class SceneTest : public SceneBase
{
public:
	SceneTest();
	virtual ~SceneTest() {}


	virtual void Init() override;
	virtual void End() override;

	virtual SceneBase* Update() override;
	virtual void Draw() override;

private:
	void DrawGrid() const;

private:
	int m_playerHandle;
	int m_enemyHandle;

	std::shared_ptr<Player> m_pPlayer;
	std::shared_ptr<Enemy> m_pEnemy;
};