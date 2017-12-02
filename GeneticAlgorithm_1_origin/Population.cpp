//
//  Population.cpp
//  GeneticAlgorithm_1_origin
//
//  Created by Marcel on 30/11/2017.
//  Copyright © 2017 Marcel. All rights reserved.
//

#include "Population.hpp"
#include "Individual.hpp"

using namespace std;


void Population::CreateNewPopulation(int populationSize, int chromosomeLength)
{
    for ( int i = 0; i < populationSize; i++ )
    {
        population_.push_back( *new Individual(chromosomeLength) );
    }
};



bool Population::CompareIndividuals(Individual* individual1, Individual* individual2)
{
    int fitness1 = individual1->GetFitness();
    int fitness2 = individual2->GetFitness();
    bool result;
    if ( fitness1 > fitness2 )
    {
        result = true;
    }
    else
    {
        result = false;
    }
    return result;
}




