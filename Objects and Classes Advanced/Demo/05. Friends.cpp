#include <iostream>
#include <istream>
#include <string>

class Company {
private:
    std::string id;
    long long capitalDollars;

public:
    Company() {}

    Company (std::string id, long long capitalDollars) : id(id),
    capitalDollars(capitalDollars) {}

    void print() {
        std::cout << this-> id << " (" << this -> capitalDollars << ")" << std::endl;
    }

    friend void getCompany (std::istream & in, Company& c);
};

void getCompany (std::istream & in, Company& c) {
    in >> c.id >> c.capitalDollars;
}

int main() {
    Company c;

    getCompany(std:cin, c);
    c.print();

    return 0;
}