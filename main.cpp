#include <iostream>
#include "vehicle.h"
#include "Car.h"

using namespace std;
int main() {
    vehicle v,v1(20);
    car c,c1(20,5);
    c1.disp();
    return 0;
}
