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
    void showall();
    virtual void disp();
    virtual ~garage(){};
    friend ostream& operator <<(ostream&,const garage&);
};
void line(){
    cout<<"----------------"<<endl;
}
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
void garage::showall() {
    int tpc=0,tpb=0,nc=0,nb=0;
    for (int i = 0; i < size(m_vehicle); ++i) {
        for (int i = 0; i < size(m_vehicle); ++i) {
            if (m_vehicle[i]->get_type() == 1){
                tpc+=m_vehicle[i]->get_price();
            }else
                tpb+=m_vehicle[i]->get_price();
        }
        for (int i = 0; i < size(m_vehicle); ++i) {
            if (m_vehicle[i]->get_type()==1)
                nc++;
            else
                nb++;
        }
    }
    line();
    cout<<"You have"<<nc+nb<<" vehicles"<<endl;
    line();
    for (int i = 0; i < size(m_vehicle); ++i) {
        m_vehicle[i]->disp();
    }
    line();
    cout<<"nb of bikes : "<<nb<< " with a tot price of "<<tpb<<endl;
    cout<<"nb of cars : "<<nc<<" with a tot price of "<<tpc<<endl;
    line();
cout<<"tot number of vehicles : "<<nb+nc<<" with a tot price of "<<tpb+tpc<<endl;

}

ostream& operator <<(ostream&os,const garage&g){
    for (int i = 0; i < size(g.m_vehicle); ++i) {
        if (g.m_vehicle[i]->get_type() == 1){
            os << g.m_vehicle[i]->get_type() << "," << g.m_vehicle[i]->get_price()<<endl;
            return (os);}
        else
        {os <<g.m_vehicle[i]->get_type() << "," << g.m_vehicle[i]->get_price()<<","<<g.m_vehicle[i]->get_speed()<<endl;
            return (os);}
    }
}

#endif //SESSION5CPP_GARAGE_H
