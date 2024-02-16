#pragma once
#include "GameObject.h"

class TestGO : public GameObject
{
public:
	TestGO(const std::string& name = "");
	void Init() override {};
	void Release() override {};
	void Reset() override {};

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;


public:
	sf::Text text;
};

