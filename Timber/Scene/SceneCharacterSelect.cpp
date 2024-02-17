#include "pch.h"
#include "SceneCharacterSelect.h"

SceneCharacterSelect::SceneCharacterSelect(SceneIds id)
    :Scene(id)
{
}

SceneCharacterSelect::~SceneCharacterSelect()
{   
}

void SceneCharacterSelect::Init()
{

    texResMgr.Load("graphics/graybackground.png");
    texResMgr.Load("graphics/player.png");
    texResMgr.Load("graphics/battle.png");
    //texResMgr.Load("graphics/player2.png");
    //texResMgr.Load("graphics/player3.png");
    texResMgr.Load("graphics/character_frame.png");
    texResMgr.Load("graphics/character_frame2.png");
    fontResMgr.Load("fonts/NeoDunggeunmoPro-Regular.ttf");

    backGround = new SpriteGo("BG");
    backGround->SetTexture("graphics/graybackground.png");
    backGround->SetPosition({1920.f / 2, 1080.f / 2});
    backGround->SetOrigin(Origins::MC);
    backGround->SetScale({2.0f, 2.0f});
    AddGo(backGround);
    
    characterFrame = new SpriteGo("CharacterFrame");
    characterFrame->SetTexture("graphics/character_frame.png");
    characterFrame->SetPosition({(1920.f / 2)-300, 1080.f / 2});
    characterFrame->SetScale({-1.0f, 1.25f});
    characterFrame->SetOrigin(Origins::MC);
    AddGo(characterFrame);

    characterFrame2 = new SpriteGo("CharacterFrame2");
    characterFrame2->SetTexture("graphics/character_frame2.png");
    characterFrame2->SetPosition({(1920.f / 2)+300, 1080.f / 2});
    characterFrame2->SetScale({1.0f, 1.25f});
    characterFrame2->SetOrigin(Origins::MC);
    AddGo(characterFrame2);

    player1 = new SpriteGo("Player1");
    player1->SetTexture("graphics/player.png");
    player1->SetPosition({(1920.f / 2)-300, 1080.f / 2});
    player1->SetScale({-1.0f, 1.0f});
    player1->SetOrigin(Origins::MC);
    AddGo(player1);

    player2 = new SpriteGo("Player2");
    player2->SetTexture("graphics/player.png");
    player2->SetPosition({(1920.f / 2)+300, 1080.f / 2});
    player2->SetScale({1.0f, 1.0f});
    player2->SetOrigin(Origins::MC);
    AddGo(player2);
    
    battle = new SpriteGo("Battle");
    battle->SetTexture("graphics/battle.png");
    battle->SetPosition({1920.f / 2, 1080.f / 2});
    battle->SetOrigin(Origins::MC);
    battle->SetScale({1.0f, 1.0f});
    AddGo(battle);

    readyButton = RectangleShape({200, 100});
    readyButton.setFillColor(Color::Green);
    readyButton.setPosition({1920.f / 2, 1080.f /2 +100});
    
    
    
    choiceText = new TextGo("ChoiceText");
    choiceText->Set(fontResMgr.Get("fonts/NeoDunggeunmoPro-Regular.ttf"), "Choose your character!", 75, Color::White);
    choiceText->SetPosition({1920.f / 2, 100.f});
    choiceText->SetOrigin(Origins::MC);
    AddGo(choiceText);

    
}

void SceneCharacterSelect::Release()
{
    Scene::Release();
}

void SceneCharacterSelect::Enter()
{
    Scene::Enter();
}

void SceneCharacterSelect::Exit()
{
}

void SceneCharacterSelect::Update(float dt)
{
    Scene::Update(dt);



    if (InputMgr::GetMouseButtonDown(Mouse::Left))
    {
        
       
    }
    
    if(player1State==PlayerReadyState::READY && player2State==PlayerReadyState::READY)
    {
        
        SCENE_MGR.ChangeScene(SceneIds::SCENE_PLAYER_2_MODE);
    }
    
}


