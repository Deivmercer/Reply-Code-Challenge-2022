#include "Demon.h"
#include <vector>

Demon::Demon() : staminaCost(0), turnsNumber(0), staminaRecovered(0), fragmentsTurn(0), fragmentsNumber()
{
};

Demon::Demon(int sc, int tn, int sr, int ft, std::vector<int> fn) : staminaCost(sc), turnsNumber(tn), staminaRecovered(sr), fragmentsTurn(ft), fragmentsNumber(fn)
{
};

Demon::~Demon()
{
};

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