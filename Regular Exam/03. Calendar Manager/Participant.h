#ifndef __PARTICIPANT_H
#define __PARTICIPANT_H

#include <string>
#include <iostream>

class Participant {
public:
    virtual ~Participant() = default;

    virtual std::string getId() const = 0;
    virtual std::string toString() const = 0;
    virtual void readFrom(std::istream & is) = 0;

};

#endif




