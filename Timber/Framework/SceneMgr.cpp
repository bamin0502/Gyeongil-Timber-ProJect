#include "pch.h"
#include "SceneMgr.h"
#include "SceneGame.h"
#include "./Scene/SceneCharacterSelect.h"
#include "./Scene/SceneGameModeSelect.h"
#include "./Scene/ScenePlayer2Mode.h"
#include "./Scene/SceneTitle.h"

SceneMgr::~SceneMgr()
{
	Release();
}

void SceneMgr::Init()
{
	Release();

	scenes.push_back(new SceneTitle(SceneIds::SCENE_TITLE));
	scenes.push_back(new SceneGameModeSelect(SceneIds::SCENE_GAME_MODE_SELECT));
	scenes.push_back(new SceneCharacterSelect(SceneIds::SCENE_CHARACTER_SELECT));
	scenes.push_back(new SCENE_GAME(SceneIds::SCENE_GAME));
	scenes.push_back(new ScenePlayer2Mode(SceneIds::SCENE_PLAYER_2_MODE));
	
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
