#include <iostream>
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
    do {
        do {
            cout<<"-----------------\n\tMenu\n-----------------"<<endl;
            cout<<"1-Add vehicle\n2-Delete a vehicule\n3-Display garage\n4-Count rides\n5-Compute prices\n6-Show everything\n7-Exit"<<endl;
            cout<<"--------------"<<endl;
            cin>>choice;
        }while(choice<1 || choice > 7);
        if (choice ==1){
            g.add();
        }
        else
        if (choice == 2){
            g.pop();
        }
        else
        if (choice == 3){
            g.disp();
            system("pause");
        }
        else
        if(choice == 4 ){
            g.count();
            system("pause");
        }
        else if (choice==5)
        {g.totprice();system("pause");}
        else if(choice==6){
            g.showall();
            system("pause");
        }

    }while(choice != 7);
    system("color 04");
    cout<<"goodbye"<<endl;
}

int main() {
    system("color 0A");
    menu();
    return 0;
}
