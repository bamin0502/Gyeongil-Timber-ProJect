#pragma once
#include "SpriteGo.h"
class EffectLog : public SpriteGo
{
protected:
	sf::Vector2f _gravity = { 0.f , 1000.f }; // 중력
	sf::Vector2f _velocity; // 속도

public:
	// Update , 
	EffectLog(const std::string& name = "");
	virtual ~EffectLog() = default;
	float _duration = 3.f; // 3 초후 삭제
	float _timer = 0.f; // 
	void Fire(const sf::Vector2f v); // 속도 받음

	void Update(float dt) override;
};

