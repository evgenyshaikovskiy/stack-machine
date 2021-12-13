#pragma once
#include <exception>
#include <string>

/// <summary>
/// Exception that occurs when certain file or directory was'nt found.
/// </summary>
/// <seealso cref="std::exception" />
class FileNotFoundException : public std::exception
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="FileNotFoundException"/> class.
	/// </summary>
	FileNotFoundException(std::string fileName)
		: _message("No such file or directory \"" + fileName + "\" was found.\n")
	{
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="FileNotFoundException"/> class.
	/// </summary>
	/// <returns></returns>
	virtual ~FileNotFoundException() noexcept {}

	/// <summary>
	/// Whats this instance.
	/// </summary>
	/// <returns></returns>
	const char* what() const noexcept
	{
		return _message.c_str();
	}

private:
	std::string _message;
};