//
// Created by Joachim Sonigo on 3/14/2023.
//

#ifndef SESSION5CPP_VEHICLE_H
#define SESSION5CPP_VEHICLE_H
#include <iostream>
using namespace std;

class vehicle {
protected:
    double m_price;
public:
    vehicle();
    vehicle(double);
    void display();
    double get_price();
};

vehicle::vehicle() {m_price=0.0;}
vehicle::vehicle(double a) {m_price=a;}
void vehicle::display() {cout<<"Price of the vehicle "<<m_price<< " in euros."<<endl;}
double vehicle::get_price() {return m_price;}

#endif //SESSION5CPP_VEHICLE_H
