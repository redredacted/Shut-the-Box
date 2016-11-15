#pragma once
#include <array>
#include <functional>
class ShutBox
{
public:
	ShutBox(std::function<void(std::array<bool, 9>& brd)> cbPrintBrd, std::function<bool(std::array<bool, 9>& brd, int diceVal)>& cbGetInput);
	~ShutBox();
	int Start();
private:
	std::array<bool, 9> board;
	std::function<void(std::array<bool, 9>& brd)> cb_printBoardState;
	std::function<bool(std::array<bool, 9>& brd, int diceVal)> cb_GetInput;
	bool shouldContinue();
};

