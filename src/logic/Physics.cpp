//
// Created by almge on 2/23/2021.
//
#include <iostream>

#include "Physics.h"

void Physics::InteractParticles(Particle &particle1, Particle &particle2) {
    Eigen::Vector3d differenceVector = (particle2.position - particle1.position);
    double distance = differenceVector.dot(differenceVector);

    Eigen::Vector3d normal = differenceVector.normalized();

    double force = distance > 0.02 ? G / distance : 0;

    Eigen::Vector3d acceleration = normal * force;

    particle1.velocity += acceleration * dt;
    particle1.position += particle1.velocity * dt;

    particle2.velocity -= acceleration * dt;
    particle2.position += particle2.velocity * dt;
}

double Physics::calculatePotentialEnergy(const Particle &particle1, const Particle &particle2) {
    Eigen::Vector3d differenceVector = (particle2.position - particle1.position);
    double distance = differenceVector.dot(differenceVector);

    return G * particle1.mass * particle2.mass / distance * 2;
}

double Physics::calculateKineticEnergy(const Particle &particle) {
    double vv = particle.velocity.dot(particle.velocity);

    return 0.5 * vv * particle.mass;
}