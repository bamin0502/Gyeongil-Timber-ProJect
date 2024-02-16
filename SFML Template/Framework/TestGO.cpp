#include "pch.h"
#include "TestGO.h"

TestGO::TestGO(const std::string& name) : GameObject(name)
{
}

void TestGO::Update(float dt)
{
}

void TestGO::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}
