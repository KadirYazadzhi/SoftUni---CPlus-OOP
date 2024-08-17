#include <iostream>
#include "Macros.h"

using namespace std;

int main() {
    double radius;
    cin >> radius;

    cout << PI << endl;

    SHOW(PI * radius * radius);
#undef SHOW
#define SHOW cout << "That's all, folks!" << endl;
    SHOW
#undef SHOW

return 0;
}
