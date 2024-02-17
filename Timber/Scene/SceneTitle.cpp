#include "pch.h"
#include "SceneTitle.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneTitle::SceneTitle(SceneIds id)
	:Scene(id)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	texResMgr.Load("graphics/starttitle.png");
	fontResMgr.Load("fonts/neodgm.ttf");

	startTitle = new SpriteGo("StartTitle");
	startTitle->SetTexture("graphics/starttitle.png");
	AddGo(startTitle);

	uiText = new TextGo("Start Message");
	uiText->Set(fontResMgr.Get("fonts/neodgm.ttf"), "Press Space to Start!", 100, sf::Color::White);
	uiText->SetPosition({ 1920.f / 2,1080.f - 300 });
	uiText->SetOrigin(Origins::MC);
	AddGo(uiText);
}

void SceneTitle::Release()
{
	Scene::Release();
}

void SceneTitle::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::SCENE_PLAYER_2_MODE);
	}
}

void SceneTitle::Enter()
{
	Scene::Enter();
}

void SceneTitle::Exit()
{
}

void SceneTitle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
