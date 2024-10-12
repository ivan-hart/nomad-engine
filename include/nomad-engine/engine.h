#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "scene.h"
#include "resource_manager.h"

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