#pragma once
#include <array>
#include <functional>

typedef std::function<void(std::array<bool, 9>& brd)> ShutOutFn;
typedef std::function<void(std::array<bool, 9>& brd, int diceVal)> ShutInFn;
typedef std::array<bool, 9> ShutBoard;

class ShutBox
{
public:
	ShutBox(ShutOutFn& cbPrintBrd, ShutInFn& cbGetInput);
	~ShutBox();
	int Start();
private:
	ShutBoard board;
	ShutOutFn cb_printBoardState;
	ShutInFn cb_GetInput;
	bool shouldContinue();
};

