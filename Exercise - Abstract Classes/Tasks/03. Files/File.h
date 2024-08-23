#ifndef FILE_H
#define FILE_H

#include "ByteContainer.h"
#include "FileSystemObject.h"


class File:public FileSystemObject, public ByteContainer {


public:
    File(std::string name, const std::string & contents)
            : FileSystemObject(name), ByteContainer(contents) {};

    virtual size_t getSize() const {
        return this->getBytes().size();
    };
};

#endif