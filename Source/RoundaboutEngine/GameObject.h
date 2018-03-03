class GameObject{
	GameObject() { Parent = NULL; }
	~GameObject(void);
	void SetTransform(const sf::Transform& transform) { LocalTransform = transform; }
	sf::Transform GetTransform() {  return LocalTransform; }
	sf::Transform GetWorldTransform() { return WorldTransform; }
	
	//void SetParent(GameObject& P) { Parent = P; };
	void AddChild(GameObject* S);
	void Update(float msec);
	
protected:
	GameObject* Parent;
	sf::Transform WorldTransform;
	sf::Transform LocalTransform;
	
	std::vector<GameObject*> Children;


};