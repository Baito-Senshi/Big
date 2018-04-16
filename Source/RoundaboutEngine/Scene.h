#pragma once

class Scene {
public:
	Scene();
	Scene(std::string Name);
	~Scene(void);

	void SetName(std::string Name) { SceneName = Name; }
	void AddChild(class GameObject* G);
	virtual void Update(sf::Time DeltaTime);

protected:
	std::string SceneName;
	std::vector<class GameObject*> Children;
};