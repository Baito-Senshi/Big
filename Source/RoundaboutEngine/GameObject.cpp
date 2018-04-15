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
		AddComponent(T);
	}
}

void GameObject::AddChild(GameObject* S)
{
	Children.push_back(S);
	S->Parent = this;
}

void GameObject::Update(sf::Time msec)
{
	if (Parent) { WorldTransform = Parent->WorldTransform * LocalTransform; }

	else { WorldTransform = LocalTransform; }
	if (Children.size() > 0)
	{
		for (std::vector<GameObject*>::iterator i = Children.begin(); i != Children.end(); ++i)
		{
			(*i)->Update(msec);
		}
	}
}

void GameObject::AddComponent(class BaseComponent * B)
{
	{ Components.push_back(B); }
}
