#include "DxLib.h"
#include "game.h"
#include "SceneTest.h"

#include "Player.h"
#include "Enemy.h"

namespace
{
	
}

SceneTest::SceneTest():
	m_playerHandle(-1),
	m_enemyHandle(-1)
{
}

void SceneTest::Init()
{
	// モデルのロード
	m_playerHandle = MV1LoadModel("data/model/player.mv1");
	m_enemyHandle = MV1LoadModel("data/model/enemy.mv1");

	m_pPlayer = std::make_shared<Player>();
	m_pPlayer->SetModel(m_playerHandle);
	m_pPlayer->Init();

	m_pEnemy = std::make_shared<Enemy>();
	m_pEnemy->SetModel(m_enemyHandle);
	m_pEnemy->Init();

	// カメラ設定
	SetCameraNearFar(10.0f, 2000.0f);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 400, -1200), VGet(0, 200, 0));
	SetupCamera_Perspective(48.0f * DX_PI_F / 180.0f);

//	SetCameraPositionAndTargetAndUpVec(VGet(0, 1000, 0), VGet(0, 0, 0), VGet(0, 0, 1));
//	SetupCamera_Ortho(2000.0f);
}

void SceneTest::End()
{
	MV1DeleteModel(m_playerHandle);
	MV1DeleteModel(m_enemyHandle);
}

SceneBase* SceneTest::Update()
{
	m_pPlayer->Update();
	m_pEnemy->Update();
	return this;
}

void SceneTest::Draw()
{
	DrawGrid();

	m_pPlayer->Draw();
	m_pEnemy->Draw();

	DrawFormatString(16, 16, 0xffffff, "HP:%d", m_pPlayer->GetHp());
}

void SceneTest::DrawGrid() const
{
	for (int z = -500; z <= 500; z += 100)
	{
		DrawLine3D(VGet(-500, 0, z), VGet(500, 0, z), 0xff0000);
	}

	for (int x = -500; x <= 500; x += 100)
	{
		DrawLine3D(VGet(x, 0, -500), VGet(x, 0, 500), 0x0000ff);
	}
}

