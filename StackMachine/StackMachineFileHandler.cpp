#include "pch.h"
#include "StackMachineFileHandler.h"
#include "CustomExceptions.h"
#include <iostream>
#include <map>
#include <string>

namespace StackMachineImplementation
{
	StackMachineFileHandler::StackMachineFileHandler(const std::string& filePath)
	{
		_functions = new std::map<std::string, std::vector<std::string>>;
		_externalFunctions = new std::map<std::string, std::function<void(Stack*)>>;
		_variables = new std::map<std::string, int>;

		this->HandleFile(filePath);
	}

	StackMachineFileHandler::~StackMachineFileHandler()
	{
		delete _functions;
		delete _externalFunctions;
		delete _variables;
	}

	void StackMachineFileHandler::StartParsing()
	{
		// parsing begins within main function
		this->ParseFunction("main");
	}

	void StackMachineFileHandler::AddExternalFunction(std::string functionName, std::function<void(Stack*)> function)
	{
		_externalFunctions->insert(std::pair<std::string, std::function<void(Stack*)>>(functionName, function));
	}

	void StackMachineFileHandler::ParseFunction(std::string functionName)
	{
		if (_functions->find(functionName) == _functions->end())
		{
			this->Notify("Exception: FunctionNotFoundException.\n");
			throw FunctionNotFoundException(functionName);
		}

		this->Notify("Call function \"" + functionName + "\".\n");
		std::vector<std::string> commands = this->_functions->find(functionName)->second;

		// can't use switch operator :(
		for (int i = 0; i < commands.size(); i++)
		{
			if (commands[i] == "push")
			{
				std::string name = commands[++i];

				int value;
				
				if (IsVariableExists(name))
				{
					// go for next command
					value = _variables->find(name)->second;
				}
				else
				{
					value = std::stoi(name);
				}

				this->Push(value);
			}
			else if (commands[i] == "pop")
			{
				std::string name = commands[i + 1];

				int value = this->Pop();
				// no variable 
				if (IsValidVariableName(name))
				{
					i++;
					if (!IsValidVariableName(name))
					{
						_variables->insert(std::make_pair(name, value));
					}
					else
					{
						_variables->find(name)->second = value;
					}
				}
			}
			else if (commands[i] == "dup")
			{
				this->Duplicate();
			}
			else if (commands[i] == "peek")
			{
				std::string name = commands[i + 1];

				int value = this->Peek();
				// no variable 
				if (IsValidVariableName(name))
				{
					i++;
					if (!IsValidVariableName(name))
					{
						_variables->insert(std::make_pair(name, value));
					}
					else
					{
						_variables->find(name)->second = value;
					}
				}
			}
			else if (commands[i] == "add")
			{
				this->Add();
			}
			else if (commands[i] == "sub")
			{
				this->Substract();
			}
			else if (commands[i] == "mul")
			{
				this->Multiply();
			}
			else if (commands[i] == "div")
			{
				this->Divide();
			}
			else if (commands[i] == "call")
			{
				this->ParseFunction(commands[++i]);
			}
			else if (commands[i] == "ifeq")
			{
				int right = this->Pop();
				int left = this->Pop();

				this->Notify("Comparing numbers " + std::to_string(left) + " with number " + std::to_string(right) + ".\n");
				if (left == right)
				{
					this->Notify("Number are equal.");
					this->FindLabel(commands, commands[++i], i);
				}
			}
			else if (commands[i] == "goto")
			{
				this->FindLabel(commands, commands[++i], i);
			}
			else if (commands[i] == "ifgr")
			{
				int left = this->Pop();
				int right = this->Pop();

				this->Notify("Compare number " + std::to_string(left) + " to number " + std::to_string(right) + ".\n");
				if (left > right)
				{
					this->Notify("Greater.");
					this->FindLabel(commands, commands[++i], i);
				}
			}
			else if (commands[i] == "return")
			{
				this->Notify("Return from function \"" + functionName + "\".\n");
				return;
			}
			else if (commands[i] == "callext")
			{
				this->Notify("Looking for external function \"" + commands[++i] + "\".\n");
				if (_externalFunctions->find(commands[i]) == _externalFunctions->end())
				{
					this->Notify("Exception: ExternalFunctionNotFoundException.\n");
					throw ExternalFunctionNotFoundException(commands[i]);
				}

				this->Notify("Invoke extrenal function \"" + commands[i] + "\".\n");
				std::function<void(Stack*)> externalFunction = _externalFunctions->find(commands[i])->second;
				externalFunction(this);
			}
		}

		this->Notify("Exception: NotAllCodePathsReturnValue.\n");
		throw NotAllCodePathsReturnAValueException(functionName);
	}

	void StackMachineFileHandler::FindLabel(std::vector<std::string>& commands, std::string labelName, int& index)
	{
		this->Notify("Looking for label \"" + labelName + "\".\n");
		std::string label = labelName + ":";

		while (index < commands.size() && commands[index] != label)
		{
			index++;
		}

		if (index == commands.size())
		{
			this->Notify("Exception: LabelNotFoundException.\n");
			throw LabelNotFoundException(labelName);
		}

		this->Notify("At label \"" + labelName + "\".\n");
	}

	void StackMachineFileHandler::HandleFile(const std::string& filePath)
	{
		std::ifstream fileStream(filePath);

		if (!fileStream.is_open())
		{
			this->Notify("Exception: FileNotFoundException.\n");
			throw FileNotFoundException(filePath);
		}
		else
		{
			this->ReadFile(fileStream);
		}

		fileStream.close();
	}

	void StackMachineFileHandler::ReadFile(std::ifstream& fileStream)
	{
		std::string current;

		while (!fileStream.eof())
		{
			fileStream >> current;

			if (current == "function")
			{
				this->ReadFunction(fileStream, current);
			}
		}
	}

	void StackMachineFileHandler::ReadFunction(std::ifstream& fileStream, std::string& current)
	{
		const std::string beginning = "{";
		const std::string end = "}";

		fileStream >> current;
		std::string currentString;
		std::vector<std::string> commands;
		fileStream >> currentString;

		while (currentString != beginning && !fileStream.eof())
		{
			fileStream >> currentString;
		}

		fileStream >> currentString;

		this->ReadUntilToken(end, fileStream, currentString, commands);

		_functions->insert(std::pair < std::string, std::vector<std::string>>(current, commands));
	}

	void StackMachineFileHandler::SkipComment(std::ifstream& fileStream, std::string& current)
	{
		const std::string commentToken = "#";

		while (current == commentToken)
		{
			while (fileStream.peek() != '\n')
			{
				fileStream >> current;
			}

			fileStream >> current;
		}
	}

	void StackMachineFileHandler::ReadUntilToken(std::string token, std::ifstream& fileStream, std::string current, std::vector<std::string>& commands)
	{
		while (current != token && !fileStream.eof())
		{
			this->SkipComment(fileStream, current);
			commands.push_back(current);
			fileStream >> current;
		}
	}

	bool StackMachineFileHandler::IsValidVariableName(std::string& variableName)
	{
		// check whether name is valid
		if (_externalFunctions->find(variableName) != _externalFunctions->end()
			|| _functions->find(variableName) != _functions->end())
		{
			this->Notify("Exception: Invalid variable name.\n");
			throw InvalidVariableNameException(variableName);
		}

		if (Contains(variableName, "0123456789")
			|| EqualsOrdinal(variableName, "push")
			|| EqualsOrdinal(variableName, "pop")
			|| EqualsOrdinal(variableName, "peek")
			|| EqualsOrdinal(variableName, "sub")
			|| EqualsOrdinal(variableName, "callext")
			|| EqualsOrdinal(variableName, "return")
			|| EqualsOrdinal(variableName, "dup")
			|| EqualsOrdinal(variableName, "add")
			|| EqualsOrdinal(variableName, "mul")
			|| EqualsOrdinal(variableName, "div")
			|| EqualsOrdinal(variableName, "call")
			|| EqualsOrdinal(variableName, "ifgr")
			|| EqualsOrdinal(variableName, "goto")
			|| EqualsOrdinal(variableName, "ifeq")
			)
		{
			return false;
		}




		return true;
	}

	bool StackMachineFileHandler::IsVariableExists(std::string& variableName)
	{
		return _variables->find(variableName) != _variables->end();
	}

	bool StackMachineFileHandler::Contains(std::string& source, std::string token)
	{
		for (int i = 0; i < token.size(); i++)
		{
			if (find(source.begin(), source.end(), token[i]) != source.end())
			{
				return true;
			}
		}

		return false;
	}

	bool StackMachineFileHandler::EqualsOrdinal(const std::string& left, const std::string& right)
	{
		return std::equal(left.begin(), left.end(),
			right.begin(), right.end(),
			[](char l, char r)
			{
				return tolower(l) == tolower(r);
			});
	}
}


