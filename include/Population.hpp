#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <vector>

#include "Chromosome.hpp"
#include "Constants.hpp"

class Population
{
public:
    const int POP_SIZE_;
    std::vector<Chromosome> pop_;
    int best_fitness_ = Const::MAX_FITNESS;

    Population(const int &pop_size) : POP_SIZE_(pop_size) {};

    void initialisePopulation(int solution_length, std::string solution);

    // returns all parents with >= max_fitness_
    std::vector<Chromosome> selectParents() const;

    // loop through parents and build new generation with building blocks from parents
    void newGeneration(const std::vector<Chromosome> &parents);

    void mutate(int min, int max, double mutation_rate);

    void evaluateFitness(const std::string &target);

    void printBest();
};

#endif