#include "Transform.h"
#include "BaseComponent.h"
#include "SFML/Graphics.hpp"

TransformComponent::TransformComponent()
{
	
}

TransformComponent::TransformComponent(sf::Transform _worldTransform) 
{
	WorldTransform = _worldTransform;
}

TransformComponent::~TransformComponent(void)
{
	delete this;
}

void TransformComponent::SetTransform(const sf::Transform & transform)
{
	LocalTransform = transform; 
}

sf::Transform TransformComponent::GetTransform()
{
	return LocalTransform;
}

sf::Transform TransformComponent::GetWorldTransform()
{
	return WorldTransform;
}

void TransformComponent::RemoveComponent() {

}