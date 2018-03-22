#include "BaseComponent.h"
#include <SFML\Graphics.hpp>

class TransformComponent : public BaseComponent  {
public:
	TransformComponent() {}
	~TransformComponent() { delete this; }

	void SetTransform(const sf::Transform T) { LocalTransform = T; }
	sf::Transform GetTransform() { return LocalTransform; };
	sf::Transform GetWorldTransform() { return WorldTransform; }

	sf::Transform WorldTransform;
	sf::Transform LocalTransform;
};  