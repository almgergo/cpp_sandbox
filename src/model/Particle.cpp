//
// Created by almge on 2/23/2021.
//


#include "Particle.h"

void Particle::print() {
    std::cout << position[0] << "|" << position[1] << "|" << position[2] << "\t\t"
              << velocity[0] << "|" << velocity[1] << "|" << velocity[2] << std::endl;
}