#pragma once

class Scene {
public:
	Scene() {}
	~Scene(void);

	Scene(std::string Name);

	void SetName(std::string Name) { SceneName = Name; }
	void AddChild();
	void AddChild(class GameObject* G);
	void Update(sf::Time DeltaTime);

	std::string SceneName;
	std::vector<class GameObject*> Children;
};