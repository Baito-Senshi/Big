#pragma once

class BaseComponent {
protected: 
	class GameObject* Host;
	virtual BaseComponent* GetComponent() { return this; }
	void RemoveComponent() { delete this; }
};
	