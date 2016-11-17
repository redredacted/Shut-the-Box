#pragma once
#include <array>
#include <vector>
#include <functional>
#include <random>

typedef std::array<bool, 9> ShutBoard;
typedef std::vector<int> ShutNum;
typedef std::function<void(ShutBoard& brd)> DispBrdFn;
typedef std::function<ShutNum(ShutBoard& brd, int diceVal)> InputFn;
typedef std::function<void()> DispRndFn;
typedef std::function<int()> GetDiceAmt;

class ShutBox
{
public:
	ShutBox(DispBrdFn& cbPrintBrd, InputFn& cbGetInput, DispRndFn& cbDispRnd, GetDiceAmt& cbGetDiceAmt);
	~ShutBox();
	int Start();
	static ShutNum boardToNum(ShutBoard& brd, bool invert);
	static bool isMatch(ShutNum& choice, int diceVal);
private:
	int diceResult;
	ShutBoard board;
	std::mt19937 rng;
	std::uniform_int_distribution<std::mt19937::result_type> dist{ 1,6 };
	DispBrdFn cb_printBoardState;
	InputFn cb_GetInput;
	DispRndFn cb_DispRnd;
	GetDiceAmt cb_GetDiceAmt;
	void rollDice(int diceToRoll);
	bool shouldContinue(ShutNum& v, int sum);
	int calcScore();
};

