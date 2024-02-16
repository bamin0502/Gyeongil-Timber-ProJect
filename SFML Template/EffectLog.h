#pragma once
#include "SpriteGo.h"
class EffectLog : public SpriteGo
{
protected:
	sf::Vector2f _gravity = { 0.f , 1000.f }; // �߷�
	sf::Vector2f _velocity; // �ӵ�

public:
	// Update , 
	EffectLog(const std::string& name = "");
	virtual ~EffectLog() = default;
	float _duration = 3.f; // 3 ���� ����
	float _timer = 0.f; // 
	void Fire(const sf::Vector2f v); // �ӵ� ����

	void Update(float dt) override;
};

