#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <vector>

#include "Chromosome.hpp"

class Population
{
public:
    const int POP_SIZE_;
    std::vector<Chromosome> pop_;
    int best_fitness_;

    Population(const int &pop_size) : POP_SIZE_(pop_size) {};

    void initialisePopulation(int solution_length, std::vector<int> solution);

    // returns all parents with >= max_fitness_
    const std::vector<Chromosome> &selectParents() const;

    // loop through parents and build new generation with building blocks from parents
    void newGeneration(const std::vector<Chromosome> &parents);
};

#endif