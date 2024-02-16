#include "pch.h"
#include "TimeBar.h"
#include "Utils.h"

TimeBar::TimeBar(const std::string& name) : GameObject(name)
{
}

TimeBar::~TimeBar()
{
}

void TimeBar::Init()
{
	_timeBar.setSize(_timeBarSize);
	_timeBar.setFillColor(sf::Color::Red);
	Utils::SetOrigin(_timeBar, Origins::MC);
	_timeBar.setPosition(1920 / 2, 1080 - 80);

	_outTimeSoundBuffer.loadFromFile("sound/out_of_time.wav");
	_outTimeSound.setBuffer(_outTimeSoundBuffer);
}

void TimeBar::Release()
{

}

void TimeBar::Reset()
{
	_isDead = false;
	_timeBarCurrentSize.x = 400;
	SetActive(true);
}

void TimeBar::AddHp()
{
	if (_timeBarCurrentSize.x + 50 < 400)
	{
		_timeBarCurrentSize.x += 50;
	}
}

void TimeBar::Update(float dt)
{
	if (_timeBarCurrentSize.x < 0)
	{
		_timeBarCurrentSize.x = 0;
		_isDead = true;
		PlayTimeOutSound();
	}
	else
	{
		_timeBarCurrentSize.x += _timeBarSpeed * dt;
		_timeBar.setSize(_timeBarCurrentSize);
	}

}

void TimeBar::Draw(sf::RenderWindow& window)
{
	window.draw(_timeBar);
}

void TimeBar::PlayTimeOutSound()
{
	_outTimeSound.play();
}
