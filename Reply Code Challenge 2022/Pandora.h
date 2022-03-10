#pragma once
#include <iostream>
#include <vector>

struct recovering_stamina
{
	int remaining_turns;
	int stamina;
};

class Pandora {
	private:
		int currentStamina;
		int maxStamina;
		int Turns;
		std::vector<recovering_stamina> rs;
	public:
		Pandora(int currentStamina, int maxStamina, int Turns);
		void setCurrentStamina(int stamina);
		int getCurrentStamina(void);
		int getMaxStamina(void);
		int getTurns(void);
		std::string toString(void);
		void addRecoveringStamina(int remaining_turns, int stamina);
		void recoverStamina();
		bool testRecoverStamina(int neededStamina);
};