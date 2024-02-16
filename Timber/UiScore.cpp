#include "pch.h"
#include "UiScore.h"

UiScore::UiScore(const std::string& name)
	: TextGo(name)
{
}

void UiScore::Reset()
{
	SetScore(0);
}

void UiScore::SetScore(int score)
{
	this->score = score;
	text.setString(textFormat + std::to_string(this->score));
}

void UiScore::AddScore(int score)
{
	this->score += score;
	text.setString(textFormat + std::to_string(this->score));
}
