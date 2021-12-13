#pragma once
#include <exception>

/// <summary>
/// Exception that occurs when stack is empty.
/// </summary>
/// <seealso cref="std::exception" />
class StackIsEmptyException : public std::exception
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="StackIsEmptyException"/> class.
	/// </summary>
	StackIsEmptyException()
		: _message("Stack is empty.\n")
	{
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="StackIsEmptyException"/> class.
	/// </summary>
	/// <returns></returns>
	virtual ~StackIsEmptyException() noexcept {}

	/// <summary>
	/// Whats this instance.
	/// </summary>
	/// <returns></returns>
	const char* what() const noexcept
	{
		return _message;
	}

private:
	const char* _message;
};