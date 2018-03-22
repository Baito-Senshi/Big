class Scene {
public:
	Scene() {}
	~Scene(void);

	Scene(std::string Name);

	void SetName(std::string Name) { SceneName = Name; }
	void AddChild();
	void AddChild(class GameObject* G);
	void Update(float DeltaTime);

	std::string SceneName;
	std::vector<class GameObject*> Children;
};