#include "nomad-engine/scene.h"

Scene::Scene() : root(nullptr) {}

void Scene::update(float delta)
{
    if (root)
    {
        root->update(delta);
    }
}

void Scene::render()
{
    if (root)
    {
        root->render();
    }
}

void Scene::setRoot(std::shared_ptr<Node> newRoot)
{
    root = newRoot;
}
