#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "BaseComponent.h"
#include "TransformComponent.h"

#include <vector>
#include <string>
#include <iostream>

GameObject::GameObject(GameObject* P, std::string N)
{
	Parent = P;
	Name = N;

	T = new TransformComponent();
	AddComponent(T);
}

GameObject::GameObject(std::string N)
{
	Name = N;
	T = new TransformComponent();
	AddComponent(T);
	std::cout << "Added2" << std::endl;

}

void GameObject::AddChild(GameObject* Child)
{
	Children.push_back(Child);
	Child->Parent = this;
}

void GameObject::Update(sf::Time DeltaTime)
{
	for (std::vector<GameObject*>::iterator i = Children.begin(); i != Children.end(); ++i)
	{
		(*i)->Update(DeltaTime);
	}

	for (std::vector<BaseComponent*>::iterator i = Components.begin(); i != Components.end(); ++i)
	{
		(*i)->Update(DeltaTime);
	}
}

void GameObject::AddComponent(class BaseComponent * B)
{
	{ Components.push_back(B); }
}

GameObject::~GameObject()
{
	for (unsigned int i = 0; i < Children.size(); i++)
	{
		delete Children[i];
	}
}