#include <vector>
#include <random>

#include "Chromosome.hpp"
#include "Population.hpp"
#include "Constants.hpp"

const std::string solution = "This is great, it works and is nice and efficient.";

int main()
{
  Population pop(100);

  pop.initialisePopulation(solution.size(), solution);
  std::cout << pop.best_fitness_ << std::endl;
  pop.printBest();

  for (int i = 0; i < Const::MAX_ITERATIONS; i++)
  {
    std::cout << "iteration: " << i << ", ";

    // select chromosomes with best fitness
    std::vector<Chromosome> parents = pop.selectParents();

    std::cout << parents.size();

    // crossover
    pop.newGeneration(parents);

    // mutate
    pop.mutate(0, Const::MAX_VALUE, 0.05);

    // evaluate fitness
    pop.evaluateFitness(solution);

    pop.printBest();

    if (pop.best_fitness_ == 0)
      break;
  }

  return 0;
}