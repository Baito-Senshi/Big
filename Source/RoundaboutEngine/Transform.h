#include "BaseComponent.h"
#include <SFML\Graphics.hpp>

class TransformComponent : BaseComponent  {
	TransformComponent();

	TransformComponent(sf::Transform _worldTransform);

	~TransformComponent(void);

	void SetTransform(const sf::Transform& transform);
	sf::Transform GetTransform();
	sf::Transform GetWorldTransform();

	virtual void AddComponent(GameObject* comp) override {
		
	}
	virtual void RemoveComponent() override;

	sf::Transform WorldTransform;
	sf::Transform LocalTransform;
};  