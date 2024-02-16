#include "pch.h"
#include "TextGo.h"
#include "Utils.h"

TextGo::TextGo(const std::string& name) : GameObject(name)
{
}

void TextGo::Set(const sf::Font& texture,const std::string str,
	const int size, const sf::Color color)
{
	SetFont(texture);
	text.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(color);
}

void TextGo::SetString(const std::string& str)
{
	text.setString(str);
	SetOrigin(originPreset);
}

void TextGo::SetFont(const sf::Font& font)
{
	text.setFont(font);
}

void TextGo::SetFont(const std::string& fontId)
{
	text.setFont(*ResourceMgr<sf::Font>::Instance().Get(fontId));
}

void TextGo::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}

void TextGo::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	text.setPosition(position);
}

void TextGo::SetScale(const sf::Vector2f& pos)
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

	text.setScale(spriteScale);
}

void TextGo::SetFlipX(bool flip)
{
	if (isFlipX == flip)
		return;

	isFlipX = flip;
	SetScale(scale);
}

void TextGo::SetFlipY(bool flip)
{
	if (isFlipY == flip)
		return;

	isFlipY = flip;
	SetScale(scale);
}

void TextGo::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::CUSTOM;
	origin = newOrigin;
	text.setOrigin(newOrigin);

}

void TextGo::SetOrigin(Origins preset)
{
	if (preset == Origins::CUSTOM)
	{
		// 기본값으로 설정
		preset = Origins::TL;
	}

	originPreset = preset;
	origin = Utils::SetOrigin(text, originPreset);

}