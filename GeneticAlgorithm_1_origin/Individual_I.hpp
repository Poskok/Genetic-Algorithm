//
//  Individual_I.hpp
//  GeneticAlgorithm_1_origin
//
//  Created by Marcel on 30/11/2017.
//  Copyright © 2017 Marcel. All rights reserved.
//

#ifndef Individual_I_hpp
#define Individual_I_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Individual_I
{
public:
    virtual vector<int> getChromosomes() = 0;
    virtual int getFitness() = 0;
};

#endif /* Individual_I_hpp */
