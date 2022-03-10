#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Pandora.h"
#include "Demon.h"

Pandora read_parameters(std::ifstream* input, int& number_of_demons);
std::vector<Demon> read_demons(std::ifstream* input, int number_of_demons);
std::vector<int> fight_demons(Pandora& p, std::vector<Demon>& demons);
void write_output(char* file_name, std::vector<int> defeated_demons);

int main(int argc, char* argv[])
{
    assert(argc == 2);

    std::ifstream input(argv[1]);
    if (!input.is_open())
    {
        std::cerr << "Cannot open input file." << std::endl;
        return -1;
    }

    int number_of_demons;
    Pandora p = read_parameters(&input, number_of_demons);
    std::vector<Demon> demons = read_demons(&input, number_of_demons);
    input.close();

    std::vector<int> defeated_demons = fight_demons(p, demons);
    write_output(argv[1], defeated_demons);

    return 0;
}

Pandora read_parameters(std::ifstream* input, int& number_of_demons)
{
    assert(input->is_open() && !input->eof());

    std::string line;

    std::getline(*input, line);
    std::stringstream ss(line);

    int Si, Smax, T;
    ss >> Si >> Smax >> T >> number_of_demons;
    
    Pandora p(Si, Smax, T);
    return p;
}

std::vector<Demon> read_demons(std::ifstream* input, int number_of_demons)
{
    assert(input->is_open() && !input->eof());
    
    std::vector<Demon> demons;
    std::string line;
    int Sc, Tr, Sr, Na, fragment;
    
    for (int i = 0; i < number_of_demons; ++i)
    {
        std::getline(*input, line);
        std::stringstream ss(line);
        std::vector<int> fragments;

        ss >> Sc >> Tr >> Sr >> Na;

        for (int j = 0; j < Na; ++j)
        {
            ss >> fragment;
            fragments.push_back(fragment);
        }

        Demon d(i, Sc, Tr, Sr, Na, fragments);
        demons.push_back(d);
    }

    return demons;
}

std::vector<int> fight_demons(Pandora& p, std::vector<Demon>& demons)
{
    std::vector<int> defeated_demons;
    int current_turn = 0;

    for (int i = 0; i < p.getTurns(); ++i, ++current_turn)
    {
        double max_score = -1;
        std::vector<Demon>::iterator best_choice = demons.end();
        std::cout << "Turn " << i << std::endl;
        for (auto i = demons.begin(); i != demons.end(); ++i)
        {
            double score;
            if (current_turn == 0)
            {
                if (i->getStaminaCost() > p.getCurrentStamina())
                    score = 0;
                else
                    score = i->getScore(p.getTurns(), current_turn);
            }
            else
                score = i->getScore(p.getTurns(), current_turn);
            std::cout << score << std::endl;
            if (score > max_score)
            {
                if (p.getCurrentStamina() < i->getStaminaCost())
                    if (!p.testRecoverStamina(i->getStaminaCost()))
                        continue;
                max_score = score;
                best_choice = i;
            }
        }

        if (best_choice == demons.end())
            break;

        defeated_demons.push_back(best_choice->getId());
        demons.erase(best_choice);
        std::cout << "-----------------------------" << std::endl;
    }

    return defeated_demons;
}

void write_output(char* file_name, std::vector<int> defeated_demons)
{
    std::string output_file_name(file_name);
    std::ofstream output(output_file_name + "_output.txt");
    if (!output.is_open())
    {
        std::cerr << "Cannout open output file." << std::endl;
        for (int i : defeated_demons)
            std::cout << i << std::endl;
    }
    else
    {
        for (int i : defeated_demons)
            output << i << std::endl;
        output.close();
    }
}
