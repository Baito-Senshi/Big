#pragma once

class GameObject {
public:
	GameObject() { Parent = nullptr; }
	~GameObject(void);

	GameObject(GameObject* P, std::string N = "GameObject");
	
	void SetParent(GameObject* P) { Parent = P; };
	GameObject* GetParent() { if (Parent != nullptr) { return Parent; } }
	void SetName(std::string N) { Name = N; }
	std::string GetName() { return Name; }
	void AddChild(GameObject* S);
	void Update(sf::Time DeltaTime);

	void AddComponent(class BaseComponent* B);
	//class BaseComponent* GetComponent(std::string ComponentName);
	//void RemoveComponent() { delete this; }

	GameObject* Parent;	
	class TransformComponent* T;
	
	sf::Transform LocalTransform;
	sf::Transform WorldTransform;
	std::string Name;
	std::vector<GameObject*> Children;
	std::vector<class BaseComponent*> Components;
};