#pragma once
#include <string>
#include <exception>

/// <summary>
/// Exception that occurs when specified function was'nt found
/// </summary>
/// <seealso cref="std::exception" />
class FunctionNotFoundException : public std::exception
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="FunctionNotFoundException"/> class.
	/// </summary>
	/// <param name="functionName">Name of the function.</param>
	FunctionNotFoundException(std::string functionName)
		: _message("There is no \"" + functionName + "\" function.\n")
	{
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="FunctionNotFoundException"/> class.
	/// </summary>
	/// <returns></returns>
	virtual ~FunctionNotFoundException() noexcept {}

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