#include "pch.h"
#include "SceneCharacterSelect.h"

SceneCharacterSelect::SceneCharacterSelect(SceneIds id)
    :Scene(id)
{
}
SceneCharacterSelect::SceneCharacterSelect(SceneIds id):Scene(id)
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
    //texResMgr.Load("graphics/character_frame.png");
    fontResMgr.Load("fonts/NeoDunggeunmoPro-Regular.ttf");

    backGround = new SpriteGo("BG");
    backGround->SetTexture("graphics/graybackground.png");
    backGround->SetPosition({1920.f / 2, 1080.f / 2});
    backGround->SetOrigin(Origins::MC);
    backGround->SetScale({2.0f, 2.0f});
    AddGo(backGround);

    battle = new SpriteGo("Battle");
    battle->SetTexture("graphics/battle.png");
    battle->SetPosition({1920.f / 2, 1080.f / 2});
    battle->SetOrigin(Origins::MC);
    battle->SetScale({1.0f, 1.0f});
    AddGo(battle);
    
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
}


