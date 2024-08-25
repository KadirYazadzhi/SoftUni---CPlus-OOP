#ifndef __OAK_H
#define __OAK_H

#include "Tree.h"

class Oak : public Tree {

    public:

        virtual const std::string getName() const override { return "Oak"; }
        virtual const std::string getLeaves() const override { return "lobed"; }
        virtual const std::string getProduction() const override { return "acorns"; }
        virtual const std::string getGreatness() const override { return "wood working, because it's hard"; }

};


#endif