#include "pch.h"
#include "SceneDev1.h"
#include "TestGO.h"

SceneDev1::SceneDev1(SceneIds id) : Scene(id)
{

}

SceneDev1::~SceneDev1()
{
}

void SceneDev1::Init()
{
	//ResourceMgr<sf::Font>& fontResMgr = ResourceMgr<sf::Font>::Instance();
	////TestGO* obj = dynamic_cast<TestGO*>(AddGo(new TestGO()));
	//TestGO* obj = new TestGO("Message");
	//obj->text.setFont(*fontResMgr.Get("fonts/KOMIKAP_.ttf"));
	//obj->text.setString("SCENE DEV 1");
	//
	//AddGo(obj);
	////_gameObjects.push_back(obj);
}

void SceneDev1::Release()                                                                                                                                                     
{
}

void SceneDev1::Enter()
{

}

void SceneDev1::Exit()
{
}

void SceneDev1::Update(float dt)
{
    Scene::Update(dt);

 	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SceneMgr::Instance().ChangeScene(SceneIds::SCENEDEV2);
	}       

	if (InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		GameObject* findGo = FindGo("Message");
		findGo->SetActive(!findGo->GetActive());
	}           
}
