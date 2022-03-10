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

        Demon d(Sc, Tr, Sr, Na, fragments);
        demons.push_back(d);
    }

    return demons;
}
