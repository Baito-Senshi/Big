#include <vector>
#include "SFML/Graphics.hpp"
#include "GameObject.h"

GameObject::~GameObject()
{
	for (unsigned int i = 0; i < Children.size(); i++)
	{
		delete Children[i];
	}
}

void GameObject::AddChild(GameObject* S)
{
	Children.push_back(S);
	S->Parent = this;
}

void GameObject::Update(float msec)
{
	if (Parent) { WorldTransform = Parent->WorldTransform * LocalTransform; }
	else { WorldTransform = LocalTransform; }
	for (std::vector<GameObject*>::iterator i = Children.begin(); i != Children.end(); ++i)
	{
		(*i)->Update(msec);
	}
}