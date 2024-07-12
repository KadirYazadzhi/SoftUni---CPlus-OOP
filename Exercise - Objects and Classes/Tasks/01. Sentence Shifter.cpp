#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

typedef list<string> ShiftData;
class SentenceShifter {

    ShiftData & data;

public:
    SentenceShifter(ShiftData & data) : data(data) {}

    void read(istream & istr) {
        string buf;
        getline(istr, buf);

        istringstream bufStr(buf);

        while (bufStr >> buf) {
            data.push_back(buf);
        }
    }

    void shift(int times);

    void print(ostream & ostr);
};

void SentenceShifter::shift(int times) {
    while (times--) {
        data.push_front(data.back());
        data.erase(--data.end());
    }
}

void SentenceShifter::print(ostream & ostr) {
    for (const string & curr : data) {
        ostr << curr << endl;
    }
}

int main() {
    ShiftData data;
    SentenceShifter sh(data);
    sh.read(cin);

    int times;
    cin >> times;

    sh.shift(times);

   sh.print(cout);
}