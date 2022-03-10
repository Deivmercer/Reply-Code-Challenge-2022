#include <iostream>
#include "Pandora.h"
#include <string>


using namespace std;

Pandora::Pandora(int currentStamina, int maxStamina, int Turns) {
	this->currentStamina = currentStamina;
	this->maxStamina = maxStamina;
	this->Turns = Turns;
}

int Pandora::getCurrentStamina(void) {
	return currentStamina;
}

int Pandora::getMaxStamina(void) {
	return maxStamina;
}

int Pandora::getTurns(void) {
	return Turns;
}

int Pandora::setCurrentStamina(int stamina) {
	currentStamina += stamina;
}

string Pandora::toString(void) {
	return "Current stamina: " + to_string(getCurrentStamina()) + 
			" Max stamina: " + to_string(getMaxStamina()) + 
			" Turns: " + to_string(getTurns());
}