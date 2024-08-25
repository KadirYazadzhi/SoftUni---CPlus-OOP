#ifndef __CONTRIBUTOR_H
#define __CONTRIBUTOR_H

#include "Participant.h"

class Contributor : public Participant {

        std::string firstName, secondName;

    public:

        Contributor() = default;
        Contributor(std::istream & is) { readFrom(is); }

        std::string getId() const override { return firstName + secondName; }
        std::string toString() const override { return firstName + " " + secondName; }

        void readFrom(std::istream & is) override { is >> firstName >> secondName; }; 

};

#endif
