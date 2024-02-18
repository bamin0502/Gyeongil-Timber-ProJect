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
    NoticeText = new TextGo("NoticeText");
    NoticeText->Set(fontResMgr.Get("fonts/NeoDunggeunmoPro-Regular.ttf"), " Mouse: \n LEFT:Single \n RIGHT:Multi", 30, sf::Color::Magenta);
    NoticeText->SetPosition({1700,100});
    NoticeText->SetOrigin(Origins::MC);
    AddGo(NoticeText);

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

    //마우스 클릭 이벤트는 먹히는데 마우스 위치인지 버튼 위치를 제대로 못잡아서 일단 마우스 클릭만 하면 이동하도록 설정
    // Vector2f singleSize;
    // singleButton->GetSize(singleSize);
    // Vector2f multiSize;
    // multiButton->GetSize(multiSize);
    // const Vector2f multiPos = multiButton->GetPosition();
    // const Vector2f singlePos = singleButton->GetPosition();
    //
    // const Vector2i mousePos = InputMgr::GetMousePosition();
    // const Vector2f mousePosF = { static_cast<float>(mousePos.x), static_cast<float>(mousePos.y) };

    if(InputMgr::GetMouseButton(Mouse::Left))
    {
        // if(mousePosF.x > singlePos.x - singleSize.x / 2 && mousePosF.x < singlePos.x + singleSize.x / 2 &&
        //    mousePosF.y > singlePos.y - singleSize.y / 2 && mousePosF.y < singlePos.y + singleSize.y / 2)
        // {
        //     SCENE_MGR.ChangeScene(SceneIds::SCENE_GAME);
        // }
        // else if(mousePosF.x > multiPos.x - multiSize.x / 2 && mousePosF.x < multiPos.x + multiSize.x / 2 &&
        //         mousePosF.y > multiPos.y - multiSize.y / 2 && mousePosF.y < multiPos.y + multiSize.y / 2)
        // {
        //     SCENE_MGR.ChangeScene(SceneIds::SCENE_CHARACTER_SELECT);
        // }
        SCENE_MGR.ChangeScene(SceneIds::SCENE_GAME);
    }
    if(InputMgr::GetMouseButton(Mouse::Right))
    {
        SCENE_MGR.ChangeScene(SceneIds::SCENE_CHARACTER_SELECT);
    }
   if(InputMgr::GetKeyDown(Keyboard::Escape))
   {
       SCENE_MGR.ChangeScene(SceneIds::SCENE_TITLE);
   }
}

