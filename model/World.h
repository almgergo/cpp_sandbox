//
// Created by almge on 2/23/2021.
//
#include <vector>
#include "Particle.h"
#include "../logic/Physics.h"

#ifndef SIMULATOR_WORLD_H
#define SIMULATOR_WORLD_H


class World {
private:
    Physics physics;

public:
    std::vector<std::unique_ptr<Particle>> particles;

    World(double dt, double G) : physics(dt, G) {}

    void ProgressWorld();
};


#endif //SIMULATOR_WORLD_H
