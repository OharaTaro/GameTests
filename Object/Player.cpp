#include "Player.h"
#include "DxLib.h"

Player::Player():
	m_model(-1)
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
}

void Player::Draw()
{
	MV1DrawModel(m_model);
}
