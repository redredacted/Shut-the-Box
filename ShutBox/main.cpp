#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include "ShutBox.h"

void printBoard(ShutBoard& brd)
{
	for (size_t i = 0; i < 9; i++)
	{
		if (brd.at(i) == true)
		{
			std::cout << i + 1 << " ";
		}
		else
		{
			std::cout << "X ";
		}
	}
	std::cout << std::endl;
}

void getInput(ShutBoard& brd, int diceVal)
{
	std::string input;
	int index{};

	for (size_t i = 0; i < 3; i++)
	{
		while (true)
		{
			std::cout << "Enter a number bewtween 1 and 9: ";
			std::getline(std::cin, input);
			std::stringstream strm{ input };

			if (strm >> index && index < 10 && index > 0)
				break;

			if (i != 0 && index < 0)
				break;

			system("cls");
			std::cout << "Input must be bewtween 1 and 9" << std::endl;
			system("pause");
			system("cls");
			printBoard(brd);
		}

		if (index < 0)
			break;

		brd.at(index - 1) = !brd.at(index - 1);
	}
}

int main()
{
	ShutOutFn pb = printBoard;
	ShutInFn gi = getInput;
	ShutBox round1(pb, gi);
	round1.Start();

	system("pause");
	return 0;
}