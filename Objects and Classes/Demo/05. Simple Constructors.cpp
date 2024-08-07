#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age = 0;
    double heightMeters = 0;

    Person(string personName, int personAge, double personHeightMeters) {
        name = personName;
        age = personAge;
        heightMeters = personHeightMeters;
    }

    Person() {
        name = "<unknown>";
    }
};

void printPersonInfo(Person person) {
    cout << "name: " << person.name
    << ", age: " << person.age
    << ", height: " << person.heightMeters << endl;
}

int main() {
    Person ben("Ben Dover", 42, 1.69);
    Person chucky = Person("Chuck Norris", 999, 999.999);

    Person defaultPerson;

    printPersonInfo(ben);
    printPersonInfo(chucky);
    printPersonInfo(defaultPerson);
    printPersonInfo(Person("Tem Porary", 1, 1.0));

    return 0;
}