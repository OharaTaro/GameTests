#pragma once
#include "DxLib.h"

class Player
{
public:
	Player();
	virtual ~Player();

	void SetModel(int model) { m_model = model; }

	void Init();
	void Update();
	void Draw();

	VECTOR GetPos() const { return m_pos; }
	int GetHp() const { return m_hp; }

private:
	bool isJumping() const;

private:
	int m_model;

	VECTOR m_pos;
	VECTOR m_vec;

	int m_hp;
};

