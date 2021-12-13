#pragma once
#include <string>
#include "ISubject.h"

class Logger : public IObserver
{
public:
	Logger(ISubject* subject);

	void Update(const std::string& message) override;
};