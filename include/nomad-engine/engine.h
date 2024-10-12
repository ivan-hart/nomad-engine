#ifndef ENGINE_H
#define ENGINE_H

#include "nomad-engine/scene.h"
#include "nomad-engine/resource_manager.h"

#include <glad/glad.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>

class Engine {
public:
    Engine();
    ~Engine();

    bool initialize();
    void run();
    void shutdown();

    void setScene(std::shared_ptr<Scene> newScene);
    ResourceManager& getResourceManager() { return resourceManager; }

private:
    SDL_Window* window;
    SDL_GLContext glContext;
    std::shared_ptr<Scene> currentScene;
    bool isRunning;
    ResourceManager resourceManager;

    void handleEvents();
    void update(float delta);
    void render();
};

#endif