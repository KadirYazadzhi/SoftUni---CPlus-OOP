#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car {
    private:
        string brand, model;
        int year;

    public:
        Car(const string & sBrand, const string & sModel, int nYear):
            brand(sBrand),
            model(sModel),
            year(nYear) {}

        const string & GetBrand() const {
            return brand;
        }

        const string & GetModel() const {
            return model;
        }

        const int & GetYear() const {
            return year;
        }

};

#endif

