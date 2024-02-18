#pragma once
#include <map>

class UiScore;
class TextGo;
class UiTimeBar;
class Tree;
class EffectLog;
class MultiPlayer;
class SpriteGo;
class SceneCharacterSelect;

class ScenePlayer2Mode : public Scene
{
public:
	enum class Status
	{
		Awake,
		Game,
		GameOver,
		Pause,
	};

	enum class PLAYER
	{
		LEFT_PLAYER = 0,
		RIGHT_PLAYER = 1,
	};

	const int LEFT = 0;
	const int RIGHT = 1;

protected:
	std::vector<UiScore*> uiScore {nullptr, nullptr};

	TextGo* uiMsg = nullptr;

	std::vector<UiTimeBar*> uiTimeBar{ nullptr, nullptr };
	std::vector<float> timer{ 0.f, 0.f };

	std::map<std::string, SpriteGo*> sprites;
	// sprites[std::string key] 로 접근가능

	std::vector<Tree*> tree;

	std::vector<MultiPlayer*> player;

	std::list<EffectLog*> useEffectList;
	std::list<EffectLog*> unuseEffectList;

	SceneCharacterSelect* SCENE_CHARACTER_SELECT;
	
	Status currStatus;

	float duration = 3.f;

	Sound sfxTimeOver;
	Music Bgm;

public:
	ScenePlayer2Mode(SceneIds id);
	virtual ~ScenePlayer2Mode();
	
	void SetStatus(Status newStatus);

	Status GetStatus() const
	{
		return currStatus;
	}
	
	void PlayEffectLog(Sides side, PLAYER player);

	void Init() override;
	void Release() override;

	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void UpdateAwake(float dt);
	void UpdateGame(float dt);
	void UpdateGameOver(float dt);
	void UpdatePause(float dt);

	void Draw(RenderWindow& window) override;

	void OnChop();
	void OnPlayerDie();

	void RightPlayerDie();
	void LeftPlayerDie();

	void textResMgrLoad();

	void AddGoSpriteLoadTexture(const std::string& key ,
		const std::string& name , const std::string& path);

	void RightPlayerMoveChopEffect(Sides inputSideRightPlayer);
	void LeftPlayerMoveChopEffect(Sides inputSideLeftPlayer);
};

