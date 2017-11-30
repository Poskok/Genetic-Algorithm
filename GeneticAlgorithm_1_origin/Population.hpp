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

using namespace std;


class Population
{
public:
    Population(int populationSize);
    Population(int populationSize, int chromosomeLength);
private:
    vector<Individual_I> population_;
    double populationFitness = -1;
};

#endif /* Population_hpp */
