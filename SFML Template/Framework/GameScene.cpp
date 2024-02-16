#include "pch.h"
#include "SpriteGo.h"
#include "BgMoveingGo.h"
#include "BgBeeGo.h"
#include "UIScore.h"
#include "TextGo.h"
#include "UIStart.h"
#include "Framework.h"
#include "TimeBar.h"
#include "Utils.h"
#include "Tree.h"
#include "EffectLog.h"
#include "Player.h"
#include <SFML/Audio.hpp>
#include "GameScene.h"

SceneGame::SceneGame(SceneIds id) : Scene(id) 
{

}

SceneGame::~SceneGame()
{

}

void SceneGame::PlayEffectLog(Sides side)
{
	EffectLog* effectLog = nullptr;

	if (_unUseEffectList.empty())
	{
		effectLog = new EffectLog();
		effectLog->SetTexture("graphics/log.png");
		effectLog->SetOrigin(Origins::BC);
		effectLog->Init();
	}
	else
	{
		effectLog = _unUseEffectList.front();
		_unUseEffectList.pop_front();
	}

	effectLog->SetActive(true);
	effectLog->Reset();
	effectLog->SetPosition(_tree->GetPosition());
	sf::Vector2f velocity(1000.f, -1000.f);

	if (side == Sides::RIGHT)
	{
		velocity.x *= -1.f;
	}

	effectLog->Fire(velocity);

	_useEffectList.push_back(effectLog);
	AddGo(effectLog);
}

void SceneGame::Init()
{
	texResMgr.Load("graphics/background.png");
	texResMgr.Load("graphics/cloud.png");
	texResMgr.Load("graphics/bee.png");
	texResMgr.Load("graphics/tree.png");
	texResMgr.Load("graphics/branch.png");
	texResMgr.Load("graphics/log.png");
	texResMgr.Load("graphics/player.png");
	texResMgr.Load("graphics/axe.png");
	texResMgr.Load("graphics/rip.png");

	// Sound 
	_chopSoundBuffer.loadFromFile("sound/chop.wav");
	_deathSoundBuffer.loadFromFile("sound/death.wav");

	_chopSound.setBuffer(_chopSoundBuffer);
	_deathSound.setBuffer(_deathSoundBuffer);


	fontMgr.Load("fonts/KOMIKAP_.ttf");

	SpriteGo* newSpriteGo = new SpriteGo("BG");
	newSpriteGo->SetTexture("graphics/background.png");

	GameObject* newObj = AddGo(newSpriteGo);

	sf::FloatRect movingBounds({-200.f, 0} ,{ 1920.f + 400.f
		, 600.f});

	BgMoveingGo* newMovingGo1 = new BgMoveingGo("cloud");
	BgMoveingGo* newMovingGo2 = new BgMoveingGo("cloud1");
	BgMoveingGo* newMovingGo3 = new BgMoveingGo("cloud2");
	BgBeeGo* newBee = new BgBeeGo("bee");
	newMovingGo1->SetTexture("graphics/cloud.png");
	newMovingGo2->SetTexture("graphics/cloud.png");
	newMovingGo3->SetTexture("graphics/cloud.png");
	newBee->SetTexture("graphics/bee.png");

	newMovingGo1->SetOrigin(Origins::MC);
	newMovingGo2->SetOrigin(Origins::MC);
	newMovingGo3->SetOrigin(Origins::MC);
	newBee->SetOrigin(Origins::MC);

	//newMovingGo->SetPosition({0.f, 1080.f * 0.5f});
	newMovingGo1->bounds = movingBounds;
	newMovingGo2->bounds = movingBounds;
	newMovingGo3->bounds = movingBounds;
	newBee->bounds = movingBounds;

	AddGo(newMovingGo1);
	AddGo(newMovingGo2);
	AddGo(newMovingGo3);
	AddGo(newBee);

	_tree = new Tree();
	_tree->SetPosition({1920.f / 2 , 900});

	AddGo(_tree);
	
	//UI
	_uiScore = new UIScore("UiScore");
	//uiScore->SetFont("fonts/KOMIKAP_.ttf");
	_uiScore->Set(*fontMgr.Get("fonts/KOMIKAP_.ttf"), "",
		40, sf::Color::White);

	/*UIStart* uiStart = new UIStart("UiStart");
	uiStart->Set(*fontMgr.Get("fonts/KOMIKAP_.ttf"), "",
		55, sf::Color::White);
	uiStart->SetPosition(sf::Vector2f(1920 / 2, 1080 / 2));*/

	AddGo(_uiScore);
	//AddGo(uiStart);

	_uiMsg = new TextGo("Center Message");

	_uiMsg->Set(*fontMgr.Get("fonts/KOMIKAP_.ttf"), 
		"PRESS ENTER TO START!", 55, sf::Color::White);
	_uiMsg->SetPosition({ 1920.f / 2, 1080.f / 2 });
	_uiMsg->SetOrigin(Origins::MC);

	AddGo(_uiMsg);

	// TimeBar
	
	_timeBar = new TimeBar("TimeBar");
	_timeBar->Init();
	
	AddGo(_timeBar);

	// Player

	_player = new Player("Player");
	AddGo(_player);

	for (GameObject* obj : _gameObjects)
	{
		obj->Init();
	}

}

void SceneGame::Release()
{
	Scene::Release();

	_uiScore = nullptr;
	_uiMsg = nullptr;
	_timeBar = nullptr;
}

void SceneGame::Enter()
{
	Scene::Enter();
	SetStatus(Status::AWAKE);
}

void SceneGame::Exit()
{
	FRAMEWORK.SetTimeScale(1.f);
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);

	if (_timeBar->_isDead && _currStatus != Status::GAMEOVER)
	{
		_timeBar->SetActive(false);
		SetStatus(Status::GAMEOVER);
	}

	if (!_timeBar->_isDead && InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		_timeBar->AddHp();
	}

	switch (_currStatus)
	{
		case SceneGame::Status::AWAKE:
			UpdateGameAwake(dt);
			break;
		case SceneGame::Status::GAME:
			UpdateGame(dt);
			break;
		case SceneGame::Status::GAMEOVER:
			UpdateGameOver(dt);
			break;
		case SceneGame::Status::PAUSE:
			UpdatePause(dt);
			break;
	}

}

void SceneGame::UpdateGameAwake(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
		{
			SetStatus(Status::GAME);
		}
}

void SceneGame::UpdateGame(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
		{
			SetStatus(Status::PAUSE);
		}

	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		if (_tree->Chop() == _player->MoveLeft())
		{
			SetStatus(Status::GAMEOVER);
			_player->Dead();
			_deathSound.play();
			return;
		}
		_player->_axe.setScale({ 1.f , 1.f });
		PlayEffectLog(Sides::LEFT);
		_chopSound.play();
		_timeBar->AddHp();
		_uiScore->AddScore();
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::Left))
	{
		_player->_axe.setScale({ 0.f , 0.f });
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		if (_tree->Chop() == _player->MoveRight())
		{
			SetStatus(Status::GAMEOVER);
			_player->Dead();
			_deathSound.play();
			return;
		}
		_player->_axe.setScale({ 1.f , 1.f });
		PlayEffectLog(Sides::RIGHT);
		_chopSound.play();
		_timeBar->AddHp();
		_uiScore->AddScore();
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::Right))
	{
		_player->_axe.setScale({ 0.f , 0.f });
	}

	for (auto it = _useEffectList.begin(); it !=
		_useEffectList.end();)
	{
		auto effectGo = *it;
		if (!effectGo->GetActive()) 
		{
			RemoveGo(effectGo);
			it = _useEffectList.erase(it);
			_unUseEffectList.push_back(effectGo);
		}
		else
		{
			++it;
		}
	}
}

void SceneGame::UpdateGameOver(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
		{
			SetStatus(Status::GAME);
			_timeBar->Reset();
			_player->Reset();
		}
}

void SceneGame::UpdatePause(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
		{
			SetStatus(Status::GAME);
		}
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void SceneGame::SetStatus(Status newStatus)
{
	Status prevStatus = newStatus;
	_currStatus = newStatus;

	switch (_currStatus)
	{
		case SceneGame::Status::AWAKE:
			_uiMsg->SetActive(true);
			_uiMsg->SetString("PRESS ENTER TO START!");
			FRAMEWORK.SetTimeScale(0.f);
			break;
		case SceneGame::Status::GAME:
			_uiMsg->SetActive(false);
			_uiMsg->SetString("");
			FRAMEWORK.SetTimeScale(1.f);
			break;
		case SceneGame::Status::GAMEOVER:
			_uiMsg->SetActive(true);
			_uiMsg->SetString("GAME OVER! PRESS ENTER TO START!");
			FRAMEWORK.SetTimeScale(0.f);
			break;
		case SceneGame::Status::PAUSE:
			_uiMsg->SetActive(true);
			_uiMsg->SetString("PRESS ESC TO RESUME!");
			FRAMEWORK.SetTimeScale(0.f);
			break;
	}
}


