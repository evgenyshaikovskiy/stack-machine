#pragma once
#include "IObserver.h"
#include <string>

/// <summary>
/// Interface that represents subject under observation.
/// </summary>
class ISubject
{
public:

	/// <summary>
	/// Finalizes an instance of the <see cref="ISubject"/> class.
	/// </summary>
	virtual ~ISubject() { };

	/// <summary>
	/// Subscribes the specified observer.
	/// </summary>
	/// <param name="observer">The observer.</param>
	virtual void Subscribe(IObserver* observer) = 0;

	/// <summary>
	/// Unsubscribes this instance.
	/// </summary>
	virtual void Unsubscribe() = 0;

protected:

	/// <summary>
	/// Notifies all observers.
	/// </summary>
	/// <param name="message">The message.</param>
	virtual void Notify(const std::string& message) = 0;

};