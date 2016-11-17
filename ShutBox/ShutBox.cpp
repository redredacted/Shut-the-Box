#include "ShutBox.h"

ShutBox::ShutBox(DispBrdFn& cbPrintBrd, InputFn& cbGetInput, DispRndFn& cbDispRnd) : board{
	true, true, true, true, true, true, true, true, true }
{
	cb_printBoardState = cbPrintBrd;
	cb_GetInput = cbGetInput;
	cb_DispRnd = cbDispRnd;
	rng.seed(std::random_device()());
}

ShutBox::~ShutBox()
{
}

int ShutBox::Start()
{
	ShutNum input{};
	input.reserve(3);

	while (true)
	{
		rollDice(2);

		//cb_printBoardState(board, diceResult);
		ShutNum input = cb_GetInput(board, diceResult);
		if (ShutBox::isMatch(input, diceResult))
		{
			for (size_t i = 0; i < input.size(); i++)
			{
				board.at(input.at(i) - 1) = false;
			}

			cb_DispRnd();
		}

		if (!shouldContinue(boardToNum(board, false), diceResult))
			break;
	}

	cb_printBoardState(board);
	return calcScore();
}

bool ShutBox::shouldContinue(ShutNum& v, int sum)
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

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = MAX_ELEMENT*MAX_ELEMENT_VALUE; j >= 0; j--)
		{
			if (j - v.at(i) < 0) continue;
			if (dp[j - v.at(i)]) dp[j] = 1;
		}
	}

	return dp[sum] ? true : false;
}

ShutNum ShutBox::boardToNum(ShutBoard& brd, bool invert)
{
	std::vector<int> numOut;
	numOut.reserve(9);

	for (size_t i = 0; i < 9; i++)
	{
		if (invert)
		{
			if (brd.at(i) == false)
				numOut.push_back(i + 1);
		}
		else
		{
			if (brd.at(i) == true)
				numOut.push_back(i + 1);
		}
	}

	return numOut;
}

void ShutBox::rollDice(int diceToRoll)
{
	int tot{};

	for (size_t i = 0; i < diceToRoll; i++)
	{
		tot += dist(rng);
	}

	diceResult = tot;
}


// returns true if the items in the vector add up to diceVal
bool ShutBox::isMatch(ShutNum& choice, int diceVal)
{
	int total{};

	for (size_t i = 0; i < choice.size(); i++)
	{
		total += choice.at(i);
	}

	if (total == diceVal)
		return true;

	return false;
}


int ShutBox::calcScore()
{
	int score{};
	ShutNum scoreVec = boardToNum(board, false);

	for (size_t i = 0; i < scoreVec.size(); i++)
	{
		score += scoreVec.at(i);
	}

	return score;
}
