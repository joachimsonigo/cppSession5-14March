#include <iostream>
#include "vehicle.h"
#include "Car.h"
#include "bike.h"
using namespace std;

void information(vehicle *v){
    v->disp();
}
int main() {
    bike b(2000,325);
    car c(10000,3);
    information(&b);
    information(&c);
    return 0;
}
