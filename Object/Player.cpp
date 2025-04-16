#include "Player.h"
#include "Pad.h"

namespace
{
	constexpr float kJumpPower = 16.0f;
	constexpr float kGravity = -0.5f;

	constexpr float kMoveAccel = 1.0f;
	constexpr float kMoveDecRate = 0.80f;

	constexpr int kDefaultHp = 50;
}

Player::Player():
	m_model(-1),
	m_pos{ 0,0,0 },
	m_vec{ 0,0,0 },
	m_hp(kDefaultHp)
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
	m_pos = VAdd(m_pos, m_vec);
	
//	m_vec = VScale(m_vec, kMoveDecRate);
	m_vec.x *= kMoveDecRate;
	m_vec.z *= kMoveDecRate;

	if (isJumping())
	{
		m_vec.y += kGravity;
	}
	else
	{
		m_vec.y = 0.0f;
		m_pos.y = 0.0f;
	}

	if (Pad::isPress(PAD_INPUT_LEFT))
	{
		m_vec.x -= kMoveAccel;
	}
	if (Pad::isPress(PAD_INPUT_RIGHT))
	{
		m_vec.x += kMoveAccel;
	}
	if (Pad::isPress(PAD_INPUT_UP))
	{
		m_vec.z += kMoveAccel;
	}
	if (Pad::isPress(PAD_INPUT_DOWN))
	{
		m_vec.z -= kMoveAccel;
	}
	if (!isJumping())
	{
		if (Pad::isTrigger(PAD_INPUT_1))
		{
			m_vec.y = kJumpPower;
		}
	}
	MV1SetPosition(m_model, m_pos);
}

void Player::Draw()
{
	MV1DrawModel(m_model);
}

bool Player::isJumping() const
{
	return (m_pos.y > 0.0f);
}
