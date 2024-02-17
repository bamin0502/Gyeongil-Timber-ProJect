#pragma once

class SceneCharacterSelect : public Scene
{
public:
    SceneCharacterSelect(SceneIds id);
    virtual ~SceneCharacterSelect();

    void Init() override;
    void Release() override;

    void Enter() override;
    void Exit() override;

    void Update(float dt) override;
};

