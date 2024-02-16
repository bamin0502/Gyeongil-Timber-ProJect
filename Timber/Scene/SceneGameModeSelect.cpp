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
    cout<<"SceneGameModeSelect::Update"<<endl;
}


