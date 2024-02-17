#pragma once

class TextGo;
class SpriteGo;

class SceneTitle : public Scene
{
protected:
	SpriteGo* startTitle = nullptr;
	TextGo* uiText = nullptr;
public:
	SceneTitle(SceneIds id);
	virtual ~SceneTitle();

	void Init() override;
	void Release() override;

	void Update(float dt) override;

	void Enter() override;
	void Exit() override;

	void Draw(sf::RenderWindow& window) override;
};

