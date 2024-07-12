#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Point {
    typedef int DataType;
    DataType x, y;

public:
    Point() : x(0), y(0) {}

    Point(istream & istr) {
        string row;
        getline(istr, row);
        istringstream  rowStr(row);
        rowStr >> x >> y;
    }

    double getEuclidianDistance(const Point & other) {
        double dx = this->x - other.x;
        double dy = this->y - other.y;

        dx *= dx;
        dy *= dy;

        return sqrt(dx + dy);
    }
};

int main() {
    Point a(cin), b(cin);

    cout.setf(ios::fixed);
    cout.precision(3);

    cout << a.getEuclidianDistance(b) << endl;
}
