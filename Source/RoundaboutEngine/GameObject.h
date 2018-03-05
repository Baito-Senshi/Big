
class GameObject {
	GameObject() { Parent = NULL; }
	~GameObject(void);
	
	//void SetParent(GameObject& P) { Parent = P; };
	void AddChild(GameObject* S);
	void Update(float msec);

protected:
	GameObject* Parent;	
	sf::Transform WorldTransform;
	sf::Transform LocalTransform;
	std::vector<GameObject*> Children;
};