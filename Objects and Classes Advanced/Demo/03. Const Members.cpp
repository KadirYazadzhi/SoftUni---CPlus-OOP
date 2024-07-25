#include <iostream>
#include <string>

class Company {
private:
    long long capitalDollars;

public:
    const std::string id;

    Company(std::string id, long long capitalDollars) : id(id), capitalDollars(capitalDollars) {}

    void addCapital (long long dollars) {
        this->capitalDollars += dollars;
    }

    void print() const {
        std::cout << this->id << this->capitalDollars << std::endl;
    }
};

int main() {
    Company c {"GOOGINC.", 100000000LL};
    const Company& constRef = c;

    std::cout << c.id << std::endl;

    constRef.print();
    c.addCapital(999999);

    return 0;
}