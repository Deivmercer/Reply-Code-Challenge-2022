#pragma once
#include <vector>
#ifndef DEMON_H
#define DEMON_H

class Demon
{
	public:
		Demon();
		Demon(int n, int sc, int tn, int sr, int ft, std::vector<int> fn);
		~Demon();
		int getId();
		int getTurns();
		int getStaminaCost();
		int getStaminaRecovered();
		int getFragmentsTurn();
		std::vector<int> getFragmentsNumber();
		double getScore(int total_turns, int current_turn);
	private:
		int id;
		int staminaCost;
		int turnsNumber;
		int staminaRecovered;
		int fragmentsTurn;
		std::vector<int> fragmentsNumber;
};

#endif