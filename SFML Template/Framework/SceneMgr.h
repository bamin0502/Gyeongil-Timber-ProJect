#pragma once
#include "Singleton.h"

class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;
protected:
	std::vector<Scene*> _scenes;

	SceneIds startScene = SceneIds::SCENEGAME;
	SceneIds currentScene;

public:
	SceneMgr() = default;
	virtual ~SceneMgr();

	void Init(); // 积己磊 开且
	void Release(); // 家戈磊 开且

	void ChangeScene(SceneIds id);

	void Update(float dt);
	void Draw(sf::RenderWindow& window);

	SceneMgr(const SceneMgr&) = delete;
	SceneMgr(SceneMgr&&) = delete;

	SceneMgr& operator=(const SceneMgr&) = delete;
	SceneMgr& operator=(SceneMgr&&) = delete;


};

#define SCENE_MGR (SceneMgr::Instance())