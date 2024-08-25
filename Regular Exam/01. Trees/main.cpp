#include "Oak.h"
#include "Pine.h"
#include "Maple.h"

using namespace std;

size_t Tree::cnt = 0;

int main(void) {

    list<unique_ptr<Tree>> trees;

    string str;
    while(cin >> str) {
        if (str == "pine")
            trees.emplace_back(make_unique<Pine>());
        else if (str == "oak")
            trees.emplace_back(make_unique<Oak>());
        else if (str == "maple")
            trees.emplace_back(make_unique<Maple>());
        else 
            break;
    }

    for(auto & sptr : trees) 
        sptr->outputTree(cout);


    return 0;
}