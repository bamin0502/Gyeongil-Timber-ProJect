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
    
    texResMgr.Load("graphics/button.png");
    
    fontResMgr.Load("fonts/NeoDunggeunmoPro-Regular.ttf");

    
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
    
}

