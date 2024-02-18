#pragma once
#include "TextGo.h"

// SCORE = ??

class UiScore : public TextGo
{
protected:
	std::string textFormat = "SCORE: ";
	int score = 0;

public:
	UiScore(const std::string& name = "");

	void Reset() override;
	int GetScore() const;
	void SetScore(int score);
	void AddScore(int score);
	
};

