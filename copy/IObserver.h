#pragma once
#include <string>

/// <summary>
/// Interface that represents some observer.
/// </summary>
class IObserver
{
public:	

	/// <summary>
	/// Finalizes an instance of the <see cref="IObserver"/> class.
	/// </summary>
	virtual ~IObserver() { };

	/// <summary>
	/// Updates some info.
	/// </summary>
	/// <param name="message">The message.</param>
	virtual void Update(const std::string& message) = 0;
};