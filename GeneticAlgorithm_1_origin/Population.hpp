//
//  Population.hpp
//  GeneticAlgorithm_1_origin
//
//  Created by Marcel on 30/11/2017.
//  Copyright © 2017 Marcel. All rights reserved.
//

#ifndef Population_hpp
#define Population_hpp

#include <stdio.h>
#include <vector>
#include "Individual_I.hpp"
#include "Individual.hpp"

using namespace std;


class Population
{
public:
    Population(vector<Individual> population) : population_(population) {}
    Population();
    void CreateNewPopulation(int populationSize, int chromosomeLength);
    Individual * GetFittest(int offset);
private:
    vector<Individual> population_;
    double populationFitness = -1;
};

#endif /* Population_hpp */
