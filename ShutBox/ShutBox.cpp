#include "ShutBox.h"

ShutBox::ShutBox(std::function<void(std::array<bool, 9>& brd)> cbPrintBrd, std::function<bool(std::array<bool, 9>& brd, int diceVal)>& cbGetInput) : board{true, true, true, true, true, true, true, true, true}
{
	cb_printBoardState = cbPrintBrd;
	cb_GetInput = cbGetInput;
}

ShutBox::~ShutBox()
{
}

int ShutBox::Start()
{
	while (shouldContinue())
	{
		cb_printBoardState(board);
		cb_GetInput(board, 6);
		//system("pause");
		system("cls");
	}

	return 0;
}

bool ShutBox::shouldContinue()
{
	return true;
}