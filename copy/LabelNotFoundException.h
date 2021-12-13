#pragma once
#include <exception>
#include <string>

/// <summary>
/// Exception that occurs when label was'nt found.
/// </summary>
/// <seealso cref="std::exception" />
class LabelNotFoundException : public std::exception
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="LabelNotFoundException"/> class.
	/// </summary>
	/// <param name="labelName">Name of the label.</param>
	LabelNotFoundException(std::string labelName)
		: _message("There is no label \"" + labelName + "\".\n")
	{
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="LabelNotFoundException"/> class.
	/// </summary>
	/// <returns></returns>
	virtual ~LabelNotFoundException() noexcept {}

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