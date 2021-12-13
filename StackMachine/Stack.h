#pragma once
#include "StackElement.h"
#include "ISubject.h"

namespace StackMachineImplementation
{
	/// <summary>
	/// Class that represents stack, and subject under observation.
	/// </summary>
	/// <seealso cref="ISubject" />
	class Stack : public ISubject
	{
	public:

		/// <summary>
		/// Initializes a new instance of the <see cref="Stack"/> class.
		/// </summary>
		Stack();

		/// <summary>
		/// Finalizes an instance of the <see cref="Stack"/> class.
		/// </summary>
		~Stack();

		/// <summary>
		/// Get count of elements;
		/// </summary>
		/// <returns>Count of elements in stack.</returns>
		int Count();

		/// <summary>
		/// Pushes value into stack.
		/// </summary>
		/// <param name="value">The value.</param>
		void Push(int value);

		
		/// <summary>
		/// Pops element from stack.
		/// </summary>
		/// <returns>integer on the top of stack.</returns>
		int Pop();

		/// <summary>
		/// Peeks element on top of the stack.
		/// </summary>
		/// <returns>integer on the top of stack.</returns>
		int Peek();


		/// <summary>
		/// Dupplicate element.
		/// </summary>
		void Duplicate();

		/// <summary>
		/// Subscribes observer to 'look' after stack.
		/// </summary>
		/// <param name="observer">The observer.</param>
		void Subscribe(IObserver* observer) override;

		/// <summary>
		/// Unsubscribes observer from stack.
		/// </summary>
		void Unsubscribe() override;

	protected:

		/// <summary>
		/// Notifies all observers(invoked, when changes in stack occur).
		/// </summary>
		/// <param name="message">The message.</param>
		void Notify(const std::string& message) override;


	private:
		int _count;
		StackElement* _top;
		IObserver* _observer;
	};
}
