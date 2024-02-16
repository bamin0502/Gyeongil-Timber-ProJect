#include "pch.h"
#include "SpriteGo.h"
#include "Utils.h"

SpriteGo::SpriteGo(const std::string& name) : GameObject(name)
{
}

void SpriteGo::SetTexture(const sf::Texture& texture)
{
	sprite.setTexture(texture);

}

void SpriteGo::SetTexture(const std::string& textureId)
{
	sprite.setTexture(*ResourceMgr<sf::Texture>().Instance().Get(textureId));
}

void SpriteGo::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void SpriteGo::SetPosition(const sf::Vector2f& pos)
{
	//GameObject::SetPosition(pos);
	position = pos;

	sprite.setPosition(pos);
}

void SpriteGo::SetScale(const sf::Vector2f& pos)
{
	sf::Vector2f spriteScale = scale = pos;

	if (isFlipX)
	{
		spriteScale.x = -scale.x;
	}

	if (isFlipY)
	{
		spriteScale.y = -scale.y;
	}

	sprite.setScale(spriteScale);
}

void SpriteGo::SetFlipX(bool flip)
{
	if (isFlipX == flip)
		return;

	isFlipX = flip;
	SetScale(scale);
}

void SpriteGo::SetFlipY(bool flip)
{
	if (isFlipY == flip)
		return;

	isFlipY = flip;
	SetScale(scale);
}

void SpriteGo::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::CUSTOM;
	origin = newOrigin;
	sprite.setOrigin(newOrigin);

}

void SpriteGo::SetOrigin(Origins preset)
{
	if (preset == Origins::CUSTOM)
	{
		// 기본값으로 설정
		preset = Origins::TL;
	}

	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);

}
