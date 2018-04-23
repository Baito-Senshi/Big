#pragma once

class GameObject {
public:
	GameObject() { Parent = nullptr; }
	~GameObject(void);

	GameObject(std::string N = "GameObject");
	GameObject(GameObject* P, std::string N = "GameObject");
	
	void SetParent(GameObject* P) { Parent = P; };
	void SetName(std::string N) { Name = N; }
	std::string GetName() { return Name; }
	void AddChild(GameObject* Child);
	virtual void Update(sf::Time DeltaTime);

	void AddComponent(class BaseComponent* B);
	//class BaseComponent* GetComponent(std::string ComponentName);
	//void RemoveComponent() { delete this; }

	GameObject* Parent;	
	class TransformComponent* T;

	class TransformComponent* GetTransform() { return T; }
	std::string Name;
	std::vector<GameObject*> Children;
	std::vector<class BaseComponent*> Components;
};