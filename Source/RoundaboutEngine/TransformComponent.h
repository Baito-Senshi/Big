#pragma once

#include "BaseComponent.h"

class TransformComponent : public BaseComponent  {
public:
	TransformComponent();
	~TransformComponent() { delete this; }

	void SetTransform(sf::Transform T) { LocalTransform = T; }
	sf::Transform GetTransform() { return LocalTransform; };
	sf::Transform GetWorldTransform() { return WorldTransform; }

	void Update(sf::Time DeltaTime);

	sf::Transform WorldTransform;
	sf::Transform LocalTransform;
};  