#include <iostream>

#include "Car.h"

void PrintInfo( const Car& objCar )
{
    cout << "Brand -> " << objCar.GetBrand() << endl;

    cout << "Model -> " << objCar.GetModel() << endl;

    cout << "Year -> " << objCar.GetYear() << endl;
}

int main()
{
    string sBrand;

    string sModel;

    int nYear;

    cin >> sBrand >> sModel >> nYear;

    const Car objCar( sBrand, sModel, nYear );

    PrintInfo( objCar );

    return 0;
}
