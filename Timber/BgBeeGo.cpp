#include "pch.h"
#include "BgBeeGo.h"

BgBeeGo::BgBeeGo(const std::string& name)
	: SpriteGo(name)
{
}

void BgBeeGo::Reset()
{
	ReDirection();
}

void BgBeeGo::ReDirection()
{
	direction = Utils::RandomOnUnitCircle();
}

void BgBeeGo::Update(float dt)
{
	timer += dt;

	SetPosition(position + direction * speed * dt);

	if (timer > duration)
	{
		timer = 0.f;
		ReDirection();
	}
	if (direction.x > 0.f)
	{
		sprite.setScale(-1.f, 1.f);
	}
	if (direction.x < 0.f)
	{
		sprite.setScale(1.f, 1.f);
	}
}
