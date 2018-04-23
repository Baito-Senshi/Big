#include "SFML/Graphics.hpp"
#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
	LocalTransform = sf::Transform(0, 0, 0,
									0, 0, 0,
									0, 0, 0);
	WorldTransform = sf::Transform(0, 0, 0,
									0, 0, 0,
									0, 0, 0);
}

void TransformComponent::Update(sf::Time DeltaTime)
{
}