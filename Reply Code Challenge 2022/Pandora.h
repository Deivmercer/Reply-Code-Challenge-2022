#pragma once
#include <iostream>
using namespace std;
class Pandora {
	private:
	int currentStamina;
	int maxStamina;
	int Turns;
	public:
	Pandora(int currentStamina, int maxStamina, int Turns);
	void setCurrentStamina(int stamina);
	int getCurrentStamina(void);
	int getMaxStamina(void);
	int getTurns(void);
	string toString(void);

};