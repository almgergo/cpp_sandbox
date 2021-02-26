//
// Created by almge on 2/26/2021.
//
#pragma once

#ifndef SIMULATOR_CAPP_H
#define SIMULATOR_CAPP_H
#include <stdio.h>
#include <SDL.h>

//==============================================================================
class CApp {
private:
    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

public:
    CApp() {}

    void initSDL();
};

//==============================================================================

#endif //SIMULATOR_CAPP_H
