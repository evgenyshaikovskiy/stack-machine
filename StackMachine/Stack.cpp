#include "pch.h"
#include "Stack.h"
#include "CustomExceptions.h"

namespace StackMachineImplementation
{
	Stack::Stack()
	{
		_top = nullptr;
		_count = 0;
		_observer = nullptr;
	}

	Stack::~Stack()
	{
		_top = nullptr;

		this->Unsubscribe();
	}

	int Stack::Count()
	{
		return _count;
	}

	void Stack::Push(int value)
	{
		if (_top == nullptr)
		{
			_top = new StackElement(value);
		}
		else
		{
			_top = new StackElement(value, _top);
		}

		_count++;

		// invoke with message that element was pushed into stack
		this->Notify("Push " + std::to_string(value) + " to stack.\n");
	}

	int Stack::Pop()
	{
		int value;
		if (_top != nullptr)
		{

			value = _top->GetValue();
			StackElement* temp = _top;
			temp = temp->Next();
			delete _top;
			_top = temp;
		}
		else
		{
			this->Notify("Exception: StackIsEmptyException.\n");
			throw StackIsEmptyException();
		}

		_count--;
		this->Notify("Pop " + std::to_string(value) + " from stack.\n");
		return value;
	}

	int Stack::Peek()
	{
		if (_count == 0)
		{
			this->Notify("Exception: StackIsEmptyException.\n");
			throw StackIsEmptyException();
		}

		this->Notify("Peek " + std::to_string(_top->GetValue()) + " from stack.\n");
		return _top->GetValue();
	}

	void Stack::Duplicate()
	{
		if (_count == 0)
		{
			this->Notify("Exception: StackIsEmptyException.\n");
			throw StackIsEmptyException();
		}

		this->Notify("Duplicate " + std::to_string(_top->GetValue()) + " in stack.\n");
		this->Push(_top->GetValue());
	}

	void Stack::Subscribe(IObserver* observer)
	{
		_observer = observer;
	}

	void Stack::Unsubscribe()
	{
		_observer = nullptr;
	}

	void Stack::Notify(const std::string& message)
	{
		if (_observer != nullptr)
		{
			_observer->Update(message);
		}
	}
}

