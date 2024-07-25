#include <iostream>
#include <string>

class Person {
    int age;
public:
    const std::string name;

    Person (std::string name, int age) {
        this->name = name;
        this->age = age;
    }

    int getAge () {
        return this->age;
    }
};

void printOlderPerson (const Person& a, const Person& b) {
    if (a.getAge() >= b.getAge()) {
        std::cout << a.name << std::endl;
    }
    else {
        std::cout << b.name << std::endl;
    }
}

int main() {
    Person a {"joro", 26};
    Person b {"ben dover", 46};

    printOlderPerson(a, b);

    return 0;
}