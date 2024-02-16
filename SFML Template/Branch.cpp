#include "pch.h"
#include "Branch.h"

Branch::Branch(const std::string& name) : SpriteGo(name)
{
}

void Branch::Reset()
{
	SetSide(Sides::NONE);
}

void Branch::SetSide(Sides side)
{
	_side = side;

	switch (_side)
	{
		case Sides::LEFT:
		case Sides::RIGHT:
			SetActive(true);
			SetFlipX(_originalDir != side);
			break;
		default:
			SetActive(false);
	}

	

}

sf::Vector2f Branch::GetPosition()
{
	return sprite.getPosition();
}
