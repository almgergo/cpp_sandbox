//
// Created by almge on 2/23/2021.
//

#include "World.h"

void World::progressWorld() {
    for (int i = 0; i < particles.size() - 1; i++) {
        for (int j = i + 1; j < particles.size(); j++) {
            physics.InteractParticles(*particles[i], *particles[j]);
        }
    }
}

double World::systemEnergy() {
    double energy = 0;

    for (int i = 0; i < particles.size() - 1; i++) {
        energy += physics.calculateKineticEnergy(*particles[i]);
        for (int j = i + 1; j < particles.size(); j++) {
            energy += physics.calculatePotentialEnergy(*particles[i], *particles[j]);
        }
    }

    return energy;
}