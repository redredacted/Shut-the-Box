#include "ShutBox.h"

ShutBox::ShutBox(ShutOutFn& cbPrintBrd, ShutInFn& cbGetInput) : board{true, true, true, true, true, true, true, true, true}
{
	cb_printBoardState = cbPrintBrd;
	cb_GetInput = cbGetInput;
}

ShutBox::~ShutBox()
{
}

int ShutBox::Start()
{
	ShutBoard temp = board;
	while (shouldContinue())
	{
		cb_printBoardState(temp);
		cb_GetInput(temp, 6);
		system("cls");
	}

	return 0;
}

bool ShutBox::shouldContinue()
{

	return true;
}