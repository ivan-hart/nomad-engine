#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Node
{
public:
    Node(const std::string &name);
    virtual ~Node() = default;

    std::unique_ptr<Node> getParent();
    void setParent(std::shared_ptr<Node> parent);

    virtual void render();
    virtual void update(float dt);

    bool addChild(std::shared_ptr<Node> node);
    bool removeChild(std::shared_ptr<Node> child);

    std::shared_ptr<Node> getChild(const std::string &name);

    const std::string getName();
    void setName(const std::string name);

protected:
    std::unique_ptr<Node> parent;
    std::vector<std::shared_ptr<Node>> children;
    std::string name;
};

#endif