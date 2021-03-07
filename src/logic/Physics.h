//
// Created by almge on 2/23/2021.
//
#pragma once

#include "../model/Particle.h"

#ifndef SIMULATOR_PHYSICS_H
#define SIMULATOR_PHYSICS_H


class Physics {
public:
    double dt;
    double G;

    Physics(double dt, double G): dt(dt), G(G) {}

    void InteractParticles(Particle& particle1, Particle& particle2);
    double calculatePotentialEnergy(const Particle& particle1, const Particle& particle2);
    double calculateKineticEnergy(const Particle& particle);
};


#endif //SIMULATOR_PHYSICS_H
