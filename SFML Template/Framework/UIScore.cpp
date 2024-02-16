#include "pch.h"
#include "UIScore.h"
#include "TextGo.h"

UIScore::UIScore(const std::string& name) : TextGo(name)
{
}

void UIScore::SetScore(int score)
{
	_score = score;

	text.setString(textFormat + std::to_string(_score));
}

void UIScore::AddScore()
{
	_score += 10;
	
	text.setString(textFormat + std::to_string(_score));
}

void UIScore::Reset()
{
	SetScore(0);
}
