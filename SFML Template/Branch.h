#pragma once
#include "SpriteGo.h"

class Branch : public SpriteGo
{
protected:
	Sides _originalDir = Sides::RIGHT; // ó�� ���� ����
	Sides _side = Sides::NONE;

public:
	Branch(const std::string& name = "");
	virtual ~Branch() = default;

	void Reset() override;
	void SetSide(Sides side);
	sf::Vector2f GetPosition();
	Sides GetSide() const {return _side; }


};

