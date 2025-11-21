#include "Chromosome.hpp"
#include "Utils.hpp"

Chromosome::Chromosome(int length) : fitness_(0.0), sequence_(length)
{
    for (int &g : sequence_)
    {
        g = generateRandomNumber(0, 100);
    }
}

void Chromosome::print()
{
    for (const auto &v : sequence_)
    {
        std::cout << v << " ";
    }
    std::cout << ", fitness: " << fitness_ << std::endl;
}

double Chromosome::evaluateFitness(const std::vector<int> &target)
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

void Chromosome::mutate()
{
    for (int i = 0; i < sequence_.size(); i++)
    {
        if (generateRandomNumber(0, 100) > 50)
        {
            sequence_[i] = generateRandomNumber(0, 100);
        }
    }
}

void Chromosome::crossover(const Chromosome &a, const Chromosome &b)
{
    for (int i = 0; i < sequence_.size(); i++)
    {
        sequence_[i] = (sequence_[i] > 50) ? a.sequence_[i] : b.sequence_[i];
    }
}