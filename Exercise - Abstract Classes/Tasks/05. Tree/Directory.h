#ifndef directory_h
#define directory_h

#include "FileSystemObjectsContainer.h"

#include <vector>
#include <algorithm>

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
        contents.begin();
    };

    virtual std::vector<std::shared_ptr<FileSystemObject> >::const_iterator end() const {
        contents.end();
    };

    virtual void remove(std::shared_ptr<FileSystemObject> obj) {
        auto i=std::find(this->contents.begin(), this->contents.end(), obj);
        this->contents.erase(i);
    };
};

#endif
