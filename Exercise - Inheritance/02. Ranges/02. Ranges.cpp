#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

struct Range {
    int start, end;

    Range() : start(0), end(0) {}

    Range(const string &buff) {
        istringstream istr(buff);
        istr >> start >> end;
    }
};

class Container : public map<int, Range> {
public:
    bool isInRange(int i) const {
        auto it = upper_bound(i);

        if (it == begin()) {
            return false;
        }

        --it;
        return i >= it->second.start && i <= it->second.end;
    }
};

int main() {
    Container c;
    string buf;

    while (getline(cin, buf) && buf != ".") {
        Range r(buf);
        c[r.start] = r;
    }

    int num;
    while (cin >> num) {
        cout << (c.isInRange(num) ? "in" : "out") << endl;
    }

    return 0;
}
