#include "pch.h"
#include "Logger.h"
#include "ISubject.h"
#include <iostream>

Logger::Logger(ISubject* subject)
{
	subject->Subscribe(this);
}

void Logger::Update(const std::string& message)
{
	std::cout << "LOG: " << message;
}
