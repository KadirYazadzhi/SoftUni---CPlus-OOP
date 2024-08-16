#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

namespace SoftUni {
    class Resource {
    private:
        int id;
        ResourceType rt;
        std::string link
    public:
        int getId(void) const {
            return id;
        };

        ResourceType getType(void) const {
            return rt;
        };

        const std::string & getLink(void) const {
            return link;
        }

        friend std::istream & operator >> (std::istream & istr, Resource & r);

        bool operator < (const Resource & other) const {
            return this->id < other.id;
        }
    };

    std::istream & operator >> (std::istream & out, enum ResourceType & t) {
        std::string buff;
        in >> buff;

        if (buff == "Demo") {
            t = ResourceType::DEMO;
        }
        else if (buff == "Presentation") {
            t = ResourceType::PRESENTATION;
        }
        else if (buff == "Video") {
            t = ResourceType::VIDEO;
        }

        return in;
    }

    std::istream & operator >> (std::istream & istr, Resource & r) {
        istr >> r.id;
        istr >> r.rt;
        
        istr.ignore();
        getline(istr, r.link);

        return istr;
    }

    std::ostream & operator << (std::ostream & out, coonst Resource & r) {
        out << r.getId() << ' ' << r.getType() << ' ' << r.getLink();

        return out;
    }
}

#endif

