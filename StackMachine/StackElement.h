#pragma once

namespace StackMachineImplementation 
{
	class StackElement
	{
	public:
		StackElement(int value);

		StackElement(int value, StackElement* next);

		int GetValue();

		StackElement* Next();

	private:
		int _value;
		StackElement* _next;
	};
}