#include <iostream>
#include <array>

#include "model/Particle.h"
#include "model/World.h"

int main(int argc, char *argv[]) {
    auto world = new World(0.0005, 0.2);
    world->initGraphics();
    world->initWithRandomParticles(100);
    world->startWorld();

    return 0;
}
