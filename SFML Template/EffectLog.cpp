#include "pch.h"
#include "EffectLog.h"

EffectLog::EffectLog(const std::string& name) : SpriteGo(name)
{

}

void EffectLog::Fire(const sf::Vector2f v)
{
	_velocity = v;
	_timer = 0.f;
}

void EffectLog::Update(float dt)
{
	_timer += dt;
	if (_timer > _duration)
	{
		SetActive(false);
		return;
	}
	
	_velocity += _gravity * dt;

	SetPosition(position + _velocity * dt);
}
