#include "pch.h"
#include "Player.h"
#include "ResourceMgr.h"
#include "Utils.h"

Player::Player(const std::string& name) : SpriteGo(name)
{

}

void Player::Update(float dt)
{

}

void Player::Reset()
{
	sprite.setTexture(*TEXTURE_RES_MGR.Get(_playerTextureId));
	_axe.setScale({ 0.0f , 0.0f });
}

void Player::Init()
{
	Release();
	sprite.setTexture(*TEXTURE_RES_MGR.Get(_playerTextureId));
	Utils::SetOrigin(sprite, Origins::MC);
	sprite.setPosition({ 1920 / 2 - 300 , 800 });
	_axe.setTexture(*TEXTURE_RES_MGR.Get(_axeTextureId));
	_axe.setPosition({1920 / 2 - 180 , 830});
	Utils::SetOrigin(_axe, Origins::MC);
	sprite.setScale(-sprite.getScale().x, sprite.getScale().y);

}
void Player::Release()
{

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(_axe);
}

Sides Player::MoveLeft()
{
	sprite.setScale(-std::abs(sprite.getScale().x), sprite.getScale().y);
	sprite.setPosition({ 1920 / 2 - 300 , 800 });
	_axe.setPosition({1920 / 2 - 180 , 830});
	_currentSide = Sides::LEFT;

	return _currentSide;
}

Sides Player::MoveRight()
{
	sprite.setScale(std::abs(sprite.getScale().x), sprite.getScale().y);
	sprite.setPosition({ 1920 / 2 + 300 , 800 });
	_axe.setPosition({1920 / 2 + 180 , 830});
	_currentSide = Sides::RIGHT;

	return _currentSide;
}

void Player::Dead()
{
	sprite.setTexture(*TEXTURE_RES_MGR.Get(_deadTextureId));
	_axe.setScale({0.f,0.f});
}

Sides Player::GetSides()
{
	return _currentSide;
}


