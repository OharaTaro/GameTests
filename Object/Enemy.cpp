#include "Enemy.h"
#include <cmath>

Enemy::Enemy():
	m_model(-1),
	m_pos{ 0,0,0 },
	m_vec{ 0,0,0 }
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	float distance = GetRand(300) + 400.0f;
	float angle = GetRand(359) * DX_PI_F / 180.0f;
	m_pos.x = cosf(angle) * distance;
	m_pos.y = 0.0f;
	m_pos.z = sinf(angle) * distance;
}

void Enemy::Update()
{
	MV1SetPosition(m_model, m_pos);
}

void Enemy::Draw()
{
	MV1DrawModel(m_model);
}
