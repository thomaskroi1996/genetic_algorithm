#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include <iostream>
#include <vector>

class Chromosome
{
private:
    std::vector<int> sequence_;

public:
    double fitness_;

    Chromosome(const std::vector<int> &sequence, double fitness) : sequence_(sequence), fitness_(fitness) {};

    Chromosome(int length);

    // fitness goes from 0 to sequence_.size()
    double evaluateFitness(const std::vector<int> &target);

    void mutate();

    void print();

    // takes parents as arguments and modifies sequence
    void crossover(const Chromosome &a, const Chromosome &b);
};

#endif