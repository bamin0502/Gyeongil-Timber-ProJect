#pragma once
#include "Defines.h"
#include "SpriteGo.h"
#include "TextGo.h"

class SceneCharacterSelect : public Scene
{
protected:
    TextGo* choiceText;
    
    SpriteGo* character1;
    SpriteGo* character2;
    SpriteGo* characterFrame;
    SpriteGo* characterFrame2;
    SpriteGo* player1;
    SpriteGo* player2;
    SpriteGo* battle;
    SpriteGo* backGround;
    RectangleShape readyButton;
    TextGo* readyText;

    PlayerReadyState player1State=PlayerReadyState::NOT_READY;
    PlayerReadyState player2State=PlayerReadyState::NOT_READY;
public:
    SceneCharacterSelect(SceneIds id);
    virtual ~SceneCharacterSelect();
    bool isReady;
    void Init() override;
    void Release() override;
    void Draw(sf::RenderWindow& window) override;
    void Enter() override;
    void Exit() override;

    void Update(float dt) override;
};

