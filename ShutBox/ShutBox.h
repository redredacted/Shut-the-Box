#pragma once
#include <array>
#include <functional>

typedef std::function<void(std::array<bool, 9>& brd)> ShutOutFn;
typedef std::function<bool(std::array<bool, 9>& brd, int diceVal)> ShutInFn;

class ShutBox
{
public:
	ShutBox(ShutOutFn& cbPrintBrd, ShutInFn& cbGetInput);
	~ShutBox();
	int Start();
private:
	std::array<bool, 9> board;
	ShutOutFn cb_printBoardState;
	ShutInFn cb_GetInput;
	bool shouldContinue();
};

