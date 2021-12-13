#pragma once
#include <exception>
#include <string>

/// <summary>
/// Exception that occurs when not all paths return value.
/// </summary>
/// <seealso cref="std::exception" />
class NotAllCodePathsReturnAValueException : public std::exception
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="NotAllCodePathsReturnAValueException"/> class.
	/// </summary>
	/// <param name="functionName">Name of the function.</param>
	NotAllCodePathsReturnAValueException(std::string functionName)
		:_message("Function \"" + functionName + "\" does not return a value at all paths.\n")
	{
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="NotAllCodePathsReturnAValueException"/> class.
	/// </summary>
	/// <returns></returns>
	virtual ~NotAllCodePathsReturnAValueException() noexcept {}

	/// <summary>
	/// Whats this instance.
	/// </summary>
	/// <returns></returns>
	const char* what() const noexcept
	{
		return _message.c_str();
	}

private:
	const std::string _message;
};