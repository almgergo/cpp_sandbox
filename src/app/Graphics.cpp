#include "Graphics.h"
#include "../model/Particle.h"

int Graphics::initApp() {
    if (!GLFWAPI::glfwInit()) {
        printf("GLFW init failed!");
        glfwTerminate();
        return 1;
    }

    // Setup GLFW window properties
    // OpenGL version
    GLFWAPI::glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    GLFWAPI::glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Core profile = NO Backwards compatibility
    GLFWAPI::glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Allow forward compatibility
    GLFWAPI::glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    mainWindow = GLFWAPI::glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test window", nullptr, nullptr);

    if (!mainWindow) {
        printf("GLFW window creation failed");
        GLFWAPI::glfwTerminate();
        return 1;
    }

    // Get buffer size information
    int bufferWidth, bufferHeight;
    GLFWAPI::glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // Set context for GLEW to use
    GLFWAPI::glfwMakeContextCurrent(mainWindow);

    // Allow modern extension features
    GLFWAPI::glewExperimental = GL_TRUE;

    if (GLFWAPI::glewInit() != GLEW_OK) {
        printf("GLEW init failed");
        GLFWAPI::glfwDestroyWindow(mainWindow);
        GLFWAPI::glfwTerminate();
        return 1;
    }

    // Setup viewport size
    GLFWAPI::glViewport(0, 0, bufferWidth, bufferHeight);

//    createTriangle();
    compileShaders();

    return 0;
}

void Graphics::drawFrame() {
//    // Loop until window closed
//    while (!GLFWAPI::glfwWindowShouldClose(mainWindow)) {
        // Get + Handle user input events
    GLFWAPI::glfwPollEvents();

    // Clear window
    GLFWAPI::glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // We only want to clear the color
    GLFWAPI::glClear(GL_COLOR_BUFFER_BIT);

    GLFWAPI::glUseProgram(shader);
    glBindVertexArray(VAO);

    glDrawArrays(GL_POINTS, 0, particleCount);

    glBindVertexArray(0);
    GLFWAPI::glUseProgram(0);

    GLFWAPI::glfwSwapBuffers(mainWindow);
//    }
}

void Graphics::createPoints(std::vector<GLfloat> points) {
    GLFWAPI::glGenVertexArrays(1, &VAO);
    GLFWAPI::glBindVertexArray(VAO);

    GLFWAPI::glGenBuffers(1, &VBO);
    GLFWAPI::glBindBuffer(GL_ARRAY_BUFFER, VBO);
    GLFWAPI::glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(GLfloat), &points[0], GL_STATIC_DRAW);
    glbuffer

    GLFWAPI::glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    GLFWAPI::glEnableVertexAttribArray(0);

    GLFWAPI::glBindBuffer(GL_ARRAY_BUFFER, 0);
    GLFWAPI::glBindVertexArray(0);

    particleCount = points.size()/3;
}

void Graphics::createTriangle() {
    GLfloat vertices[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
    };

    GLFWAPI::glGenVertexArrays(1, &VAO);
    GLFWAPI::glBindVertexArray(VAO);

    GLFWAPI::glGenBuffers(1, &VBO);
    GLFWAPI::glBindBuffer(GL_ARRAY_BUFFER, VBO);
    GLFWAPI::glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLFWAPI::glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    GLFWAPI::glEnableVertexAttribArray(0);

    GLFWAPI::glBindBuffer(GL_ARRAY_BUFFER, 0);
    GLFWAPI::glBindVertexArray(0);
}

void Graphics::addShader(GLuint theProgram, const char *shaderCode, GLenum shaderType) {
    GLuint theShader = glCreateShader(shaderType);

    const GLchar *theCode[1];
    theCode[0] = shaderCode;

    GLint codeLength[1];
    codeLength[0] = strlen(shaderCode);

    GLFWAPI::glShaderSource(theShader, 1, theCode, codeLength);
    GLFWAPI::glCompileShader(theShader);

    GLint result = 0;
    GLchar eLog[1024] = {0};

    GLFWAPI::glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
    if (!result) {
        GLFWAPI::glGetShaderInfoLog(theShader, sizeof(eLog), nullptr, eLog);
        printf("Error compiling the %d shader: '%s'\n", shaderType, eLog);
        return;
    }

    glAttachShader(theProgram, theShader);
}

void Graphics::compileShaders() {
    shader = GLFWAPI::glCreateProgram();

    if (!shader) {
        printf("Error creating shader program!\n");
        // TODO - crash, or handle this error
        return;
    }

    Graphics::addShader(shader, vShader, GL_VERTEX_SHADER);
    Graphics::addShader(shader, fShader, GL_FRAGMENT_SHADER);

    GLint result = 0;
    GLchar eLog[1024] = {0};

    GLFWAPI::glLinkProgram(shader);
    GLFWAPI::glGetProgramiv(shader, GL_LINK_STATUS, &result);
    if (!result) {
        GLFWAPI::glGetProgramInfoLog(shader, sizeof(eLog), nullptr, eLog);
        printf("Error linking program: '%s'\n", eLog);
        return;
    }

    GLFWAPI::glValidateProgram(shader);
    GLFWAPI::glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
    if (!result) {
        GLFWAPI::glGetProgramInfoLog(shader, sizeof(eLog), nullptr, eLog);
        printf("Error validating program: '%s'\n", eLog);
        return;
    }
}


void Graphics::initSDL() {
    printf("initSDL");
//    The window we'll be rendering to
    SDL_Window *window = nullptr;

    //The surface contained by the window
    SDL_Surface *screenSurface = nullptr;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);

            //Fill the surface white
            SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

            //Update the surface
            SDL_UpdateWindowSurface(window);

            //Wait two seconds
            SDL_Delay(2000);
        }
    }

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
}
