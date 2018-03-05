#include "BaseComponent.h"

BaseComponent::BaseComponent()
{

}

BaseComponent::BaseComponent(GameObject * _Host)
{
	Host = _Host;
}

BaseComponent::~BaseComponent()
{
	delete this;
}

BaseComponent* BaseComponent::GetComponent() {
	return this;
}

void BaseComponent::AddComponent(GameObject* host) {

}

void BaseComponent::RemoveComponent() {

}