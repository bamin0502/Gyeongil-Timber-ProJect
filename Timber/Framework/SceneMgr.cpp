#include "pch.h"
#include "SceneMgr.h"
#include "SceneGame.h"

SceneMgr::~SceneMgr()
{
	Release();
}

void SceneMgr::Init()
{
	Release();

	scenes.push_back(new SCENE_GAME(SceneIds::SCENE_TITLE));
	scenes.push_back(new SCENE_GAME(SceneIds::SCENE_CHARACTER_SELECT));
	scenes.push_back(new SCENE_GAME(SceneIds::SCENE_GAME_MODE_SELECT));
	scenes.push_back(new SCENE_GAME(SceneIds::SCENE_GAME));
	scenes.push_back(new SCENE_GAME(SceneIds::SCENE_PLAYER_2_MODE));


	for (auto scene : scenes)
	{
		scene->Init();
	}

	currentScene = startScene;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : scenes)
	{
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	// TO-DO: 모든 게임 오브젝트 업데이트 끝난 후에 씬 전환 되도록

	scenes[(int)currentScene]->Exit();
	currentScene = id;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Update(float dt)
{
	scenes[(int)currentScene]->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->Draw(window);
}
