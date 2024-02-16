#include "pch.h"
#include "GameObject.h"

GameObject::GameObject(const std::string& name) : 
	name(name)
{
}

GameObject::~GameObject()
{
}

void GameObject::Init()
{

}

void GameObject::Release()
{
}

void GameObject::SetOrigin(Origins preset)
{
	if (Origins::CUSTOM == preset)
	{

	}

	originPreset = preset;
	origin = { 0.f, 0.f };
}

void GameObject::Reset()
{
}

void GameObject::Update(float dt)
{
}

void GameObject::Draw(sf::RenderWindow& window)
{
}
