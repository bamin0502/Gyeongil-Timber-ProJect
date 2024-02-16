#pragma once
#include "TextGo.h"

class UIScore : public TextGo
{
protected:
	std::string textFormat = "SCORE = ";
	int _score = 0;
	

public:
	UIScore(const std::string& name = "");

	void SetScore(int score);
	void AddScore();

	void Reset() override;
};

