//
// Created by almge on 3/8/2021.
//

#ifndef SIMULATOR_SYCLPHYSICS_H
#define SIMULATOR_SYCLPHYSICS_H

#include <iostream>
#include <algorithm>
#include <CL/sycl.hpp>
#include "../model/Particle.h"

class SyclPhysics {
public:
    double dt;
    double G;

    SyclPhysics(double dt, double G): dt(dt), G(G) {}

    void syclHelloWorld();

    void interactParticles(std::vector<std::unique_ptr<Particle>>& particles);
};


#endif //SIMULATOR_SYCLPHYSICS_H
