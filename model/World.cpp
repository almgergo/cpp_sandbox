//
// Created by almge on 2/23/2021.
//

#include "World.h"

void World::ProgressWorld() {
    for (int i = 0; i < particles.size() - 1; i++) {
        for (int j = i + 1; j < particles.size(); j++) {
            physics.InteractParticles(*particles[i], *particles[j]);
        }
    }
}