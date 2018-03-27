#include <vector>
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "BaseComponent.h"
#include "TransformComponent.h"

GameObject::~GameObject()
{
	for (unsigned int i = 0; i < Children.size(); i++)
	{
		delete Children[i];
	}
}

GameObject::GameObject(GameObject * P, std::string N)
{
	Parent = P;
	Name = N;
	if (Parent != nullptr)
	{
		AddComponent(new TransformComponent());
	}
}

void GameObject::AddChild(GameObject* S)
{
	Children.push_back(S);
	S->Parent = this;
}

void GameObject::Update(sf::Time msec)
{
	if (this->Parent) { T->WorldTransform = &GameObject::T->GetTransform * T->LocalTransform; }

	else { T->WorldTransform = T->LocalTransform; }
	for (std::vector<GameObject*>::iterator i = Children.begin(); i != Children.end(); ++i)
	{
		(*i)->Update(msec);
	}
}

void GameObject::AddComponent(class BaseComponent * B)
{
	{ Components.push_back(B); }
}
