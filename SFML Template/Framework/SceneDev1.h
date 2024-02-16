#pragma once

class SceneDev1 : public Scene
{
protected:


public:
	SceneDev1(SceneIds id);
	virtual ~SceneDev1();

	void Init() override; // 자식클래스 초기화
	void Release() override; // 


	void Enter() override; // 씬 시작 구현
	void Exit() override; // 씬 종료 구현

	virtual void Update(float dt) override;
};

