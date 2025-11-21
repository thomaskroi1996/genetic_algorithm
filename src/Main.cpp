#include <vector>
#include <random>

#include "Chromosome.hpp"
#include "Population.hpp"

const int MAX_ITERATIONS = 1000;
std::vector<int> solution = {0, 1, 3, 6, 4, 88, 3, 2, 8, 4};

int main()
{
  Population pop(100);

  pop.initialisePopulation(solution.size(), solution);

  for (int i = 0; i < MAX_ITERATIONS; i++)
  {
    // select chromosomes with best fitness
    std::vector<Chromosome> parents = pop.selectParents();

    // crossover
    pop.newGeneration(parents);

    // mutate
    pop.mutate();

    // evaluate fitness
    pop.evaluateFitness();
  }

  return 0;
}