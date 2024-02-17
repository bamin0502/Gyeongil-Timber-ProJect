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
    
    readyText = new TextGo("ReadyText");
    readyText->Set(fontResMgr.Get("fonts/NeoDunggeunmoPro-Regular.ttf"), "Ready", 75, Color::Black);
    readyText->SetPosition({1920.f / 2, 1080.f / 2 + 300});
    readyText->SetOrigin(Origins::MC);
    AddGo(readyText);
    
    readyButton.setSize({400, 100});
    readyButton.setFillColor(sf::Color(255, 0, 0, 128));
    readyButton.setOrigin({200, 50});
    readyButton.setPosition({1920.f / 2, 1080.f / 2 + 320});


    
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

void SceneCharacterSelect::Draw(sf::RenderWindow& window)
{
    Scene::Draw(window);

    window.draw(readyButton);
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

    //플레이어가 준비상태가 되면 레디버튼을 누를 수 있게 한다.
    if (InputMgr::GetKeyDown(Keyboard::LShift))
    {
        player1State = PlayerReadyState::READY;
    }
    if(InputMgr::GetKeyDown(Keyboard::RShift))
    {
        player2State = PlayerReadyState::READY;
    }
    
    
    if (InputMgr::GetMouseButtonDown(Mouse::Left))
    {
        if(isReady)
        {
            SCENE_MGR.ChangeScene(SceneIds::SCENE_PLAYER_2_MODE);
        }
        else
        {
            return;
        }
    }
    
    if(player1State==PlayerReadyState::READY && player2State==PlayerReadyState::READY)
    {
        isReady= true;
        readyText->Set(fontResMgr.Get("fonts/NeoDunggeunmoPro-Regular.ttf"), "Start", 75, Color::Black);
        readyButton.setFillColor(sf::Color(0, 255, 0, 128));
    }
    
}


