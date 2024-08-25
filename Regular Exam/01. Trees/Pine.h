#ifndef __PINE_H
#define __PINE_H

#include "Tree.h"

class Pine : public Tree {

    public:

        virtual const std::string getName() const override { return "Pine"; }
        virtual const std::string getLeaves() const override { return "rounded"; }
        virtual const std::string getProduction() const override { return "needles and cones"; }
        virtual const std::string getGreatness() const override { return "walking under, because it's evergreen"; }

};

#endif