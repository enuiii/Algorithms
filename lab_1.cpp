#include <iostream>
#include <stack>
#include <string>

bool isExpressionValid(const std::string& expression)
{
	std::stack<char> bracketsStack;

	for (char bracket : expression)
	{
		if (bracket == '(' || bracket == '{' || bracket == '[')
		{
			bracketsStack.push(bracket);
		}
		else if (bracket == ')' || bracket == '}' || bracket == ']')
		{
			if (bracketsStack.empty())
			{
				return false;
			}
			char topBracket = bracketsStack.top();
			bracketsStack.pop();
			if (bracket == ')' && topBracket != '(' || bracket == '}' && topBracket != '{' || bracket == ']' && topBracket != '[')
			{
				return false;
			}
		}
	}
	return bracketsStack.empty();
}

int main()
{
	setlocale(0, "");

	std::cout << "Введите строку: ";
	std::string input;
	std::cin >> input;

	if (isExpressionValid(input))
	{
		std::cout << "Строка существует" << std::endl;
	}
	else
	{
		std::cout << "Строка не существует" << std::endl;
	}

	return 0;
}