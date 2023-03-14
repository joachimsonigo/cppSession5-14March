//
// Created by Joachim Sonigo on 3/14/2023.
//

#ifndef SESSION5CPP_GARAGE_H
#define SESSION5CPP_GARAGE_H
#include <vector>
#include <ostream>
#include "vehicle.h"
#include "Car.h"
#include "bike.h"
using namespace std;


class garage {
protected:
    vector<vehicle *> m_vehicle;
public:
    garage(){};
    void add();
    void pop();
    void count();
    void totprice();
    virtual void disp();
    virtual ~garage(){cout<<"deleted garage"<<endl;};
};

void garage::add() {
    int type;
    cout<<"What vehicle type are you trying to add?(1 for car 2 for bike)"<<endl;
    cin>>type;
    if (type == 1){
        double price;
        int nd;
        cout<<"Enter the vehicle price"<<endl;
        cin>>price;
        cout<<"Enter the number of doors"<<endl;
        cin>>nd;
        m_vehicle.push_back(new car(price,nd));
    }
    else if (type == 2){
        double price,speed;
        cout<<"How much does your bike cost?"<<endl;
        cin>>price;
        cout<<"What's your bike's top speed?"<<endl;
        cin>>speed;
        m_vehicle.push_back(new bike(price,speed));
    }
    else cout<<"Vehicle type can't be stored in your garage"<<endl;
}
void garage::pop() {
    int index;
    cout<<"What's the index of the vehicle you want to remove from your garage?"<<endl;
    cin>>index;
        m_vehicle.erase(m_vehicle.begin() + index-1);
}

void garage::disp() {
    for (int i = 0; i < size(m_vehicle); ++i) {
        m_vehicle[i]->disp();
    }
}
void garage::count() {
    int nc=0,nb=0;
    for (int i = 0; i < size(m_vehicle); ++i) {
        if (m_vehicle[i]->get_type()==1)
            nc++;
        else
            nb++;
    }
    cout<<"You have "<< nc<<" cars and "<<nb<<" bikes.\nFor a total of "<<nb+nc<<" vehicles."<<endl;
}
void garage::totprice() {
    int totprc=0,totprb=0;
    for (int i = 0; i < size(m_vehicle); ++i) {
        if (m_vehicle[i]->get_type() == 1){
            totprc+=m_vehicle[i]->get_price();
        }else
            totprb+=m_vehicle[i]->get_price();
    }
    cout<<"Total value of garage "<<totprb+totprc<<".\nTotal price of bikes : "<<totprb<<" \nTotal price of cars : "<<totprc<<endl;
}
#endif //SESSION5CPP_GARAGE_H
