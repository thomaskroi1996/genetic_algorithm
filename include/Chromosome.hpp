#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include <iostream>
#include <vector>

class Chromosome
{
private:
    std::string sequence_;

public:
    double fitness_;

    Chromosome(const std::string &sequence, double fitness) : sequence_(sequence), fitness_(fitness) {};

    Chromosome(int length);

    // fitness goes from 0 to sequence_.size()
    double evaluateFitness(const std::string &target);

    // void mutate();

    void mutate(int min, int max, double mutation_rate);

    void print();

    // takes parents as arguments and modifies sequence
    void crossover(const Chromosome &a, const Chromosome &b);
};

#endif