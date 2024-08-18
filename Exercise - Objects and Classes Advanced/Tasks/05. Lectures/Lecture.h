#ifndef LECTURE_H
#define LECTURE_H

#include <set>
#include "Resource.h"

namespace SoftUni {
    typedef std::vector<ResourceType> ResourceVector;

    class Lecture {
        public:
            typedef std::set<Resource> ResourceSet;
            typedef std::map<ResourceType, int> ResourcesCount;

        private:
            ResourceSet resources;
            ResourcesCount count;

        public:
            ResourceSet::iterator begin() {
                return resources.begin();
            }
            ResourceSet::iterator end() {
                return resources.end();
            }

            Lecture & operator << (const Resource & r) {
                ResourceSet::iterator itFound = resources.find(r);
                if (itFound != resources.end()) {
                    ResourceType rt = r.getType();
                    resources.erase(itFound);
                    count[rt]--;

                    if (count[rt] == 0) {
                        count.erase(rt);
                    }
                }
                resources.insert(r);
                count[r.getType()]++;

                return *this;
            }

            int operator [] (ResourceType rt) {
                return count[rt];
            }

        friend ResourceVector & operator << (ResourceVector & vec, Lecture & l);
    };

    ResourceVector & operator << (ResourceVector & vec, Lecture & l) {
        for (auto curr : l.count) {
            vec.push_back(curr.first);
        }

        return vec;
    }
}

#endif
