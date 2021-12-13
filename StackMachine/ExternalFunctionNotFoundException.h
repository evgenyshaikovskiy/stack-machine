#pragma once
#include <string>
#include <exception>

/// <summary>
/// Exception that occurs when external function was'nt found.
/// </summary>
/// <seealso cref="std::exception" />
class ExternalFunctionNotFoundException : public std::exception
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="ExternalFunctionNotFoundException"/> class.
	/// </summary>
	/// <param name="functionName">Name of the function.</param>
	ExternalFunctionNotFoundException(std::string functionName)
		: _message("There is no \"" + functionName + "\" external function.\n")
	{
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="ExternalFunctionNotFoundException"/> class.
	/// </summary>
	/// <returns></returns>
	virtual ~ExternalFunctionNotFoundException() noexcept {}

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