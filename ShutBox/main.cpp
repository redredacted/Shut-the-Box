#include <iostream>
#include <functional>
#include "ShutBox.h"

void printBoard(std::array<bool, 9>& brd)
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

bool getInput(std::array<bool, 9>& brd, int diceVal)
{
	int index{};
	//std::cout << "Please insert any combination of number(s) bewtween 1 and 9 that will add up too " << diceVal;
	std::cin >> index;
	brd.at(index - 1) = !brd.at(index - 1);

	return false;
}

int main()
{
	std::function<void(std::array<bool, 9>&)> pb = printBoard;
	std::function<bool(std::array<bool, 9>&, int)> gi = getInput;
	ShutBox round1(pb, gi);
	round1.Start();

	system("pause");
	return 0;
}