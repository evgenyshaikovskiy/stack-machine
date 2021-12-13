#pragma once
#include <exception>

/// <summary>
/// Exception that occurs when dividing by zero.
/// </summary>
/// <seealso cref="std::exception" />
class DivisionByZeroException : public std::exception
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="DivisionByZeroException"/> class.
	/// </summary>
	DivisionByZeroException()
		: _message("Division by zero.\n") 
	{
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="DivisionByZeroException"/> class.
	/// </summary>
	/// <returns></returns>
	virtual ~DivisionByZeroException() noexcept {}

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
