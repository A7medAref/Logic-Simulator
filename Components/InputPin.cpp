#include "InputPin.h"

InputPin::InputPin()
{
	m_connected = false;
}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::SetConnected(bool connected)
{
	m_connected = connected;
}

bool InputPin::GetConnected()
{
	return m_connected;
}
