#pragma once
#include "Defines.h"
#include "SpriteGo.h"
#include "TextGo.h"

class SceneCharacterSelect : public Scene
{

protected:
    TextGo* choiceText;
    friend class ScenePlayer2Mode;
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
    TextGo* player1Text;
    TextGo* player2Text;
    TextGo* noticeText;
    Music Bgm;
    PlayerReadyState player1State=PlayerReadyState::NOT_READY;
    PlayerReadyState player2State=PlayerReadyState::NOT_READY;

    vector<string> CharacterTexture =
    {
        "graphics/player.png",
        "graphics/player2.png",
        "graphics/player3.png"
    };


public:
    SceneCharacterSelect(SceneIds id);
    virtual ~SceneCharacterSelect();
    bool isReady=false;
    int player1Index;
    int player2Index;
    string player1Texture = "graphics/player.png";
    string player2Texture = "graphics/player.png";

    void Init() override;
    void Release() override;
    void Draw(sf::RenderWindow& window) override;
    void Enter() override;
    void Exit() override;

    void Update(float dt) override;
};

