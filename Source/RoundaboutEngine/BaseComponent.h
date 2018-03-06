#include "GameObject.h"
#include <SFML\Graphics.hpp>

class BaseComponent {
public: 
	BaseComponent();
	BaseComponent(GameObject* _Host);
	~BaseComponent();
	GameObject* Host;
	BaseComponent* GetComponent();
	virtual void AddComponent(BaseComponent host);
	virtual void RemoveComponent();
	std::vector<BaseComponent*> comp;
};
