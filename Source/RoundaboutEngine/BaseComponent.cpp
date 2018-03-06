#include "BaseComponent.h"
#include <vector>
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

BaseComponent* BaseComponent::GetComponent() 
{
	return this;
}

void BaseComponent::AddComponent(BaseComponent host) 
{
	comp.push_back(comp);
}

void BaseComponent::RemoveComponent()
{
	comp.pop_back();
}