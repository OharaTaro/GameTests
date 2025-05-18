#include "game.h"
#include "SceneArrow.h"

SceneArrow::SceneArrow():
	m_arrowHandle(-1),
	m_interval(0),
	m_randVec(VGet(200,0,0))
{
}

void SceneArrow::Init()
{
	// モデルのロード
	m_arrowHandle = MV1LoadModel("data/model/arrow.mv1");

	// カメラ設定
	SetCameraNearFar(10.0f, 2000.0f);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 400, -1000), VGet(0, 200, 0));
	SetupCamera_Perspective(48.0f * DX_PI_F / 180.0f);
}

void SceneArrow::End()
{
	MV1DeleteModel(m_arrowHandle);
}

SceneBase* SceneArrow::Update()
{
	m_interval++;
	if (m_interval >= 120)
	{
		m_randVec.x = GetRand(500) + 10.0f;
		if (GetRand(2))	m_randVec.x *= -1.0f;
		m_randVec.y = GetRand(500) + 10.0f;
		if (GetRand(2))	m_randVec.y *= -1.0f;
		m_randVec.z = GetRand(500) + 10.0f;
		if (GetRand(2))	m_randVec.z *= -1.0f;

		m_randVec = VNorm(m_randVec);
		m_randVec = VScale(m_randVec, 200.0f);

		m_interval = 0;
	}
	return this;
}

void SceneArrow::Draw()
{
	DrawGrid();

//	DrawCapsule3D(VGet(0,0,0), m_randVec, 4.0f, 8, 0xffffff, 0xffffff, true);
	MV1DrawModel(m_arrowHandle);

	DrawString(0,0,"SceneArrow", 0xffffff);
}

void SceneArrow::DrawGrid() const
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
