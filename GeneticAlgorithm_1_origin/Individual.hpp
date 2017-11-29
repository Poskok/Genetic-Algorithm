//
//  Individual.hpp
//  GeneticAlgorithm_1_origin
//
//  Created by Marcel on 29/11/2017.
//  Copyright © 2017 Marcel. All rights reserved.
//

#ifndef Individual_hpp
#define Individual_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Individual
{
public:
    Individual(int chromosomeLength);
    Individual(vector<int> chomosomes);
private:
    vector<int> chromosome_;
    double fitness = -1;
};

#endif /* Individual_hpp */


