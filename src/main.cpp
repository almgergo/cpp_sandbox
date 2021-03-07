#include <iostream>
#include <array>
#include <random>

#include "model/Particle.h"
#include "model/World.h"
#include "app/CApp.h"

int main(int argc, char *argv[]) {
    CApp* app = new CApp();
//    app->initSDL();
    app->initApp();

    return 0;
}

void WorldTest() {
    size_t N = 100;

    std::mt19937 generator(123);
    std::uniform_real_distribution<double> dis(0.0, 100.0);

    Eigen::Vector3d v(1, 2, 3);
    Eigen::Vector3d w(1, 2, 3);
    std::cout << "-v + w - v =\n" << w + v << std::endl;

    auto world = new World(0.0001, 0.1);
    auto particles = std::vector<std::unique_ptr<Particle>>();
    particles.reserve(100);

    particles.push_back(std::make_unique<Particle>(Eigen::Vector3d(0, 0, 0), Eigen::Vector3d(0, 0, 0), 1));
    particles.push_back(std::make_unique<Particle>(Eigen::Vector3d(2, 2, 2), Eigen::Vector3d(0, 0, 0), 1));

//    for (auto i = 0; i < N; i++) {
//        Eigen::Vector3d position(dis(generator), dis(generator), dis(generator));
////        Eigen::Vector3d velocity (dis(generator)*0.01, dis(generator)*0.01, dis(generator)*0.01);
//        Eigen::Vector3d velocity(0, 0, 0);
//
//        auto particle = std::make_unique<Particle>(position, velocity, 1);
//        particles.push_back(std::move(particle));
//    }

    world->particles = std::move(particles);

    double initialEnergy = world->systemEnergy();

//    for (size_t i = 0; i < 999999; i++) {
//        world->progressWorld();
//
//        if (i % 5000 == 0) {
//            double systemEnergy = world->systemEnergy();
//            if (systemEnergy > 1)
//                world->particles[0]->print();
//            std::cout << "Energy: " << systemEnergy << ", difference: " << systemEnergy - initialEnergy << std::endl;
//        }
//    }
}
