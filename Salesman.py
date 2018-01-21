#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Dec 24 14:10:37 2017

@author: mguina
"""

import numpy as np
import matplotlib.pyplot as plt
import random
from time import gmtime, strftime
from matplotlib import style
style.use(['dark_background', 'ggplot'])


def create_individual(chromosomeLength):
    return np.random.permutation(chromosomeLength)


def generate_cities_distances(chromosomeLength):
    N = chromosomeLength
    b = np.random.randint(-2000, 2000, size=(N, N))
    C = abs(b + b.T) / 2
    np.fill_diagonal(C, 0)
    return C


def generate_initial_population(populationSize, chromosomeLength):
    population = []
    for i in range(0, populationSize):
        population.append(create_individual(chromosomeLength))
    return population


def individual_distance(individual, city_distances):
    distance = 0
    for i in range(0, len(individual) - 1):
        distance += city_distances[individual[i], individual[i+1]]
    distance += city_distances[individual[len(individual) - 1], individual[0]]
    return distance


def get_fitness_for_population(population, city_distances):
    fitness = []
    for i in range(0, len(population)):
        fitness.append(1 / individual_distance(population[i], city_distances))
    return fitness


def is_chosen_partner(fitness, median, max, min):
    probabilityToBeSelected = (fitness - min)/(max - min)
    randGen = np.random.uniform(0, 1)
    isSelected = 0
    if (randGen <= probabilityToBeSelected):
        isSelected = 1
    return isSelected


def select_parent(population, city_distances):
    tournamentSize = int(len(population)/100)
    random.shuffle(population)
    fitness = get_fitness_for_population(population, city_distances)
    maxFitness = fitness[0]
    parent = population[0]
    for i in range(1, tournamentSize):
        if (fitness[i] > maxFitness):
            parent = population[i]
            maxFitness = fitness[i]
    return parent


def generate_child(mother, father):
    child = mother.copy()
    a = np.random.randint(0, len(mother) - 1)
    b = np.random.randint(0, len(mother) - 1)
    while (a == b):
        a = np.random.randint(0, len(mother) - 1)
        b = np.random.randint(0, len(mother) - 1)
        c = b
        if (a > b):
            b = a
            a = c
    for i in range(a, b):
        child[i] = father[i]
    child = educate_child(child)
    return child


def educate_child(child):
    for i in range(0, len(child) - 1):
        if (i not in child):
            position = np.random.randint(0, len(child) - 1)
            child[position] = i
    return child


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


def generate_new_population(population, city_distances, p):
    newPopulation = []
    for i in range(0, len(population)):
        mother = select_parent(population, city_distances)
        father = select_parent(population, city_distances)
        newPopulation.append(educate_child(generate_child(mother, father)))
#    for i in range(0, len(newPopulation)-1):
#            newPopulation[i] = mutate(newPopulation[i], p)
    random.shuffle(newPopulation)
    return newPopulation


def genetic_algorithm(populationSize, chromosomeLength, n, p, city_distances):
    newPopulation = generate_initial_population(populationSize,
                                                chromosomeLength)
    numberOfTrials = n
    populationFitness = []
    for i in range(1, numberOfTrials):
        timeMessage = strftime("%Y-%m-%d %H:%M:%S", gmtime())
        print(timeMessage, 'creating a new generation')
        newPopulation = generate_new_population(newPopulation, city_distances,
                                                p)
        print('new generation of population created')
        populationFitness.append(np.mean(get_fitness_for_population(
                newPopulation, city_distances)))
        if (len(newPopulation) == 0):
            print('problem with newPopulation size : = 0')
    with plt.style.context(('dark_background')):
        plt.plot(range(1, numberOfTrials), populationFitness)
    return populationFitness

populationSize = 2000
chromosomeLength = 10
N = chromosomeLength
city_distances = generate_cities_distances(chromosomeLength)
population = generate_initial_population(populationSize, chromosomeLength)
f = get_fitness_for_population(population, city_distances)
median = np.median(f)