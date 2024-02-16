#pragma once
#include "TextGo.h"

class UIStart : public TextGo
{
protected:
	std::string textFormat = "Enter To Start";
	int _score = 0;

public:
	UIStart(const std::string& name = "");

	void Reset() override;
};

