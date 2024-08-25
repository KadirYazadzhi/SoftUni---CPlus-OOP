#ifndef __INFO_H
#define __INFO_H

#include <string>

struct Info {

    virtual ~Info() = default;

    virtual std::string getInfo() const = 0;
};

#endif