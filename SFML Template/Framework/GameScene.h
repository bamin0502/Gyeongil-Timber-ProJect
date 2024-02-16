#pragma once
#include <SFML/Audio.hpp>
#include "Scene.h"
#include "pch.h"

class TimeBar;
class UIScore;
class TextGo;
class Tree;
class EffectLog;
class Player;

class SceneGame : public Scene
{
public:
	enum class Status // 상태 패턴
	{
		AWAKE, // 초기화 0 
		GAME,  // 게임중 1
		GAMEOVER, // 게임오버 0
		PAUSE, // 정지 1
	};

protected:
	UIScore* _uiScore = nullptr;
	TextGo* _uiMsg = nullptr;
	Status _currStatus;
	TimeBar* _timeBar = nullptr;
	Tree* _tree = nullptr;
	Player* _player = nullptr;

	std::list<EffectLog*> _useEffectList;
	std::list<EffectLog*> _unUseEffectList;

	// Sound
	sf::SoundBuffer _chopSoundBuffer;
	sf::SoundBuffer _deathSoundBuffer;

	sf::Sound _chopSound;
	sf::Sound _deathSound;



public:
	SceneGame(SceneIds id);
	virtual ~SceneGame();

	void PlayEffectLog(Sides side);

	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Release() override;
	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	void UpdateGameAwake(float dt);
	void UpdateGame(float dt);
	void UpdateGameOver(float dt);
	void UpdatePause(float dt);
	virtual void Draw(sf::RenderWindow& window) override;

	void SetStatus(Status newStatus);

	float deltatime = 0.0f;
	float changeCloud = 3.0f;
};