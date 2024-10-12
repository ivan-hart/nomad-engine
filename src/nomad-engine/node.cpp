#include "nomad-engine/node.h"

Node::Node(const std::string &name)
{
    this->setName(name);
}

Node* Node::getParent()
{
    return this->parent;
}

void Node::setParent(Node* parent)
{
    this->parent = parent;
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
    for (const auto& node : children)
    {
        if (node->getName() == child->getName() || node == child)
            return false;
    }
    children.push_back(child);
    child->setParent(this);
    return true;
}

// removes a node from the children vector
bool Node::removeChild(std::shared_ptr<Node> child)
{
    auto it = std::find_if(children.begin(), children.end(),
        [&child](const std::shared_ptr<Node>& node) {
            return node.get() == child.get();
        });

    if (it != children.end())
    {
        std::cout << "Node deleted\n";
        (*it)->setParent(nullptr);
        children.erase(it);
        return true;
    }

    std::cout << "Node not found\n";
    return false;
}


// returns a refrence of a node in the children vector by name
std::shared_ptr<Node> Node::getChild(const std::string &name)
{
    for (const auto& node : children)
    {
        if (node->getName() == name)
        {
            std::cout << "Returning node: " << name << std::endl;
            return node;
        }
    }
    return nullptr;
}

// returns the name of this node
const std::string Node::getName()
{
    return this->name;
}

// sets the name of the current node as long as its not empty
void Node::setName(const std::string& name)
{
    if (!name.empty())
    {
        this->name = name;
    }
}
