#pragma once



class SceneGameModeSelect : public Scene
{
protected:

public:
    SceneGameModeSelect(SceneIds id);
    virtual ~SceneGameModeSelect();

    void Init() override;
    void Release() override;

    void Enter() override;
    void Exit() override;

    void Update(float dt) override;
};

