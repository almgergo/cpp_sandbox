//
// Created by almge on 2/23/2021.
//
#include <array>
#include <iostream>
#include <eigen/StdVector>

#ifndef SIMULATOR_PARTICLE_H
#define SIMULATOR_PARTICLE_H


class Particle {
private:
    std::array<double, 3> position;
    std::array<double, 3> velocity;
    double mass;
public:
    Particle(const std::array<double, 3>& position,
             const std::array<double, 3>& velocity,
             double mass) : position(position), velocity(velocity), mass(mass) {}

    std::array<double, 3> getPosition() {
        return position;
    }

    void print();
};


#endif //SIMULATOR_PARTICLE_H
