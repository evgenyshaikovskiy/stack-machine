#pragma once
#include <exception>
#include <string>

class InvalidVariableNameException : public std::exception
{
public:
	InvalidVariableNameException(std::string varName)
		: _message("Can't access variable \"" + varName + "\".\n")
	{
	}

	virtual ~InvalidVariableNameException() noexcept {}

	const char* what() const noexcept
	{
		return _message.c_str();
	}


private:
	const std::string _message;
};