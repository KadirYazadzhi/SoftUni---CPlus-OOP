#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Student {
    string name;
    string surname;
    double totalAverage = 0;

public:
    void read(istream & istr);
    void print(ostream & ostr);
    double getTotalAverage(void) {
        return totalAverage;
    }

};

void Student::read(istream & istr) {
    istr >> name >> surname >> totalAverage;
}

void Student::print(ostream & ostr) {
    ostr << name << " " << surname << " " << totalAverage << endl;
}

int main(void) {
    vector<Student> data;

    int totalStudent;
    cin >> totalStudent;

    if (totalStudent <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    while (totalStudent--) {
        Student s;
        s.read(cin);

        data.push_back(s);
    }

    double grandTotalAverage = 0;
    for (Student & curr : data) {
        grandTotalAverage += curr.getTotalAverage();
        curr.print(cout);
    }

    cout << (grandTotalAverage / data.size()) << endl;
}




