#include "pch.h"
#include "StackElement.h"

namespace StackMachineImplementation
{
	StackElement::StackElement(int value)
	{
		_value = value;
		_next = nullptr;
	}

	StackElement::StackElement(int value, StackElement* next)
	{
		_value = value;
		_next = next;
	}

	int StackElement::GetValue()
	{
		return _value;
	}

	StackElement* StackElement::Next()
	{
		return _next;
	}
}



