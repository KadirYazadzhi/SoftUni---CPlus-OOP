#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileSystemObjectsContainer.h"

#include <vector>

class Directory: public FileSystemObject, public FileSystemObjectsContainer {

    std::vector<std::shared_ptr<FileSystemObject>> contents;

public:
    Directory(std::string name) : FileSystemObject(name) {};


    virtual size_t getSize() const {

        size_t size=0;

        for (std::shared_ptr<FileSystemObject> curr : contents) {
            size+=curr->getSize();
        };
        return size;
    };


    virtual void add(const std::shared_ptr<FileSystemObject>& obj) {
        contents.push_back(obj);
    };


    virtual std::vector<std::shared_ptr<FileSystemObject> >::const_iterator begin() const {
        return contents.begin();
    };

    virtual std::vector<std::shared_ptr<FileSystemObject> >::const_iterator end() const {
        return contents.end();
    };

    virtual void remove(std::shared_ptr<FileSystemObject> obj) {
        auto i=std::find(this->contents.begin(), this->contents.end(), obj);
        this->contents.erase(i);
    };

};

#endif