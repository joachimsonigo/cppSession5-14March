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
    ofstream MyFile("filename.txt");
    MyFile.open ("filename.txt", ios::out | ios::in );
    garage g;
    do {
        do {
            cout<<"-----------------\n\tMenu\n-----------------"<<endl;
            cout<<"1-Add\n2-Show\n3-Delete\n4-Exit"<<endl;
            cout<<"--------------"<<endl;
            cin>>choice;
        }while(choice<1 || choice > 4);
        if (choice ==1){
            g.add();
            MyFile<<g;
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
            MyFile<<g;
        }
    }while(choice != 4);
    system("color 04");
    cout<<"goodbye"<<endl;
    MyFile.close();
}

int main() {
    system("color 0A");
    menu();
    return 0;
}
