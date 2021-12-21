#pragma once
#include <exception>
#include <string>

/// <summary>
/// Thrown when variable name is invalid.
/// </summary>
/// <seealso cref="std::exception" />
class InvalidVariableNameException : public std::exception
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="InvalidVariableNameException"/> class.
	/// </summary>
	/// <param name="varName">Name of the variable.</param>
	InvalidVariableNameException(std::string varName)
		: _message("Can't access variable \"" + varName + "\".\n")
	{
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="InvalidVariableNameException"/> class.
	/// </summary>
	/// <returns></returns>
	virtual ~InvalidVariableNameException() noexcept {}

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