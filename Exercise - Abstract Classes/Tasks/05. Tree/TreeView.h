#ifndef TreeView_h
#define TreeView_h

#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>

bool comparer(
        const std::shared_ptr<FileSystemObject> a,
        const std::shared_ptr<FileSystemObject> b) {
    return a->getName()<b->getName();
}


std::string getTreeView(
        std::vector<std::shared_ptr<FileSystemObject> >::const_iterator begin,
std::vector<std::shared_ptr<FileSystemObject> >::const_iterator end,
const std::string & indentation) {
std::ostringstream ostr;
std::vector<std::shared_ptr<FileSystemObject> > contents(begin,end);

std::sort(contents.begin(), contents.end(), [](const std::shared_ptr<FileSystemObject> a, const std::shared_ptr<FileSystemObject> b) {
return a->getName() < b->getName();
});

//the following function is the same as the listed above
std::sort(contents.begin(),contents.end(),comparer);

for (std::shared_ptr<FileSystemObject> curr : contents) {
ostr<<indentation<<curr->getName()<<std::endl;

FileSystemObjectsContainer * d = dynamic_cast<FileSystemObjectsContainer *>(curr.get());

if (d!=nullptr) {
ostr<<getTreeView(d->begin(), d->end(),"--->"+indentation);
};
};
return ostr.str();
};


std::string getTreeView(std::vector<std::shared_ptr<FileSystemObject> >& root) {
    return getTreeView(root.begin(), root.end(),"");
};



#endif
