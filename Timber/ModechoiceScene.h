#pragma once

class SCENECHOICE_GAME:public Scene
{
public:
    SCENECHOICE_GAME(SceneIds id);
    virtual ~SCENECHOICE_GAME();

    void Init() override;
    void Release() override;

    void Enter() override;
    void Exit() override;

    void Update(float dt) override;
};
