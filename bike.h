//
// Created by Joachim Songio on 3/14/2023.
//

#ifndef SESSION5CPP_BIKE_H
#define SESSION5CPP_BIKE_H
using namespace std;
#include <iostream>
#include "vehicle.h"

class bike:public vehicle {
protected:
    double m_speed;
public:
    bike();
    bike(double,double);
    virtual void disp();
    virtual double get_price();
    virtual int get_type();
    virtual ~bike(){cout<<"bike is kill"<<endl;};

};
bike::bike():vehicle(),m_speed(0) {}
bike::bike(double p, double s):vehicle(p),m_speed(s) {}
void bike::disp() {vehicle::disp();cout<<"This vehicle can go "<<m_speed<<" and is of type "<<get_type()<<" it's a bike."<<endl;}
double bike::get_price() {return vehicle::get_price();}
int bike::get_type() {return 2;}
#endif //SESSION5CPP_BIKE_H
