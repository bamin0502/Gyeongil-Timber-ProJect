#pragma once
#include "SpriteGo.h"
#include "TextGo.h"


class SceneGameModeSelect : public Scene
{
protected:
    SpriteGo* modeBackground;
    SpriteGo* singleButton;
    SpriteGo* multiButton;

    TextGo* selectText;
    TextGo* singleText;
    TextGo* multiText;
    TextGo* NoticeText;

public:

    SceneGameModeSelect(SceneIds id);
    virtual ~SceneGameModeSelect();
    
    void Init() override;
    void Release() override;

    void Enter() override;
    void Exit() override;

    void Update(float dt) override;

    
};

