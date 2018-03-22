class GameObject {
public:
	GameObject() { Parent = nullptr; }
	~GameObject(void);

	GameObject(GameObject* P, std::string N = "GameObject");
	
	void SetParent(GameObject* P) { Parent = P; };
	void SetName(std::string N) { Name = N; }
	void AddChild(GameObject* S);
	void Update(float DeltaTime);

	void AddComponent(class BaseComponent* B);
	//void RemoveComponent() { delete this; }

	GameObject* Parent;	
	class TransformComponent* T;
	
	std::string Name;
	sf::Transform WorldTransform;
	sf::Transform LocalTransform;
	std::vector<GameObject*> Children;
	std::vector<class BaseComponent*> Components;
};