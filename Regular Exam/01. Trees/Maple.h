#ifndef __MAPLE_H
#define __MAPLE_H

#include "Tree.h"

class Maple : public Tree {

    public:

        virtual const std::string getName() const override { return "Maple"; }
        virtual const std::string getLeaves() const override { return "palmate, hand-like"; }
        virtual const std::string getProduction() const override { return "helicopter seeds"; }
        virtual const std::string getGreatness() const override { return "maple syrup production"; }

};


#endif