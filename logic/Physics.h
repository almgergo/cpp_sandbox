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
};


#endif //SIMULATOR_PHYSICS_H
