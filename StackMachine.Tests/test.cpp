#include "pch.h"
#include "../StackMachine/Stack.h"
#include "../StackMachine/StackMachine.h"
#include "../StackMachine/CustomExceptions.h"
#include "../StackMachine//StackMachineFileHandler.h"

using namespace StackMachineImplementation;

TEST(StackTests, Peek_Tests) 
{
	Stack stack;
	for (int i = 0; i < 100; i++)
	{
		stack.Push(i);
		ASSERT_EQ(stack.Peek(), i);
	}
}

TEST(StackTests, Stack_Pop_Throws_Exception)
{
	Stack stack;

	ASSERT_ANY_THROW(stack.Pop());
}

TEST(StackTests, Peek_Pop_Count_Duplicate_Tests)
{
	Stack stack;
	int initial = 10;
	stack.Push(initial);

	for (int i = 0; i < 100; i++)
	{
		stack.Duplicate();
		ASSERT_EQ(initial, stack.Peek());
		ASSERT_EQ(i + 2, stack.Count());
	}

	int size = stack.Count();
	for (int i = 0; i < size; i++)
	{
		ASSERT_EQ(stack.Pop(), initial);
	}


	ASSERT_EQ(stack.Count(), 0);
}

TEST(StackMachineTests, Mul_Tests)
{
	StackMachine machine;
	machine.Push(35);
	machine.Push(123);
	machine.Multiply();
	ASSERT_EQ(machine.Count(), 1);
	ASSERT_EQ(machine.Peek(), 35 * 123);
}

TEST(StackMachineTests, Div_Tests_Throw_Exception)
{
	StackMachine machine;
	machine.Push(10);
	machine.Push(0);

	ASSERT_ANY_THROW(machine.Divide());
}

TEST(StackMachineTests, Sub_Tests)
{
	StackMachine machine;
	machine.Push(40);
	machine.Push(100);
	machine.Substract();

	ASSERT_EQ(machine.Peek(), -60);
}

TEST(StackMachineTests, AddTests)
{
	StackMachine machine;
	machine.Push(6);
	machine.Push(25);
	machine.Add();
	ASSERT_EQ(31, machine.Peek());
}

TEST(StackMachineTests, Div_Tests)
{
	StackMachine machine;
	machine.Push(12);
	machine.Push(4);
	machine.Divide();
	ASSERT_EQ(machine.Peek(), 3);
}

