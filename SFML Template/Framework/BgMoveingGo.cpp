#include "pch.h"
#include "BgMoveingGo.h"
#include "Utils.h"

BgMoveingGo::BgMoveingGo(const std::string& name) : 
	SpriteGo(name)
{
}

void BgMoveingGo::Update(float dt)
{
	SetPosition(position + direction * speed * dt);
	Flip();

	if (position.x < bounds.left || position.x > bounds.left 
		+ bounds.width)
	{
		std::cout << "Out!!" << std::endl;
		Reposition();                 
	}

	deltatime += dt;

	if (deltatime > changeCloud)
	{
		deltatime = 0.0f;
		direction.x = Utils::RandomValue() > 0.5f ? 1.f : -1.f;
	}
}

// 구름 초기화
void BgMoveingGo::Reset()
{
	speed = Utils::RandomRange(speedMin, speedMax);
	direction.x = Utils::RandomValue() > 0.5f ? 1.f : -1.f;
	 
	scale.x = Utils::RandomValue() * 2.0f;
	scale.y = Utils::RandomValue() * 2.0f + 0.3;

	//sf::Vector2f newScale = scale;
	//newScale.x = std::abs(newScale.x);

	//if (direction.x < 0)
	//{
	//	newScale.x = -newScale.x;
	//}

	//SetScale(newScale);

	sf::Vector2f newPos;
	sf::Vector2f newScale1(scale.x, scale.y);

	newPos.x = Utils::RandomRange(bounds.left, bounds.left + bounds.width);

	newPos.y = Utils::RandomRange(bounds.top, bounds.top + bounds.height);

	SetPosition(newPos);
	SetScale(newScale1);
	
}

// 경계밖으로 나갔을때 처리
void BgMoveingGo::Reposition()
{
	speed = Utils::RandomRange(speedMin, speedMax);

	sf::Vector2f newPos;

	if (Utils::RandomValue() > 0.5f)
	{
		direction.x = 1.f;
		newPos.x = bounds.left;
	}
	else
	{
		direction.x = -1.f;
		newPos.x = bounds.left + bounds.width;
	}
	
	newPos.y = Utils::RandomRange(bounds.top, bounds.top + bounds.height);

	SetPosition(newPos);

	//sf::Vector2f newScale = scale;
	//newScale.x = std::abs(newScale.x);

	//if (direction.x < 0)
	//{
	//	newScale.x = -newScale.x;
	//}

	//SetScale(newScale);
	
}

void BgMoveingGo::Flip()
{
	if (direction.x > 0)
	{
		sprite.setScale(-std::abs(sprite.getScale().x), sprite.getScale().y);
	}
	else if (direction.x < 0)
	{

		sprite.setScale(std::abs(sprite.getScale().x), sprite.getScale().y);
	}

}
