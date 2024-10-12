#include "engine.h"
#include <memory>

class Square : public Node
{
public:
    Square(const std::string &name) : Node(name) {}

    void update(float delta) override
    {
        // Update sprite logic
    }

    void render() override
    {
        // Render sprite using OpenGL
    }
};

int main(int argc, char *argv[])
{
    Engine engine;
    if (!engine.initialize())
    {
        return 1;
    }

    auto scene = std::make_shared<Scene>();
    auto root = std::make_shared<Node>("Root");
    auto square = std::make_shared<Square>("1");

    root->addChild(square);
    scene->setRoot(root);

    engine.setScene(scene);
    engine.run();

    return 0;
}
