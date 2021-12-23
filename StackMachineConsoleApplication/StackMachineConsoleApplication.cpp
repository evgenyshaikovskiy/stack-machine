// StackMachineConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../StackMachine/StackMachine.h"
#include "../StackMachine/Logger.h"
#include "../StackMachine/StackMachineFileHandler.h"
#include "../StackMachine/CustomExceptions.h"

using namespace StackMachineImplementation;

void Print(Stack* stack)
{
    std::cout << "Stack top: " << stack->Pop() << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 3 && argc != 2)
    {
        std::cout << "Invalid command line parameters.";
        throw std::exception();
    }

    StackMachineFileHandler handler(argv[1]);
    handler.AddExternalFunction("print", Print);
    Logger* logger;
    if (argc == 3)
    {
        if (std::strcmp(argv[2], "-debug") == 0)
        {
            logger = new Logger(&handler);
        }
        else
        {
            std::cout << "Invalid second argument.";
            throw std::exception();
        }
    }

    try
    {
        handler.StartParsing();
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception:" << ex.what() << std::endl;
    }

    return 0;
}
