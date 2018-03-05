#include "GameObject.h"
class BaseComponent {
public: 
	BaseComponent();
	BaseComponent(GameObject* _Host);
	~BaseComponent();
	GameObject* Host;
	BaseComponent* GetComponent();
	virtual void AddComponent(GameObject* host);
	virtual void RemoveComponent();
};
