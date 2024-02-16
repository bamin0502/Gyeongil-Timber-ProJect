#include "pch.h"
#include "BgBeeGo.h"
#include "Utils.h"

BgBeeGo::BgBeeGo(const std::string& name) : SpriteGo(name)
{

}

void BgBeeGo::Update(float dt)
{
	sf::Vector2f ran = Utils::RandomOnUnitCircle();
	SetPosition(position + direction * speed * dt);
	Flip();
	if (position.x < bounds.left || position.x > bounds.left 
		+ bounds.width)
	{
		std::cout << "Out!!" << std::endl;

		Reposition();                 
	}

	deltatime += dt;

	if (deltatime > changeBee)
	{
		ReDirection();
		deltatime = 0.0f;
		changeBee = Utils::RandomValue();
		/*direction.x = Utils::RandomValue() > 0.5f ? 1.f : -1.f;*/
	}
}

void BgBeeGo::Reset()
{
	ReDirection();

	speed = Utils::RandomRange(speedMin, speedMax);
	direction.x = Utils::RandomValue() > 0.5f ? 1.f : -1.f;

	sf::Vector2f newPos;
	newPos.x = Utils::RandomRange(bounds.left, bounds.left + bounds.width);
	newPos.y = Utils::RandomRange(bounds.top, bounds.top + bounds.height);

	SetPosition(newPos);
}

void BgBeeGo::Reposition()
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
}

void BgBeeGo::ReDirection()
{
	direction = Utils::RandomOnUnitCircle();
}

void BgBeeGo::Flip()
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
