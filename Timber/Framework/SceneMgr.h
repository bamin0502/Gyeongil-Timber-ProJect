#pragma once
#include "Singleton.h"

class Scene;

class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

protected:
	std::vector<Scene*> scenes;

	SceneIds startScene = SceneIds::SCENE_PLAYER_2_MODE; // 임시 수정
	SceneIds currentScene = startScene;

	SceneMgr() = default;
	virtual ~SceneMgr();

public:
	void Init();
	void Release();

	void ChangeScene(SceneIds id);

	
	//Scene* GetCurrentScene() { return scenes[(int)currentScene]; } 원본
	Scene* GetCurrentScene() { return scenes[0]; } // 임시 수정

	void Update(float dt);
	void Draw(sf::RenderWindow& window);


	SceneMgr(const SceneMgr&) = delete;
	SceneMgr(SceneMgr&&) = delete;
	SceneMgr& operator=(const SceneMgr&) = delete;
	SceneMgr& operator=(SceneMgr&&) = delete;
};

#define SCENE_MGR (SceneMgr::Instance())