#include "Demon.h"
#include <vector>

Demon::Demon() : staminaCost(0), turnsNumber(0), staminaRecovered(0), fragmentsTurn(0), fragmentsNumber()
{
};

Demon::Demon(int n, int sc, int tn, int sr, int ft, std::vector<int> fn) : id(n), staminaCost(sc), turnsNumber(tn), staminaRecovered(sr), fragmentsTurn(ft), fragmentsNumber(fn)
{
};

Demon::~Demon()
{
};

int Demon::getId()
{
	return id;
}

int Demon::getTurns()
{
	return turnsNumber;
}

int Demon::getStaminaCost()
{
	return staminaCost;
}

int Demon::getStaminaRecovered()
{
	return staminaRecovered;
}

int Demon::getFragmentsTurn()
{
	return fragmentsTurn;
}

std::vector<int> Demon::getFragmentsNumber()
{
	return fragmentsNumber;
};

double Demon::getScore(int total_turns, int current_turn)
{
	double score = 0;
	int remaining_turns = total_turns - current_turn;
	
	for (int i = 0; i < remaining_turns && i < fragmentsTurn; ++i)
		score += fragmentsNumber.at(i);

	score /= staminaCost;
	
	if (turnsNumber < remaining_turns) 
		score *= staminaRecovered;

	return score;
}
