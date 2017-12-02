//
//  Population.cpp
//  GeneticAlgorithm_1_origin
//
//  Created by Marcel on 30/11/2017.
//  Copyright © 2017 Marcel. All rights reserved.
//

#include "Population.hpp"
#include "Individual.hpp"
#include "Individual_I.hpp"

using namespace std;

void Population::CreateNewPopulation(int populationSize, int chromosomeLength)
{
    for ( int i = 0; i < populationSize; i++ )
    {
        population_.push_back( *new Individual(chromosomeLength) );
    }
}


