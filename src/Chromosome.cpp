#include "Chromosome.hpp"
#include "Utils.hpp"
#include "Constants.hpp"

Chromosome::Chromosome(int length) : fitness_(0.0), sequence_("")
{
    for (int i = 0; i < length; i++)
    {
        sequence_ += getRandomChar();
    }
}

void Chromosome::print()
{
    for (const auto &v : sequence_)
    {
        std::cout << v << "";
    }
    std::cout << ", fitness: " << fitness_ << std::endl;
}

double Chromosome::evaluateFitness(const std::string &target)
{
    fitness_ = sequence_.size();
    for (int i = 0; i < sequence_.size(); i++)
    {
        if (sequence_[i] == target[i])
        {
            fitness_--;
        }
    }
    return fitness_;
}

void Chromosome::mutate(int min_value, int max_value, double mutation_rate)
{
    for (auto &g : sequence_)
    {
        if ((rand() / double(RAND_MAX)) < mutation_rate)
        {
            g = getRandomChar();
        }
    }
}

void Chromosome::crossover(const Chromosome &a, const Chromosome &b)
{
    int n = sequence_.size();
    int point = rand() % n;

    for (int i = 0; i < n; i++)
    {
        if (i < point)
            sequence_[i] = a.sequence_[i];
        else
            sequence_[i] = b.sequence_[i];
    }
}