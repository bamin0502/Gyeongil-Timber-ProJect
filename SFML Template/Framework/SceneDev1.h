#pragma once

class SceneDev1 : public Scene
{
protected:


public:
	SceneDev1(SceneIds id);
	virtual ~SceneDev1();

	void Init() override; // �ڽ�Ŭ���� �ʱ�ȭ
	void Release() override; // 


	void Enter() override; // �� ���� ����
	void Exit() override; // �� ���� ����

	virtual void Update(float dt) override;
};

