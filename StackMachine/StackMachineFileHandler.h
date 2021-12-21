#pragma once
#include <string>
#include <functional>
#include <fstream>
#include <vector>
#include <map>
#include "StackMachine.h"

namespace StackMachineImplementation
{
	/// <summary>
	/// Stack machine handler.
	/// </summary>
	/// <seealso cref="StackMachine" />
	class StackMachineFileHandler : public StackMachine
	{
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="StackMachineFileHandler"/> class.
		/// </summary>
		/// <param name="filePath">The file path.</param>
		StackMachineFileHandler(const std::string& filePath);

		/// <summary>
		/// Finalizes an instance of the <see cref="StackMachineFileHandler"/> class.
		/// </summary>
		~StackMachineFileHandler();

		/// <summary>
		/// Start parsing from file.
		/// </summary>
		void StartParsing();

		/// <summary>
		/// Adds the external function.
		/// </summary>
		/// <param name="functionName">Name of the function.</param>
		/// <param name="function">The function.</param>
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