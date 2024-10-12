#ifndef SCENE_H
#define SCENE_H

#include "nomad-engine/node.h"

class Scene
{
public:
    Scene();
    ~Scene() = default;

    void update(float delta);
    void render();

    void setRoot(std::shared_ptr<Node> root);
    std::shared_ptr<Node> getRoot();

private:
    std::shared_ptr<Node> root;
};

#endif