#pragma once
#include "SpriteGo.h"

class Player : public SpriteGo
{


public:
	Player(const std::string& name = "");

	void Update(float dt) override;
	void Reset() override;
	void Init() override;
	void Release() override;
	void Draw(sf::RenderWindow& window);
	Sides MoveLeft();
	Sides MoveRight();

	void Dead();
	Sides GetSides();
	
	sf::Sprite _axe;

	Sides _currentSide = Sides::LEFT;

private:
	std::string _playerTextureId = "graphics/player.png";
	std::string _axeTextureId = "graphics/axe.png";
	std::string _deadTextureId = "graphics/rip.png";
};

