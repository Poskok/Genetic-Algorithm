#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Dec  5 09:58:22 2017

@author: mguina
"""

import numpy as np
import matplotlib.pyplot as plt
import random
from time import gmtime, strftime
from matplotlib import style
style.use(['dark_background','ggplot'])


#PI = 3.1415926535897931

#def Rastrigin(x, y):
#    return 20 + x * x + y * y - 10 * (cos( 2 * PI * x  ) + cos( 2 * PI * y ))
#
#def binarize(value):
#    return bin(ctypes.c_uint.from_buffer(ctypes.c_float(1.0)).value)


def create_individual(chromosomeLength):
    tempIndividual = np.random.uniform(0, 1, chromosomeLength)
    individual = []
    for i in range(0, chromosomeLength):
        if (tempIndividual[i] < 0.5):
            individual.append(0)
        else:
            individual.append(1)
    return individual


def mutation(individual):
    sizeOfIndividual = len(individual)
    a = np.random.randint(0, sizeOfIndividual-1)
    b = a
    while (a == b):
        b = np.random.randint(0, sizeOfIndividual-1)
    sentinel = individual[a]
    individual[a] = individual[b]
    individual[b] = sentinel
    return individual


def mutate(individual, p):
    mutant = individual
    if (np.random.uniform(0, 1) < p):
        mutant = mutation(individual)
    return mutant


def crossover(male, female):
    sizeOfIndividual = len(female)
    child = []
    for i in range(0, sizeOfIndividual):
        if (np.random.uniform(0, 1) < 0.5):
            child.append(female[i])
        else:
            child.append(male[i])
    return child


def fitness(individual):
    return individual.count(1)


def generate_population(populationSize, chromosomeLength):
    population = []
    for i in range(0, populationSize):
        population.append(create_individual(chromosomeLength))
    return population


def naturaly_select(individual):
    probaToBeSelected = fitness(individual) / len(individual)
    isSelected = 0
    randGen = np.random.uniform(0, 1)
    if (randGen <= probaToBeSelected):
        isSelected = 1
    return isSelected


def create_new_generation(population, p):
    parents = []
    newPopulation = []
    i = 0
    populationSize = len(population)
    for i in range(0, populationSize - 1):
        if (naturaly_select(population[i]) == 1):
            parents.append(population[i])
    newPopulationSize = 0
    while (newPopulationSize < populationSize):
            a = np.random.randint(0, len(parents))
            b = np.random.randint(0, len(parents))
            newPopulation.append(crossover(parents[a], parents[b]))
            newPopulationSize = len(newPopulation)
    for i in range(0, newPopulationSize-1):
            newPopulation[i] = mutate(newPopulation[i], p)
    random.shuffle(newPopulation)
    return newPopulation


def mean_fitness_population(population):
    fitnessArray = []
    size = len(population[0])
    for i in range(0, len(population)-1):
        fitnessArray.append(fitness(population[i]))
    return np.mean(fitnessArray) / size


def genetic_algorithm(populationSize, chromosomeLength, n, p):
    newPopulation = generate_population(populationSize, chromosomeLength)
    numberOfTrials = n
    populationFitness = []
    for i in range(1, numberOfTrials):
        timeMessage = strftime("%Y-%m-%d %H:%M:%S", gmtime())
        print(timeMessage, 'creating a new generation')
        newPopulation = create_new_generation(newPopulation, p)
        print('new generation of population created')
        if (len(newPopulation) == 0):
            print('problem with newPopulation size : = 0')
        populationFitness.append(mean_fitness_population(newPopulation))
    with plt.style.context(('dark_background')):
        plt.plot(range(1, numberOfTrials), populationFitness)
    return populationFitness
