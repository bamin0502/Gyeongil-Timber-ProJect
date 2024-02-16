#include "pch.h"
#include "Scene.h"
#include "ResourceMgr.h"

Scene::Scene(SceneIds id) : _id(id) , 
	texResMgr(ResourceMgr<sf::Texture>().Instance()) , 
	fontMgr(ResourceMgr<sf::Font>().Instance())
{
}

void Scene::Release()
{
	for (auto& obj : _gameObjects)
	{
		delete obj;
	}
	_gameObjects.clear();
}

void Scene::Enter()
{
	for (auto obj : _gameObjects)
	{
		obj->Reset();
	}
}

void Scene::Update(float dt)
{
	for (auto& obj : _gameObjects)
	{
		if(obj->GetActive())
			obj->Update(dt);
	}
}

void Scene::Draw(sf::RenderWindow& window)
{
	for (auto& obj : _gameObjects)
	{
		if(obj->GetActive())
			obj->Draw(window);
	}  
}

GameObject* Scene::FindGo(const std::string& name)
{
	for (auto obj : _gameObjects)
	{
		if (obj->name == name)
		{
			return obj;
		}
	}

	return nullptr;
}

bool Scene::FindGoAll(const std::string& name, 
	std::list<GameObject*>& list)
{
	bool isFind = false;
	// list.clear();
	for (auto obj : _gameObjects)
	{
		if (obj->name == name)
		{
			list.push_back(obj);
			isFind = true;
		}
	}

	return isFind;
}

GameObject* Scene::AddGo(GameObject* obj)
{
	if (std::find(_gameObjects.begin(), _gameObjects.end()
		, obj) == _gameObjects.end())
	{
		_gameObjects.push_back(obj);
		return obj;
	}
	return nullptr;
	
}

void Scene::RemoveGo(GameObject* obj)
{
	_gameObjects.remove(obj);
}
