#pragma once
class SceneDev2 : public Scene
{
protected:


public:
	SceneDev2(SceneIds id);
	virtual ~SceneDev2();

	void Init() override; // �ڽ�Ŭ���� �ʱ�ȭ
	void Release() override; // 

	void Enter() override; // �� ���� ����
	void Exit() override; // �� ���� ����

	virtual void Update(float dt) override;
};

