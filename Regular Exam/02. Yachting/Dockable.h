#ifndef __DOCKABLE_H
#define __DOCKABLE_H

#include <string>
#include "Supplemental.h"

struct Dockable {

    virtual ~Dockable() = default;

    virtual std::string dock() const = 0;
    virtual std::string undock() const = 0;
    virtual bool onSupplementArrival(Supplement *s) = 0;
};

#endif