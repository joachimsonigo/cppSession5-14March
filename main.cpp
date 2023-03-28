#include <iostream>
#include <fstream>
#include "vehicle.h"
#include "Car.h"
#include "bike.h"
#include "garage.h"
using namespace std;


void information(vehicle *v){
    v->disp();
}

void menu(){
    int choice;
    garage g;
    g.read();
    do {
        do {
            cout<<"-----------------\n\tMenu\n-----------------"<<endl;
            cout<<"1-Add\n2-Show\n3-Delete\n4-Exit"<<endl;
            cout<<"--------------"<<endl;
            cin>>choice;
        }while(choice<1 || choice > 4);
        if (choice ==1){
            g.add();
            g.write();
        }
        else
        if (choice == 2){
            g.showall();
            system("pause");
        }
        else
        if (choice == 3){
            g.disp();
            system("pause");
            g.pop();
            g.write();
        }
    }while(choice != 4);
    system("color 04");
    cout<<"Goodbye, thank you for using this program."<<endl;
}

int main() {
    system("color 0A");
    menu();
    return 0;
}
