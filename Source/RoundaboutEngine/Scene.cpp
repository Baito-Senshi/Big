#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "GameObject.h"

#include <vector>
#include <string>
#include <iostream>

Scene::Scene()
{
}

Scene::Scene(std::string Name = "Scene")
{
	SceneName = Name;
}

Scene::~Scene()
{
	for (unsigned int i = 0; i < Children.size(); i++)
	{
		delete Children[i];
	}
}

void Scene::AddChild(GameObject* S)
{
	Children.push_back(S);
}

void Scene::Update(sf::Time DeltaTime)
{
	for (std::vector<GameObject*>::iterator i = Children.begin(); i != Children.end(); ++i)
	{
		(*i)->Update(DeltaTime);
	}
}