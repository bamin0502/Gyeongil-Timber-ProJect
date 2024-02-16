#include "pch.h"
#include "Tree.h"
#include "GameObject.h"
#include "Branch.h"
#include "Utils.h"

Tree::Tree(const std::string& name) : GameObject(name)
{
}

Tree::~Tree()
{
	Release();
}

void Tree::UpdataBranchPos()
{
	// position : 현재 트리의 위치 
	sf::Vector2f pos = position; 

	for (Branch* branch : _branches)
	{
		pos.y -= branchOffsetY;
		branch->SetPosition(pos);
	}
}

Sides Tree::Chop()
{
	Branch* temp = _branches.front();

	_branches.pop_front();

	temp->SetSide(RandomSide(4));

	_branches.push_back(temp);

	// 가지 위치 
	UpdataBranchPos();

	return _branches.front()->GetSide();

}

void Tree::Init()
{
	Release();
	_tree.setTexture(*TEXTURE_RES_MGR.Get(_treeTextureId));

	sf::Texture& branchTexture = *TEXTURE_RES_MGR.Get(_branchTextureId);
	float originBranchY = branchTexture.getSize().y;
	float originBranchX = _tree.getLocalBounds().width * -0.5f;

	Utils::SetOrigin(_tree, Origins::BC);
	for (int i = 0; i < _branchesCount; i++)
	{
		Branch* branch = new Branch();
		branch->SetTexture(branchTexture);
		branch->SetOrigin({originBranchX , originBranchY});
		_branches.push_back(branch);
	}

}

void Tree::Release()
{
	for (Branch* branch : _branches)
	{
		delete branch;
	}
	
	_branches.clear();
}

Sides Tree::RandomSide(int range)
{
	Sides side = Sides::NONE;

	int rand = Utils::RandomRange(0 , range);

	if (rand < 2)
	{
		side = (Sides)rand;
	}
	return side;
}

void Tree::SetOrigin(Origins preset)
{
}

void Tree::SetOrigin(const sf::Vector2f& newOrigin)
{
}

void Tree::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	_tree.setPosition(pos);
	UpdataBranchPos(); 
}

void Tree::Reset()
{
	for (Branch* branch : _branches)
	{
		 branch->Reset();
	}

	int noneCount = 2;
	int count = 0;

	// 처음 시작하는 2개의 가지는 side None 로 설정
	for (Branch* branch : _branches)
	{
		if (count < noneCount)
		{
			branch->SetSide(Sides::NONE);
		}
		else
		{
			branch->SetSide(RandomSide());
		}
		++count;
	}

	// 가지 위치
	UpdataBranchPos();
}

void Tree::Update(float dt)
{
	//if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	//{
	//	Chop(Sides::LEFT);
	//}
	//if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	//{
	//	Chop(Sides::RIGHT);
	//}

	for (Branch* branch : _branches)
	{
		if (branch->GetActive())
		{
			branch->Update(dt);
		}
	}
}

void Tree::Draw(sf::RenderWindow& window)
{
	window.draw(_tree);
	for (Branch* branch : _branches)
	{
		if (branch->GetActive())
		{
			branch->Draw(window);
		}
	}
}
