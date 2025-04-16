#pragma once
#include "DxLib.h"

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	void SetModel(int model) { m_model = model; }

	void Init();
	void Update();
	void Draw();

	VECTOR GetPos() const { return m_pos; }

private:
	int m_model;

	VECTOR m_pos;
	VECTOR m_vec;
};

