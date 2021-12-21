#pragma once
#include <string>
#include <functional>
#include <fstream>
#include <vector>
#include <map>
#include "StackMachine.h"

namespace StackMachineImplementation
{
	class StackMachineFileHandler : public StackMachine
	{
	public:
		StackMachineFileHandler(const std::string& filePath);
		~StackMachineFileHandler();

		void StartParsing();

		void AddExternalFunction(std::string functionName, std::function<void(Stack*)> function);

	private:
		std::map<std::string, std::vector<std::string>>* _functions;
		std::map<std::string, std::function<void(Stack*)>>* _externalFunctions;
		std::map<std::string, int>* _variables;

		void ParseFunction(std::string functionName);
		void FindLabel(std::vector<std::string>& commands, std::string label, int& index);

		void HandleFile(const std::string& filePath);
		void ReadFile(std::ifstream& fileStream);
		void ReadFunction(std::ifstream& fileStream, std::string& current);
		void SkipComment(std::ifstream& fileStream, std::string& current);
		void ReadUntilToken(std::string token, std::ifstream& fileStream, std::string current, std::vector<std::string>& commands);
		bool IsValidVariableName(std::string& variableName);
		bool IsVariableExists(std::string& variableName);
		static bool Contains(std::string& source, std::string token);
		static bool EqualsOrdinal(const std::string& left, const std::string& right);
	};
}