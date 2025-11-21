#include "Population.hpp"
#include "Utils.hpp"

void Population::initialisePopulation(int sequence_length, std::string solution)
{
    best_fitness_ = sequence_length;
    for (int i = 0; i <= POP_SIZE_; i++)
    {
        pop_.push_back(Chromosome(sequence_length));
        double curr_fitness = pop_[i].evaluateFitness(solution);
        best_fitness_ = std::fmin(best_fitness_, curr_fitness);
    }
}

std::vector<Chromosome> Population::selectParents() const
{
    std::vector<Chromosome> parents_;
    for (auto &c : pop_)
    {
        if (c.fitness_ <= best_fitness_)
        {
            parents_.push_back(c);
        }
    }
    return parents_;
}

void Population::newGeneration(const std::vector<Chromosome> &parents)
{
    for (auto &child : pop_)
    {
        if (!parents.empty())
        {
            child.crossover(parents[generateRandomNumber(0, parents.size() - 1)], parents[generateRandomNumber(0, parents.size() - 1)]);
        }
    }
}

void Population::mutate(int min, int max, double mutation_rate)
{
    for (auto &c : pop_)
    {
        c.mutate(min, max, mutation_rate);
    }
}

void Population::evaluateFitness(const std::string &target)
{
    for (auto &c : pop_)
    {
        c.evaluateFitness(target);
        best_fitness_ = std::fmin(c.fitness_, best_fitness_);
    }
}

void Population::printBest()
{
    for (auto &c : pop_)
    {
        if (c.fitness_ == best_fitness_)
        {
            std::cout << "best chromosome: ";
            c.print();
            break;
        }
    }
}