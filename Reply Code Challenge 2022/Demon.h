#pragma once
#include <vector>
#ifndef DEMON_H
#define DEMON_H

class Demon
{
	public:
		Demon();
		Demon(int sc, int tn, int sr, int ft, std::vector<int> fn);
		~Demon();
		int getTurns();
		int getStaminaCost();
		int getStaminaRecovered();
		int getFragmentsTurn();
		std::vector<int> getFragmentsNumber();
	private:
		int staminaCost;
		int turnsNumber;
		int staminaRecovered;
		int fragmentsTurn;
		std::vector<int> fragmentsNumber;
};

#endif