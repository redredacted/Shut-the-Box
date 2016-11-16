#include "ShutBox.h"

ShutBox::ShutBox(ShutFn& cbPrintBrd, ShutSetFn& cbGetInput) : board{true, true, true, true, true, true, true, true, true}
{
	cb_printBoardState = cbPrintBrd;
	cb_GetInput = cbGetInput;
	rng.seed(std::random_device()());
}

ShutBox::~ShutBox()
{
}

int ShutBox::Start()
{
	ShutBoard temp;
	int dice{};

	do
	{
		//following line of code does not produce intended functionality
		dice = rollDice() + rollDice();
		temp = board;
		cb_printBoardState(board);
		cb_GetInput(temp, dice);
	} while (shouldContinue(boardToNum(temp), dice));

	//debug
	std::cout << "There are no combinations of numbers remaining on the board that can add up to " << dice << std::endl;
	return 0;
}

bool ShutBox::shouldContinue(std::array<int, 9>& v, int sum)
{
	// https://en.wikipedia.org/wiki/Subset_sum_problem
	// http://www.cs.dartmouth.edu/~ac/Teach/CS105-Winter05/Notes/nanda-scribe-3.pdf
	// http://stackoverflow.com/a/27335046
	// try to figure out how this code works from above ^ I did not write got from above
	const int MAX_ELEMENT = 100;
	const int MAX_ELEMENT_VALUE = 1000;
	// i think the memset below sets all the array values to 0
	static int dp[MAX_ELEMENT*MAX_ELEMENT_VALUE + 1]; memset(dp, 0, sizeof(dp));

	dp[0] = 1;

	for (int i = 0; i < 9; i++)
	{
		for (int j = MAX_ELEMENT*MAX_ELEMENT_VALUE; j >= 0; j--)
		{
			if (j - v[i] < 0) continue;
			if (dp[j - v[i]]) dp[j] = 1;
		}
	}

	return dp[sum] ? true : false;
}

ShutNum ShutBox::boardToNum(ShutBoard& brd)
{
	std::array<int, 9> numOut;

	for (size_t i = 0; i < 9; i++)
	{
		if (brd.at(i) != true)
		{
			numOut.at(i) = i + 1;
		}
		else
		{
			numOut.at(i) = 0;
		}
	}

	return numOut;
}


int ShutBox::rollDice()
{
	return dist(rng);
}
