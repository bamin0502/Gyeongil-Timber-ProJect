#pragma once
class SceneDev2 : public Scene
{
protected:


public:
	SceneDev2(SceneIds id);
	virtual ~SceneDev2();

	void Init() override; // 자식클래스 초기화
	void Release() override; // 

	void Enter() override; // 씬 시작 구현
	void Exit() override; // 씬 종료 구현

	virtual void Update(float dt) override;
};

