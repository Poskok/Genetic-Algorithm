//
//  Individual.cpp
//  GeneticAlgorithm_1_origin
//
//  Created by Marcel on 29/11/2017.
//  Copyright © 2017 Marcel. All rights reserved.
//

#include "Individual.hpp"
#include <stdio.h>
#include <vector>
#include <random>
#include <numeric>
using namespace std;

Individual::Individual(int chromosomeLength)
{
    chromosome_ = *new vector<int>();
    double uniformRandomNumber;
    for ( int gene = 0; gene < chromosomeLength; gene++ )
    {
        uniformRandomNumber = generateRandomUniform(0.0, 10.0);
        if ( uniformRandomNumber < 5 )
        {
            chromosome_[gene] = 0;
        }
        else
        {
            chromosome_[gene] = 1;
        }
    }
}

int Individual::getFitness()
{
    return accumulate(chromosome_.begin(), chromosome_.end(), 0);;
}

vector<int> Individual::getChromosomes()
{
    return chromosome_;
}

double Individual::generateRandomUniform(double from, double to)
{
    double result = 0.0;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<double> distr(from, to);
    result = distr(generator);
    return result;
}

