#pragma once
#include "Stack.h"
namespace StackMachineImplementation
{
	/// <summary>
	/// Implementation for stack machine.
	/// </summary>
	/// <seealso cref="Stack" />
	class StackMachine : public Stack
	{
	public:

		/// <summary>
		/// Adds elements on the top of stack.
		/// </summary>
		void Add();

		/// <summary>
		/// Substracts elements on the top of stack.
		/// </summary>
		void Substract();

		/// <summary>
		/// Multiplies elements on the top of stack.
		/// </summary>
		void Multiply();

		/// <summary>
		/// Divides elements on the top of stack.
		/// </summary>
		void Divide();

	private:
		void CheckForStackElements();
	};
}