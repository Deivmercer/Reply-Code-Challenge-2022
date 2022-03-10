#include <iostream>
#include "Pandora.h"
#include <string>

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

void Pandora::setCurrentStamina(int stamina) {
	currentStamina += stamina;
}

std::string Pandora::toString(void) {
	return "Current stamina: " + std::to_string(getCurrentStamina()) + 
			" Max stamina: " + std::to_string(getMaxStamina()) + 
			" Turns: " + std::to_string(getTurns());
}

void Pandora::addRecoveringStamina(int remaining_turns, int stamina)
{
	recovering_stamina rec_stam;
	rec_stam.remaining_turns = remaining_turns;
	rec_stam.stamina = stamina;
	rs.push_back(rec_stam);
}

void Pandora::recoverStamina()
{
	std::vector<std::vector<recovering_stamina>::iterator> to_remove;

	for (auto i = rs.begin(); i != rs.end(); ++i)
	{
		i->remaining_turns -= 1;

		if (i->remaining_turns == 0)
		{
			currentStamina += i->stamina;
			to_remove.push_back(i);
		}
	}

	for (auto it : to_remove)
	{
		rs.erase(it);
	}
}

bool Pandora::testRecoverStamina(int neededStamina)
{
	std::vector<recovering_stamina> backup_rs = rs;
	int stamina = currentStamina;

	while (!backup_rs.empty() && neededStamina > stamina)
	{
		std::vector<std::vector<recovering_stamina>::iterator> to_remove;

		for (auto i = backup_rs.begin(); i != backup_rs.end(); ++i)
		{
			i->remaining_turns -= 1;

			if (i->remaining_turns == 0)
			{
				stamina += i->stamina;
				to_remove.push_back(i);
			}
		}

		for (auto it : to_remove)
		{
			backup_rs.erase(it);
		}
	}

	return neededStamina > stamina;
}
