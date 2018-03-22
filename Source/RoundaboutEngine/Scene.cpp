#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "GameObject.h"

#include <vector>
#include <string>

Scene::~Scene()
{
	for (unsigned int i = 0; i < Children.size(); i++)
	{
		delete Children[i];
	}
}

Scene::Scene(std::string Name = "Scene")
{
	SceneName = Name;
}

void Scene::AddChild()
{
	GameObject* NewGameObject;
	Children.push_back(NewGameObject);
}

void Scene::AddChild(GameObject* S)
{
	Children.push_back(S);
}

void Scene::Update(float msec)
{
	for (std::vector<GameObject*>::iterator i = Children.begin(); i != Children.end(); ++i)
	{
		(*i)->Update(msec);
	}
}