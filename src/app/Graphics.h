// Created by almge on 3/7/2021.
//

#ifndef SIMULATOR_GRAPHICS_H
#define SIMULATOR_GRAPHICS_H

#include <cstdio>
#include <cstring>
#include <string>

#include <SDL.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
//#include "../graphics/VertexShader.h"

static const char *vertexShader =
#include "../graphics/vertexShader.vs"
;

static const char *fragmentShader =
#include "../graphics/fragmentShader.vs"
;

class Graphics {
private:
    // Shaders
    const char *vShader = vertexShader;
    const char *fShader = fragmentShader;
    // Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    size_t particleCount = 0;

    GLFWwindow *mainWindow;
    GLuint VAO, VBO, shader;

public:

    Graphics() {}

    void initSDL();

    int initApp();

    void drawFrame();

    void createPoints(std::vector<GLfloat> points);

    void createTriangle();

    void compileShaders();

    bool shouldClose() {
        return GLFWAPI::glfwWindowShouldClose(mainWindow);
    }

    void addShader(GLuint theProgram, const char *shaderCode, GLenum shaderType);
};


#endif //SIMULATOR_GRAPHICS_H
