#pragma once
#include <string>
#include "ISubject.h"

/// <summary>
/// Logger for StackMachine.
/// </summary>
/// <seealso cref="IObserver" />
class Logger : public IObserver
{
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="Logger"/> class.
	/// </summary>
	/// <param name="subject">The subject.</param>
	Logger(ISubject* subject);

	/// <summary>
	/// Updates some info.
	/// </summary>
	/// <param name="message">The message.</param>
	void Update(const std::string& message) override;
};