#include "Utils.hpp"
#include "Constants.hpp"

int generateRandomNumber(const int &min, const int &max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}

char getRandomChar()
{
    char c = Const::GENES[generateRandomNumber(0, Const::GENES.size())];
    return c;
}