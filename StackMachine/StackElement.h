#pragma once

namespace StackMachineImplementation 
{
	/// <summary>
	/// Class that represents stack element.
	/// </summary>
	class StackElement
	{
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="StackElement"/> class.
		/// </summary>
		/// <param name="value">The value.</param>
		StackElement(int value);

		/// <summary>
		/// Initializes a new instance of the <see cref="StackElement"/> class.
		/// </summary>
		/// <param name="value">The value.</param>
		/// <param name="next">The next.</param>
		StackElement(int value, StackElement* next);

		/// <summary>
		/// Gets the value.
		/// </summary>
		/// <returns></returns>
		int GetValue();

		/// <summary>
		/// Nexts this instance.
		/// </summary>
		/// <returns></returns>
		StackElement* Next();

	private:
		int _value;
		StackElement* _next;
	};
}