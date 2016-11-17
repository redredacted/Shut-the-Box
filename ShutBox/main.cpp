#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <vector>
#include <algorithm>
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

ShutNum getInput(ShutBoard& brd, int diceVal)
{
	std::string input;
	ShutNum idx{};
	idx.reserve(3);
	int index{};

	while (true)
	{
		int i = idx.size();

		while (true)
		{
			printBoard(brd);
			std::cout << "diceVal is " << diceVal << std::endl;
			std::cout << "Enter a number bewtween 1 and 9: ";
			std::getline(std::cin, input);
			std::stringstream strm{ input };

			if (strm >> index && index < 10 && index > 0 && brd.at(index - 1) == true && !(std::find(idx.begin(), idx.end(), index) != idx.end()))
				break;

			// thing after && returns true if value of index is in vector idx
			if (brd.at(index - 1) == false || std::find(idx.begin(), idx.end(), static_cast<int>(index)) != idx.end())
			{
				std::cout << "That number has already been set" << std::endl;
			}
			else
			{
				std::cout << "Input must be bewtween 1 and 9" << std::endl;
			}
			system("pause");
		}

		idx.push_back(index);

		if (ShutBox::isMatch(idx, diceVal))
			break;
	}
	return idx;
}

void dispRound()
{
	std::cout << "diceVal was matched by player" << std::endl;
	system("pause");
}

int main()
{
	DispBrdFn pb = printBoard;
	InputFn gi = getInput;
	DispRndFn dr = dispRound;
	ShutBox round1(pb, gi, dr);
	std::cout << "You Scored: " << round1.Start() << std::endl;

	system("pause");
	return 0;
}