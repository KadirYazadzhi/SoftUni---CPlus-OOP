#ifndef __NAMED_H
#define __NAMED_H

#include <string>

struct Named {

    virtual ~Named() = default;

    virtual std::string getName() const = 0;
};

#endif