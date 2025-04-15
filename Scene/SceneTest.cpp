#include "DxLib.h"
#include "game.h"
#include "SceneTest.h"


namespace
{
	
}

SceneTest::SceneTest():
	m_playerHandle(-1)
{
}

void SceneTest::Init()
{
	// モデルのロード
	m_playerHandle = MV1LoadModel("data/model/player.mv1");

	// カメラ設定
	SetCameraNearFar(10.0f, 2000.0f);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 400, -1000), VGet(0, 0, 0));
	SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
}

void SceneTest::End()
{
	MV1DeleteModel(m_playerHandle);
}

SceneBase* SceneTest::Update()
{
	
	return this;
}

void SceneTest::Draw()
{
	DrawGrid();

	MV1DrawModel(m_playerHandle);

	DrawString(0,0,"3Dのテスト",0xffffff);
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

	DrawString(0,0,"SceneTest", 0xffffff);
}

