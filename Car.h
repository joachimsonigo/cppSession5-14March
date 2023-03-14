//
// Created by Joachim Sonigo on 3/14/2023.
//

#ifndef SESSION5CPP_CAR_H
#define SESSION5CPP_CAR_H
using namespace std;
#include <iostream>
#include "vehicle.h"

class car:public vehicle {
protected:
    int m_doors;
public:
    car();
    car(double,int);
    void disp();
    double get_price();
    int get_type();
};

car::car() {vehicle();m_doors=0;}
car::car(double a, int n): vehicle(a),m_doors(n){}
double car::get_price() {vehicle::get_price();}
int car::get_type() {return 1;}
void car::disp() {cout<<"This vehicle has "<<m_doors<<" doors costs "<<m_price<<" euros and is of type "<<get_type()<<endl;}
#endif //SESSION5CPP_CAR_H
