//
// Created by almge on 2/23/2021.
//
#pragma once

#include <algorithm>
#include <random>
#include <memory>
#include <chrono>

#include "Particle.h"
#include "../logic/Physics.h"
#include "../app/Graphics.h"
#include "World.h"
#include "../logic/SyclPhysics.h"

#ifndef SIMULATOR_WORLD_H
#define SIMULATOR_WORLD_H


class World {
private:
    std::unique_ptr<Graphics> graphics;

public:
    Physics physics;
    SyclPhysics syclPhysics;
    std::vector<std::unique_ptr<Particle>> particles;

    World(double dt, double G) : physics(dt, G), syclPhysics(dt, G) {
    }

    void initGraphics() {
        graphics = std::make_unique<Graphics>();
        graphics->initApp();
    }

    void initWithRandomParticles(size_t N = 50) {
        std::mt19937 generator(123);
        std::uniform_real_distribution<double> dis(-1.0f, 1.0f);

        auto particles = std::vector<std::unique_ptr<Particle>>();
        particles.reserve(100);

        for (auto i = 0; i < N; i++) {
            Eigen::Vector3d position(dis(generator), dis(generator), 0);
            Eigen::Vector3d velocity(position[1] * 0.25, - position[0] * 0.25, 0);
//            Eigen::Vector3d velocity(0, 0, 0);

            auto particle = std::make_unique<Particle>(position, velocity, 1);
            particles.push_back(std::move(particle));
        }
        this->particles = std::move(particles);
    }

    void startWorld() {
        size_t i = 0;
        while (!graphics->shouldClose()) {
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            progressWorld();
            graphics->drawFrame();
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

            std::cout << "Time difference = "
                      << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]"
                      << std::endl;
            i++;
        }

    }

    void progressWorld();

    double systemEnergy();
};


#endif //SIMULATOR_WORLD_H
