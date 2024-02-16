#include "pch.h"
#include "SceneMgr.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
#include "GameScene.h"

SceneMgr::~SceneMgr()
{
	Release();
}

void SceneMgr::Init() // 초기화 부분
{
	Release();
	_scenes.push_back(new SceneDev1(SceneIds::SCENEDEV1));
	_scenes.push_back(new SceneDev2(SceneIds::SCENEDEV2));
	_scenes.push_back(new SceneGame(SceneIds::SCENEGAME));

	for (auto scene : _scenes)
	{
		scene->Init();
	}

	currentScene = startScene;
	_scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : _scenes)
	{
		scene->Release();
		delete scene;
	}
	_scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	_scenes[(int)currentScene]->Exit();
	currentScene = id;
	_scenes[(int)currentScene]->Enter();
}

void SceneMgr::Update(float dt)
{
	_scenes[(int)currentScene]->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	_scenes[(int)currentScene]->Draw(window);
}
