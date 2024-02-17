#pragma once
#include "SpriteGo.h"
#include "Scene/SceneCharacterSelect.h"
class ScenePlayer2Mode;
class Tree;

class MultiPlayer : public SpriteGo
{
public:
	sf::Sound sfxChop;
	sf::Sound sfxDeath;

	sf::Sprite spriteAxe;
	sf::Vector2f axeLocalPosition = { -60, -60 };

	Sides playerSide = Sides::RIGHT;
	Sides axeSide = Sides::LEFT;

	Sides side = Sides::RIGHT;
	float offsetPositionX = 300.f;
	bool isAlive = true;
	bool isChopping = true;

	ScenePlayer2Mode* sceneGame;
	Tree* tree;
	const std::string treeName = "";
	SceneCharacterSelect* sceneCharacterSelect;
public:
	MultiPlayer(const std::string& name = "" , 
		const std::string& tree = "");

	virtual ~MultiPlayer() = default;

	
	std::string texIdPlayer = "graphics/player.png";
	std::string texIdAxe = "graphics/axe.png";
	std::string texIdRip = "graphics/rip.png";

	bool IsAlive() const
	{
		return isAlive;
	}
	Sides GetSide() const
	{
		return side;
	}
	void SetSide(Sides s);
	void OnDie();

	virtual void SetPosition(const sf::Vector2f& pos);
	virtual void SetScale(const sf::Vector2f& scale);

	virtual void Init();
	virtual void Release();

	virtual void Reset();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window); 

	void MoveChop(Sides inputSide);
};

