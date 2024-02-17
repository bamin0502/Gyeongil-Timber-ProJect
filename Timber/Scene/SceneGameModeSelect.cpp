#include "pch.h"
#include "SceneGameModeSelect.h"

SceneGameModeSelect::SceneGameModeSelect(SceneIds id):Scene(id)
{
    
}

SceneGameModeSelect::~SceneGameModeSelect()
{
    
}

void SceneGameModeSelect::Init()
{
    // Load resources
    texResMgr.Load("graphics/graybackground.png");
    texResMgr.Load("graphics/single_button.png");
    texResMgr.Load("graphics/multi_button.png");
    fontResMgr.Load("fonts/NeoDunggeunmoPro-Regular.ttf");
    modeBackground = new SpriteGo("modeBG");
    modeBackground->SetTexture("graphics/graybackground.png");
    modeBackground->SetPosition({1920.f / 2, 1080.f / 2});
    modeBackground->SetOrigin(Origins::MC);
    modeBackground->SetScale({2.0f, 2.0f});
    AddGo(modeBackground);

    singleButton = new SpriteGo("SingleButton");
    singleButton->SetTexture("graphics/single_button.png");
    singleButton->SetPosition({1920.f / 2, 1080.f / 2});
    singleButton->SetScale({0.75f, 0.75f});
    singleButton->SetOrigin(Origins::MC);
    AddGo(singleButton);
    multiButton = new SpriteGo("MultiButton");
    multiButton->SetTexture("graphics/multi_button.png");
    multiButton->SetPosition({1920.f / 2, 1080.f / 2 + 300});
    multiButton->SetScale({0.75f, 0.75f});
    multiButton->SetOrigin(Origins::MC);
    AddGo(multiButton);
    
    selectText = new TextGo("SelectText");
    selectText->Set(fontResMgr.Get("fonts/NeoDunggeunmoPro-Regular.ttf"), "Select Game Mode", 100, sf::Color::White);
    selectText->SetPosition({1920.f / 2, 100});
    selectText->SetOrigin(Origins::MC);
    AddGo(selectText);
    singleText = new TextGo("SingleText");
    singleText->Set(fontResMgr.Get("fonts/NeoDunggeunmoPro-Regular.ttf"), "Single", 100, sf::Color::White);
    singleText->SetPosition({1920.f / 2, 1080.f / 2-30});
    singleText->SetOrigin(Origins::MC);
    AddGo(singleText);
    multiText = new TextGo("MultiText");
    multiText->Set(fontResMgr.Get("fonts/NeoDunggeunmoPro-Regular.ttf"), "Multi", 100, sf::Color::White);
    multiText->SetPosition({1920.f / 2, 1080.f / 2 + 270});
    multiText->SetOrigin(Origins::MC);
    AddGo(multiText);


}

void SceneGameModeSelect::Release()
{
    Scene::Release();
}

void SceneGameModeSelect::Enter()
{
    Scene::Enter();

}

void SceneGameModeSelect::Exit()
{
}

void SceneGameModeSelect::Update(float dt)
{
    Scene::Update(dt);
    
    if (InputMgr::GetMouseButtonDown(Mouse::Left))
    {
        
        //버튼 안에서 클릭했을 경우 실행 시킬건데 어캐해야할까?
        if (singleButton->GetPosition().x && singleButton->GetPosition().y)
        {
            SCENE_MGR.ChangeScene(SceneIds::SCENE_GAME);
        }
        else if(multiButton->GetPosition().x && multiButton->GetPosition().y)
        {
            SCENE_MGR.ChangeScene(SceneIds::SCENE_CHARACTER_SELECT);
        }
        else if(!singleButton->GetPosition().x && !singleButton->GetPosition().y && !multiButton->GetPosition().x && !multiButton->GetPosition().y)
        {
            //아무것도 안하고 넘어가기
            
        }
    }
}

