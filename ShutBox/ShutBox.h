#pragma once
#include <array>
#include <functional>
#include <random>
//debug stuff below
#include <iostream>

typedef std::function<void(std::array<bool, 9>& brd)> ShutFn;
typedef std::function<void(std::array<bool, 9>& brd, int diceVal)> ShutSetFn;
typedef std::array<bool, 9> ShutBoard;
typedef std::array<int, 9> ShutNum;

class ShutBox
{
public:
	ShutBox(ShutFn& cbPrintBrd, ShutSetFn& cbGetInput);
	~ShutBox();
	int Start();
	static ShutNum boardToNum(ShutBoard& brd);
private:
	ShutBoard board;
	ShutFn cb_printBoardState;
	ShutSetFn cb_GetInput;
	bool shouldContinue(std::array<int, 9>& v, int sum);
	std::mt19937 rng;
	std::uniform_int_distribution<std::mt19937::result_type> dist{1,7};
	int rollDice();
};

