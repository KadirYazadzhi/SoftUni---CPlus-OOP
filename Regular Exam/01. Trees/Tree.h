#ifndef __TREE_H
#define __TREE_H

#include <string>
#include <iostream>
#include <memory>
#include <list>

class Tree {
public:
    Tree() { ++cnt; }
    virtual ~Tree() { --cnt; }

    virtual const std::string getName() const = 0;
    virtual const std::string getLeaves() const = 0;
    virtual const std::string getProduction() const = 0;
    virtual const std::string getGreatness() const = 0;

    void outputTree(std::ostream &os) const {
        static int counter = 1;
        os << counter++ << ". " << getName() << " tree with "
           << getLeaves() << " leaves, which produces "
           << getProduction() << " and is great for "
           << getGreatness() << "." << std::endl;
    }

    static size_t cnt;

private:
    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;
};

#endif

