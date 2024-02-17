#pragma once
#include "SpriteGo.h"
#include "TextGo.h"

class SceneCharacterSelect : public Scene
{
protected:
    TextGo* choiceText;
    
    SpriteGo* character1;
    SpriteGo* character2;
    
    SpriteGo* battle;
    SpriteGo* backGround;
public:
    SceneCharacterSelect(SceneIds id);
    virtual ~SceneCharacterSelect();

    void Init() override;
    void Release() override;

    void Enter() override;
    void Exit() override;

    void Update(float dt) override;
};

