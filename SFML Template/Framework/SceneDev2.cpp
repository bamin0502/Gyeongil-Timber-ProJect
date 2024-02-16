#include "pch.h"
#include "SceneDev2.h"
#include "TestGO.h"

SceneDev2::SceneDev2(SceneIds id) : Scene(id)
{

}

SceneDev2::~SceneDev2()
{
}

void SceneDev2::Init()
{
	//ResourceMgr<sf::Font>& fontResMgr = ResourceMgr<sf::Font>::Instance();
	//TestGO* obj = new TestGO();
	//obj->text.setFont(*fontResMgr.Get("fonts/KOMIKAP_.ttf"));
	//obj->text.setString("SCENE DEV 2");
	//_gameObjects.push_back(obj);
}

void SceneDev2::Release()                                                                                                                                                     
{
}

void SceneDev2::Enter()
{
}

void SceneDev2::Exit()
{

}

void SceneDev2::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SceneMgr::Instance().ChangeScene(SceneIds::SCENEDEV1);
	}
}
