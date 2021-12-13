#pragma once
#include <exception>
#include <string>

/// <summary>
/// Exception that occurs when during operation there is not enough elements in stack.
/// </summary>
/// <seealso cref="std::exception" />
class NotEnoughStackElementsException : public std::exception
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="NotEnoughStackElementsException"/> class.
	/// </summary>
	NotEnoughStackElementsException() : _message("Not enought elements in stack to perform operation")
	{
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="NotEnoughStackElementsException"/> class.
	/// </summary>
	/// <returns></returns>
	virtual ~NotEnoughStackElementsException() noexcept {}

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