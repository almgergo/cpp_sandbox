#include <iostream>
#include <array>
#include <random>

#include "model/Particle.h"
#include "model/World.h"


int main() {
    size_t N = 100;

    std::mt19937 generator(123);
    std::uniform_real_distribution<double> dis(0.0, 100.0);

    Eigen::Vector3d v(1, 2, 3);
    Eigen::Vector3d w(1, 2, 3);
    std::cout << "-v + w - v =\n" << w + v << std::endl;

    auto world = new World(0.0001, 0.1);
    auto particles = std::vector<std::unique_ptr<Particle>>();
    particles.reserve(100);

    for (auto i = 0; i < N; i++) {
        Eigen::Vector3d position(dis(generator), dis(generator), dis(generator));
//        Eigen::Vector3d velocity (dis(generator)*0.01, dis(generator)*0.01, dis(generator)*0.01);
        Eigen::Vector3d velocity(0, 0, 0);

        auto particle = std::make_unique<Particle>(position, velocity, 1);
        particles.push_back(std::move(particle));
    }

    world->particles = std::move(particles);
//
//    for (std::unique_ptr<Particle> &p : world->particles) {
//        p->print();
//        break;
//    }
    auto p1 = Particle(Eigen::Vector3d(0, 0, 0), Eigen::Vector3d(0, 0, 0), 1);
    auto p2 = Particle(Eigen::Vector3d(2, 2, 0), Eigen::Vector3d(0, 0, 0), 1);

    for (size_t i = 0; i < 9999]




































































































    ==10=99; i++) {
        if (i % 10000 == 0) {
            p1.print();
        }
        world->physics.InteractParticles(p1, p2);
    }

//    for (std::unique_ptr<Particle> &p : world->particles) {
//        p->print();
//        break;
//    }

    return 0;
}
