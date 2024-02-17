#include "pch.h"
#include "ScenePlayer2Mode.h"
#include "SpriteGo.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "BgMovingGo.h"
#include "BgBeeGo.h"
#include "UiScore.h"
#include "UiTimeBar.h"
#include "Tree.h"
#include "EffectLog.h"
#include "MultiPlayer.h"
#include <map>

ScenePlayer2Mode::ScenePlayer2Mode(SceneIds id) : Scene(id)
{

}

ScenePlayer2Mode::~ScenePlayer2Mode()
{

}

void ScenePlayer2Mode::SetStatus(Status newStatus)
{
	Status prevStatus = currStatus;
	currStatus = newStatus;

	switch (currStatus)
	{
	case Status::Awake:
		timer[LEFT] = duration;
		timer[RIGHT] = duration;

		uiTimeBar[LEFT]->SetValue(timer[LEFT] / duration);
		uiTimeBar[RIGHT]->SetValue(timer[RIGHT] / duration);

		FRAMEWORK.SetTimeScale(0.f);
		uiMsg->SetActive(true);
		uiMsg->SetString("PRESS ENTER TO START!");
		break;

	case Status::Game:
		if (prevStatus == Status::GameOver)
		{
			timer[LEFT] = duration;
			timer[RIGHT] = duration;

			uiTimeBar[LEFT]->SetValue(timer[LEFT] / duration);
			uiTimeBar[RIGHT]->SetValue(timer[RIGHT] / duration);

			player[(int)PLAYER::LEFT_PLAYER]->Reset();
			player[(int)PLAYER::RIGHT_PLAYER]->Reset();

			tree[0]->Reset();
			tree[1]->Reset();

			uiScore[LEFT]->SetScore(0);
			uiScore[RIGHT]->SetScore(0);
		}
		FRAMEWORK.SetTimeScale(1.f);
		uiMsg->SetActive(false);
		uiMsg->SetString("");
		break;
	case Status::GameOver:
		FRAMEWORK.SetTimeScale(0.f);
		uiMsg->SetActive(true);
		for (GameObject* obj : gameObjects)
		{
			obj->Init();
		}
		break;
	case Status::Pause:
		FRAMEWORK.SetTimeScale(0.f);
		uiMsg->SetActive(true);
		uiMsg->SetString("PRESS ESC TO RESUME!");
		break;
	}
}

void ScenePlayer2Mode::PlayEffectLog(Sides side , PLAYER player)
{
	EffectLog* effectLog = nullptr;
	if (unuseEffectList.empty())
	{
		effectLog = new EffectLog();
		effectLog->SetTexture("graphics/log.png");
		effectLog->SetOrigin(Origins::BC);
		effectLog->Init();
	}
	else
	{
		effectLog = unuseEffectList.front();
		unuseEffectList.pop_front();
	}

	effectLog->SetActive(true);
	effectLog->Reset();
	effectLog->SetPosition(tree[(int)player]->GetPosition());

	sf::Vector2f velocity(1000.f, -1000.f);
	if (side == Sides::RIGHT)
	{
		velocity.x *= -1.f;
	}
	effectLog->Fire(velocity);

	useEffectList.push_back(effectLog);
	AddGo(effectLog);
}

void ScenePlayer2Mode::Init()
{
	// **********************FontLoad**********************
	textResMgrLoad();
	fontResMgr.Load("fonts/KOMIKAP_.ttf");

	// *********************SoundLoad**********************
	soundResMgr.Load("sound/out_of_time.wav");
	sfxTimeOver.setBuffer(RES_MGR_SOUND_BUFFER.Get("sound/out_of_time.wav"));

	// ********************Backgorund**********************
	AddGoSpriteLoadTexture("Background", "BG", "graphics/background.png");
	
	sf::FloatRect movingBounds({ -200.f, 0.f }, { 1920.f + 400.f, 600.f });

	// **********************Cloud*************************
	for (int i = 0; i < 3; ++i)
	{
		BgMovingGo* newMovingGo = new BgMovingGo(std::string("Cloud") + std::to_string(i));
		newMovingGo->SetTexture("graphics/cloud.png");
		newMovingGo->SetOrigin(Origins::MC);
		newMovingGo->SetFlipX(true);
		newMovingGo->bounds = movingBounds;
		AddGo(newMovingGo);
	}

	// ***********************Tree*************************
	tree.push_back(new Tree("TreeLeft"));
	tree.push_back(new Tree("TreeRight"));

	tree[LEFT]->SetPosition({470.f , 900.f});
	tree[RIGHT]->SetPosition({1450.f, 900.f});

	AddGo(tree[LEFT]);
	AddGo(tree[RIGHT]);

	// **********************Player************************
	player.push_back(new MultiPlayer("PlayerLeft" , "TreeLeft"));
	player.push_back(new MultiPlayer("PlayerRight", "TreeRight"));

	AddGo(player[(int)PLAYER::LEFT_PLAYER]);
	AddGo(player[(int)PLAYER::RIGHT_PLAYER]);

	// ***********************uiMsg************************
	uiMsg = new TextGo("Center Message");
	uiMsg->Set(fontResMgr.Get("fonts/KOMIKAP_.ttf"),
		"PRESS ENTER TO START!", 75, sf::Color::White);
	uiMsg->SetPosition({ 1920.f / 2, 1080.f / 2 });
	uiMsg->SetOrigin(Origins::MC);
	AddGo(uiMsg);

	// **********************uiScore***********************
	uiScore[LEFT] = new UiScore("LeftScore");
	uiScore[RIGHT] = new UiScore("RIGHTScore");

	uiScore[LEFT]->Set(fontResMgr.Get("fonts/KOMIKAP_.ttf"), "", 40, sf::Color::White);
	uiScore[RIGHT]->Set(fontResMgr.Get("fonts/KOMIKAP_.ttf"), "", 40, sf::Color::White);
	uiScore[RIGHT]->SetPosition({1650.f , 0});

	AddGo(uiScore[LEFT]);
	AddGo(uiScore[RIGHT]);

	// *********************uiTimeBar**********************
	sf::Vector2f uiTimeBarPos = (sf::Vector2f)FRAMEWORK.GetWindowSize();
	uiTimeBarPos.x *= 0.5f;
	uiTimeBarPos.x -= 690.f;
	uiTimeBarPos.y *= 0.9f;

	uiTimeBar[LEFT] = new UiTimeBar("LeftTimeBar");
	uiTimeBar[RIGHT] = new UiTimeBar("RightTimeBar");

	uiTimeBar[LEFT]->Set({ 400, 80 }, sf::Color::Red);
	uiTimeBar[LEFT]->SetOrigin(Origins::ML);
	uiTimeBar[LEFT]->SetPosition(uiTimeBarPos);

	uiTimeBarPos.x += 990.f;

	uiTimeBar[RIGHT]->Set({ 400, 80 }, sf::Color::Red);
	uiTimeBar[RIGHT]->SetOrigin(Origins::ML);
	uiTimeBar[RIGHT]->SetPosition(uiTimeBarPos);

	AddGo(uiTimeBar[LEFT]);
	AddGo(uiTimeBar[RIGHT]);

	for (GameObject* obj : gameObjects)
	{
		obj->Init();
	}
}

void ScenePlayer2Mode::Release()
{
	Scene::Release();
}

void ScenePlayer2Mode::Enter()
{
	player[(int)PLAYER::LEFT_PLAYER]->
		SetPosition(tree[LEFT]->GetPosition());

	player[(int)PLAYER::RIGHT_PLAYER]->
		SetPosition(tree[RIGHT]->GetPosition());

	Scene::Enter();

	SetStatus(Status::Awake);
}

void ScenePlayer2Mode::Exit()
{}

void ScenePlayer2Mode::Update(float dt)
{
	Scene::Update(dt);

	switch (currStatus)
	{
	case Status::Awake:
		UpdateAwake(dt);
		break;
	case Status::Game:
		UpdateGame(dt);
		break;
	case Status::GameOver:
		UpdateGameOver(dt);
		break;
	case Status::Pause:
		UpdatePause(dt);
		break;
	}
}

void ScenePlayer2Mode::UpdateAwake(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		SetStatus(Status::Game);
	}
}

void ScenePlayer2Mode::UpdateGame(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SetStatus(Status::Pause);
	}

	Sides inputSideRightPlayer = Sides::NONE;
	Sides inputSideLeftPlayer = Sides::NONE;

	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		inputSideRightPlayer = Sides::LEFT;
		timer[RIGHT] += 0.5f;
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		inputSideRightPlayer = Sides::RIGHT;
		timer[RIGHT] += 0.5f;
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::A))
	{
		inputSideLeftPlayer = Sides::LEFT;
		timer[LEFT] += 0.5f;
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::D))
	{
		inputSideLeftPlayer = Sides::RIGHT;
		timer[LEFT] += 0.5f;
	}

	timer[RIGHT] = timer[RIGHT] > duration ? duration : timer[RIGHT];
	timer[LEFT] = timer[LEFT] > duration ? duration : timer[LEFT];

	timer[RIGHT] -= dt;
	timer[LEFT] -= dt;

	uiTimeBar[RIGHT]->SetValue(timer[RIGHT] / duration);
	uiTimeBar[LEFT]->SetValue(timer[LEFT] / duration);

	if (uiTimeBar[RIGHT]->GetValue() <= 0.f)
	{
		uiMsg->SetString("Left Player Win!! / Right Player Lose");
		SetStatus(Status::GameOver);
		player[RIGHT]->OnDie();

		sfxTimeOver.play();
		for (GameObject* obj : gameObjects)
		{
			obj->Init();
		}
		return;
	}

	if (uiTimeBar[LEFT]->GetValue() <= 0.f)
	{
		uiMsg->SetString("Left Player Lose / Right Player Win!!");
		SetStatus(Status::GameOver);
		player[LEFT]->OnDie();

		sfxTimeOver.play();
		for (GameObject* obj : gameObjects)
		{
			obj->Init();
		}

		return;
	}

	RightPlayerMoveChopEffect(inputSideRightPlayer);
	LeftPlayerMoveChopEffect(inputSideLeftPlayer);

	auto it = useEffectList.begin();
	while (it != useEffectList.end())
	{
		EffectLog* effectGo = *it;
		if (!effectGo->GetActive())
		{
			RemoveGo(effectGo);
			it = useEffectList.erase(it);
			unuseEffectList.push_back(effectGo);
		}
		else
		{
			++it;
		}
	}
}

void ScenePlayer2Mode::UpdateGameOver(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		SetStatus(Status::Game);
	}
}

void ScenePlayer2Mode::UpdatePause(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SetStatus(Status::Game);
	}
}

void ScenePlayer2Mode::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void ScenePlayer2Mode::OnChop()
{}

void ScenePlayer2Mode::OnPlayerDie()
{
	SetStatus(Status::GameOver);
}

void ScenePlayer2Mode::textResMgrLoad()
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
}

void ScenePlayer2Mode::AddGoSpriteLoadTexture(const std::string& key, const std::string& name, const std::string& path)
{
	texResMgr.Load(path);

	SpriteGo* spriteGo = new SpriteGo(name);
	spriteGo->SetTexture(texResMgr.Get(path));
	AddGo(spriteGo);
	
	sprites.insert({ key, spriteGo });
}

void ScenePlayer2Mode::RightPlayerDie()
{
	SetStatus(Status::GameOver);
	uiMsg->SetString("Left Player Win!! / Right Player Lose");
}

void ScenePlayer2Mode::LeftPlayerDie()
{
	SetStatus(Status::GameOver);
	uiMsg->SetString("Left Player Lose / Right Player Lose!!");
}

void ScenePlayer2Mode::RightPlayerMoveChopEffect(Sides inputSideRightPlayer)
{
	if (inputSideRightPlayer != Sides::NONE)
	{
		player[(int)PLAYER::RIGHT_PLAYER]->isChopping = true;
		player[(int)PLAYER::RIGHT_PLAYER]->sfxChop.play();

		Sides branchSide = tree[1]->Chop(inputSideRightPlayer);
		PlayEffectLog(inputSideRightPlayer, PLAYER::RIGHT_PLAYER);
		player[(int)PLAYER::RIGHT_PLAYER]->SetSide(inputSideRightPlayer);

		if (inputSideRightPlayer != branchSide)
		{
			OnChop();
			uiScore[RIGHT]->AddScore(10);
		}
		else
		{
			RightPlayerDie();
			player[(int)PLAYER::RIGHT_PLAYER]->OnDie();
			player[(int)PLAYER::RIGHT_PLAYER]->sfxDeath.play();
		}
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::Left) || InputMgr::GetKeyUp(sf::Keyboard::Right))
	{
		player[(int)PLAYER::RIGHT_PLAYER]->isChopping = false;
	}
}

void ScenePlayer2Mode::LeftPlayerMoveChopEffect(Sides inputSideLeftPlayer)
{
	if (inputSideLeftPlayer != Sides::NONE)
	{
		player[(int)PLAYER::LEFT_PLAYER]->isChopping = true;
		player[(int)PLAYER::LEFT_PLAYER]->sfxChop.play();

		Sides branchSide = tree[0]->Chop(inputSideLeftPlayer);
		PlayEffectLog(inputSideLeftPlayer, PLAYER::LEFT_PLAYER);
		player[(int)PLAYER::LEFT_PLAYER]->SetSide(inputSideLeftPlayer);

		if (inputSideLeftPlayer != branchSide)
		{
			OnChop();
			uiScore[LEFT]->AddScore(10);
		}
		else
		{
			LeftPlayerDie();
			player[(int)PLAYER::LEFT_PLAYER]->OnDie();
			player[(int)PLAYER::LEFT_PLAYER]->sfxDeath.play();
		}
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::A) || InputMgr::GetKeyUp(sf::Keyboard::D))
	{
		player[(int)PLAYER::LEFT_PLAYER]->isChopping = false;
	}
}
