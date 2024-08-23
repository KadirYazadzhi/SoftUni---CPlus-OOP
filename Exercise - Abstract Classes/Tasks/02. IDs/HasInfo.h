#ifndef HASINFO_H
#define HASINFO_H

#include <string>

struct HasInfo {
    virtual std::string getInfo() const = 0;

    virtual ~HasInfo() = default;
};

#endif
