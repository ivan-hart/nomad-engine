#include "engine.h"
#include <iostream>

Engine::Engine() : window(nullptr), glContext(nullptr), isRunning(false) {}

Engine::~Engine()
{
    shutdown();
}

bool Engine::initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    glContext = SDL_GL_CreateContext(window);
    if (glContext == nullptr)
    {
        std::cerr << "OpenGL context could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        std::cerr << "GLAD could not be initalized" << glGetError() << std::endl;
        return false;
    }

    glViewport(0, 0, 800, 600);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    isRunning = true;
    return true;
}

void Engine::run()
{
    Uint32 lastTime = SDL_GetTicks();
    while (isRunning)
    {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        handleEvents();
        update(deltaTime);
        render();
    }
}

void Engine::shutdown()
{
    if (glContext)
    {
        SDL_GL_DeleteContext(glContext);
    }
    if (window)
    {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

void Engine::setScene(std::shared_ptr<Scene> newScene)
{
    currentScene = newScene;
}

void Engine::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
    }
}

void Engine::update(float delta)
{
    if (currentScene)
    {
        currentScene->update(delta);
    }
}

void Engine::render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (currentScene)
    {
        currentScene->render();
    }

    SDL_GL_SwapWindow(window);
}
