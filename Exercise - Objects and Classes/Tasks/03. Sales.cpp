#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Sale {
    string town;
    string product;
    double price = 0;
    double quantity = 0;

    public:
        Sale(istream & istream);

        const string & getTown(void) const {
            return town;
        }

        double getTotal(void) const {
            return price * quantity;
        }
};

Sale::Sale(istream &istream) {
    string buf;
    getline(istream, buf);
    istringstream bufStr(buf);

    bufStr >> town >> product >> price >> quantity;
}

class Sales {
    public:
        typedef vector<Sale> SalesData;

    private:
        SalesData data;

    public:
        Sales(istream & istr);

        const SalesData & getData(void) const {
            return data;
        }
};

Sales::Sales(istream & istr) {
    size_t salesNum;
    istr >> salesNum;
    istr.ignore();

    data.reserve(salesNum);

    while (salesNum--) {
        data.emplace_back(istr);
    }
}

class SalesCalculator {
    const Sales & data;

    map<string, double> salesByTown;

    public:
        SalesCalculator(const Sales & data) : data(data) {}

        void calculate();

        void print(ostream & ostr) const;
};

void SalesCalculator::calculate() {
    salesByTown.clear();

    for (const Sale & curr : data.getData()) {
        const string & town = curr.getTown();

        salesByTown[town] += curr.getTotal();
    }
}

void SalesCalculator::print(ostream & ostr) const {
    ostr.setf(ios::fixed);
    ostr.precision(2);

    for (const auto &curr : salesByTown) {
        ostr << curr.first << " -> " << curr.second << endl;
    }
}

int main() {
    Sales salesData(cin);

    SalesCalculator salesCalculation(salesData);

    salesCalculation.calculate();
    salesCalculation.print(cout);
}
