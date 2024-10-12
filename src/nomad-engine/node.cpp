#include "node.h"

Node::Node(const std::string &name)
{
    this->setName(name);
}

std::unique_ptr<Node> Node::getParent()
{
    return std::make_unique<Node>(this->parent);
}

void Node::setParent(std::shared_ptr<Node> parent)
{
    this->parent = std::make_unique<Node>(parent);
}

void Node::render()
{
    // does nothing as its meant to be overrided
}

void Node::update(float dt)
{
    // does nothing as its meant to be overrided
}

// adds a child as long as it doesnt exist in the children vector or if the name isn't a duplicate
bool Node::addChild(std::shared_ptr<Node> child)
{
    for (auto node = children.begin(); node != children.end();)
    {
        if ((*node)->getName() == child->getName() || (*node) == child)
            return false;
    }
    children.push_back(child);
    return true;
}

// removes a node from the children vector
bool Node::removeChild(std::shared_ptr<Node> child)
{
    for (auto node = children.begin(); node != children.end();)
    {
        if (child == (*node))
        {
            std::cout << "Node deleted\n";
            children.erase(node);
            return true;
        }
    }
    std::cout << "Node not found\n";
    return false;
}

// returns a refrence of a node in the children vector by name
std::shared_ptr<Node> Node::getChild(const std::string &name)
{
    for (auto node = children.begin(); node != children.end();)
    {
        if (this->name == (*node)->name)
        {
            std::cout << "Returning node: " << name << std::endl;
            return (*node);
        }
    }
}

// returns the name of this node
const std::string Node::getName()
{
    return this->name;
}

// sets the name of the current node as long as its not empty
void Node::setName(const std::string name)
{
    if (name == "")
        ;
    this->name = name;
}
