#pragma once
class Player
{
public:
	Player();
	virtual ~Player();

	void SetModel(int model) { m_model = model; }

	void Init();
	void Update();
	void Draw();

private:
	int m_model;
};

