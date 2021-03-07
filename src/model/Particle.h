//
// Created by almge on 2/23/2021.
//
#pragma once

#include <array>
#include <iostream>
#include <eigen/StdVector>

#ifndef SIMULATOR_PARTICLE_H
#define SIMULATOR_PARTICLE_H


class Particle {

public:
    Eigen::Vector3d position;
    Eigen::Vector3d velocity;
    double mass;

    Particle(const Eigen::Vector3d &position,
             const Eigen::Vector3d &velocity,
             double mass) : position(position), velocity(velocity), mass(mass) {}

    void print();
};


#endif //SIMULATOR_PARTICLE_H
