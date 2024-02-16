#pragma once
#include "SpriteGo.h"

class BgMoveingGo : public SpriteGo
{
public:
	BgMoveingGo(const std::string& name = "");

public:
	void Update(float dt) override;

	void Reset() override;
	void Reposition();
	void Flip();

	sf::FloatRect bounds = { 0.f, 0.f, 1920.f, 1080.f };

	sf::Vector2f direction = { 1.0f, 0.f };
	float speed = 100.f;
	float speedMin = 100.f;
	float speedMax = 200.f;

	float deltatime = 0.0f;
	float changeCloud = 1.0f;
};

