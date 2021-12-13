#include "pch.h"
#include "StackMachine.h"
#include "CustomExceptions.h"

namespace StackMachineImplementation
{
	void StackMachine::Add()
	{
		this->CheckForStackElements();

		int right = this->Pop();
		int left = this->Pop();

		this->Notify("Add " + std::to_string(left) + " to " + std::to_string(right) + ".\n");
		this->Push(right + left);
	}

	void StackMachine::Substract()
	{
		this->CheckForStackElements();

		int right = this->Pop();
		int left = this->Pop();

		this->Notify("Substract " + std::to_string(left) + " from " + std::to_string(right) + ".\n");
		this->Push(left - right);
	}

	void StackMachine::Multiply()
	{
		this->CheckForStackElements();

		int right = this->Pop();
		int left = this->Pop();

		this->Notify("Multiply " + std::to_string(left) + " with " + std::to_string(right) + ".\n");
		this->Push(right * left);
	}

	void StackMachine::Divide()
	{
		this->CheckForStackElements();

		int right = this->Pop();
		int left = this->Pop();

		if (right == 0)
		{
			this->Notify("Exception: DivisionByZeroException.\n");
			throw DivisionByZeroException();
		}
		else
		{
			this->Notify("Divide " + std::to_string(left) + " on " + std::to_string(right) + ".\n");
			this->Push(left / right);
		}
	}

	void StackMachine::CheckForStackElements()
	{
		if (this->Count() < 2)
		{
			this->Notify("Exception: NotEnoughStackElementsException.\n");
			throw NotEnoughStackElementsException();
		}
	}
}