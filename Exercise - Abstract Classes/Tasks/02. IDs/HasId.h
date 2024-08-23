#ifndef HASID_H
#define HASID_H

struct HasId {
    virtual int getId() const = 0;

    virtual ~HasId() = default;
};

#endif
