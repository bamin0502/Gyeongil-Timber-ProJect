#pragma once
class GameObject;
class Branch;

class Tree : public GameObject
{
protected:
	sf::Sprite _tree;
	

public:
	Tree(const std::string& name = "");
	virtual ~Tree();
	void UpdataBranchPos();
	std::list<Branch*> _branches;
	
	int _branchesCount = 6;
	std::string _treeTextureId = "graphics/tree.png";
	std::string _branchTextureId = "graphics/branch.png";

	float branchOffsetY = 150.f;

	Sides Chop();

	void Init() override;
	void Release() override;

	static Sides RandomSide(int range = 4);

	// 실시간 가지의 개수가 아님 초기화 가지 개수
	void SetBranchCount(int count)
	{
		_branchesCount = count;
	};

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetPosition(const sf::Vector2f& pos) override;

	void Reset() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

