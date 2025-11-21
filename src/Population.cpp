#include "Population.hpp"
#include "Utils.hpp"

void Population::initialisePopulation(int sequence_length, std::vector<int> solution)
{
    best_fitness_ = sequence_length;
    for (int i = 0; i < POP_SIZE_; i++)
    {
        pop_.push_back(Chromosome(sequence_length));
        double curr_fitness = pop_[i].evaluateFitness(solution);
        best_fitness_ = std::fmin(best_fitness_, curr_fitness);
        pop_[i].print();
    }
}

const std::vector<Chromosome> &Population::selectParents() const
{
    std::vector<Chromosome> parents;
    for (auto &c : pop_)
    {
        if (c.fitness_ >= best_fitness_)
        {
            parents.push_back(c);
        }
    }
    return parents;
}

void Population::newGeneration(const std::vector<Chromosome> &parents)
{
    for (auto &child : pop_)
    {
        child.crossover(parents[generateRandomNumber(0, POP_SIZE_)], parents[generateRandomNumber(0, POP_SIZE_)]);
    }
}