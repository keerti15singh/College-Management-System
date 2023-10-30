#include<iostream>
#include<stdio.h>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#include<string.h>
using namespace std;
class Pencils{
int id;
string thickness;
string brand;
int quantity;
int price;
public:
void MainMenu();
void showAll();
void addPencils();
void modify();
void checkPencils();
void takeOrders();
void finishedOrders();
void buyPencils(string,int,int);
};
void Pencils::MainMenu(){
   system("cls");
       int c;
       do{
        cout<<"\n                                   ===========================";
        cout<<"\n                                   WELCOME TO PENCILS STOCK\n";
        cout<<"                                   ===========================\n";
        cout<<"\n\n";
        cout<<"                 1.View All Pencils in the stock\n\n";
        cout<<"                 2.Add Pencils\n\n";
        cout<<"                 3.Edit Pencils\n\n";
        cout<<"                 4.Find Pencils\n\n";
        cout<<"                 5.View the placed Orders to be manufactured\n\n";
        cout<<"                 6.View all the orders fulfilled till now\n\n";
        cout<<"                 7.Exit\n\n";
        cout<<"                 Please Enter Required Option: ";
        cin>>c;
        switch (c){
        case 1:
        showAll();
        break;
        case 2:
        addPencils();
        break;
        case 3:
        modify();
        break;
        case 4:
        checkPencils();
        break;
        case 5:
        takeOrders();
        break;
        case 6:
        finishedOrders();
        break;
        case 7:
        cout<<"n\t\t\tExiting\n";
        break;
        default:
            break;
        }}while(c!=7); 
}
void Pencils::addPencils(){
    fstream file;
        cout<<"\n               Enter the details of the pencils you want to add:\n";
        cout<<"\n               ID: ";
        cin>>id;
        cout<<"\n               Brand: ";
        cin>>brand;
        cout<<"\n               Thickness: ";
        cin>>thickness;
        cout<<"\n               Quantity: ";
        cin>>quantity;
        cout<<"\n               Price(in Rupees): ";
        cin>>price;
        cout<<"\n               Pencil Added Successfully!";
        file.open("Pencildata.txt",ios::app|ios::out);
        file << " " << id << " " << brand << " " << thickness << " " << quantity<< " " << price <<"\n";
        file.close();
}
void Pencils::showAll(){
    fstream file;
        cout<<"\n                                                   ALL PENCILS\n";
        cout<<"                                                   ===========";
        cout<<"\n\n";
    file.open("Pencildata.txt", ios::in);
        file >> id >> brand >> thickness >> quantity  >> price;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tId: " << id << endl;
            cout << "\t\t\tBrand: " << brand << "\n";
            cout << "\t\t\tThickness: " << thickness << "\n";
            cout << "\t\t\tQuantity: " << quantity<< "\n";
            cout << "\t\t\tPrice: " << price << "\n";
            file >> id >> brand >> thickness >> quantity  >> price;
        }
        file.close();
}
void Pencils::modify(){
    Pencils::showAll();
    fstream file,file1;
    file.open("Pencildata.txt",ios::in);
    file1.open("Pencildata1.txt",ios::out|ios::app);
    int count = 0;
    int id1;
    string brand1,thickness1;
    int quantity1,price1;
    cout << "\n\n\t\t\t\tUpdate Pencils Record";
    file.open("Pencildata.txt",ios::in);
    file1.open("Pencildata1.txt",ios::out|ios::app);
    if (!file)
        cout << "\n\n\t\t\tFile Opening Error!";
    else {
        cout << "\n\n\t\t\tPencil ID : ";
        int m=10;
        cin >>id1;
        file >>id>>brand>>thickness>>quantity>>price;
        while (!file.eof()) {
            if (id1==id&&m==10){
            cout << "\n\n\t\t\tId: " << id << endl;
            cout << "\t\t\tBrand: " << brand << "\n";
            cout << "\t\t\tThickness: " << thickness << "\n";
            cout << "\t\t\tQuantity: " << quantity << "\n";
            cout << "\t\t\tPrice: " << price << "\n";
            cout << "\n\t\t\t\t"<< "Update Pencil Record";
    cout<<"\n\t\t\t               Id: ";
    cin>>id1;
    cout<<"\n\t\t\t               Brand: ";
    cin>>brand1;
    cout<<"\n\t\t\t               Thickness: ";
    cin>>thickness1;
    cout<<"\n\t\t\t               Quantity: ";
    cin>>quantity1;
    cout<<"\n\t\t\t               Price(each in rupees): ";
    cin>>price1;
    cout<<"\n\t\t\t               ClothData Updated Successfully!";
    file1 << " " << id1 << " "<< brand1<< " "<<thickness1<<" "<<quantity1<<" "<<price1<< "\n\n";
                count++;
                m=5;
            }
    else {
    file1 << " " << id << " "<< brand<< " "<<thickness<<" "<<quantity<<" "<<price<< "\n\n";
    }
       file >> id >> brand >> thickness >> quantity >> price;
        }
        if (count == 0)
            cout << "\n\nPenicl ID" << " Not Found...";
    }
    cout << endl;
    file.close();
    file1.close();
    remove("Pencildata.txt");
    rename("Pencildata1.txt","Pencildata.txt");
}
void Pencils::checkPencils(){
fstream file;
    int count=0;
    int code1;
    cout << "\n\n\t\t\t\tCheck "<< "Particular Pencil";
    file.open("Pencildata.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        cout << "\n\n\t\t\tPencil ID : ";
        cin >> code1;
        file >> id >> brand >> thickness >> quantity >> price;
        while (!file.eof()) {
                if (code1 == id) {
             cout << "\n\n\t\t\tId: " << id << endl;
            cout << "\t\t\tBrand: " << brand << "\n";
            cout << "\t\t\tThickness: " << thickness<< "\n";
            cout << "\t\t\tQuantity: " << quantity << "\n";
            cout << "\t\t\tPrice: " << price << "\n";
                count++;
                break;
            }
           file >> id >> brand  >> thickness >> quantity >> price;
        }
        file.close();
        if (count == 0)
            cout << "\n\nPencil ID Not"<< " Found...";
    }
}
void Pencils::buyPencils(string name,int a,int b){
fstream file, file1;
fstream file2;
file2.open("FinishedOrdersPencils.txt",ios::app|ios::out);
    int count = 0;
    file1.open("Pencildata1.txt",ios::app | ios::out);
    file.open("Pencildata.txt", ios::in);
    
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        int m=10;
        file >>id>>brand>>thickness>>quantity>>price;
        while (!file.eof()) {

            if (a==id&&m==10){
                if(quantity<b){
                    cout<<"\n\t\t\tProduct as per as your desire is not available\n\t\t\tIf you want to buy place an order of it\n";
               m=5;
               file1 << " " << id << " "<<brand<< " "<<thickness<<" "<<quantity << " " <<price<<"\n\n";
                }
                else{
    fstream f;
        f.open("Bill1.txt",ios::app|ios::out);
        f << " " << brand << " " << price << " " << b<< "\n";
        f.close();
    file2<<" "<<name<<" "<<a<<" "<<brand<<" "<<thickness<<" "<<b<<" "<<price<<"\n\n";
    file1 << " " << a << " "<< brand<< " "<<thickness<<" "<<quantity-b <<" "<<price<< "\n\n";
                count++;
                m=5;} }
    else {
    file1 << " " << id << " "<<brand<< " "<<thickness<<" "<<quantity << " " <<price<<"\n\n";
    }
       file >> id >> brand>> thickness >> quantity >> price;
        }
        if (count == 0)
            cout << "\n\nPencil ID" << " Not Found..."; }
    cout << endl;
    file.close();
    file1.close();
    remove("Pencildata.txt");
    rename("Pencildata1.txt","Pencildata.txt");
}
void Pencils::finishedOrders(){
    fstream file; 
    string name;
    file.open("FinishedOrdersPencils.txt",ios::in);
    file>>name>>id>>brand>>thickness>>quantity>>price;
    while(!file.eof()){
        cout<<"\n\t\t\tName: "<<name;
        cout<<"\n\t\t\tId: "<<id;
        cout<<"\n\t\t\tBrand: "<<brand;
        cout<<"\n\t\t\tThickness: "<<thickness;
        cout<<"\n\t\t\tQuantity: "<<quantity;
        cout<<"\n\t\t\tPrice: "<<price;
        file>>name>>id>>brand>>thickness>>quantity>>price;
    }
 }
void Pencils::takeOrders(){
fstream file;
file.open("PlaceordersPencils.txt",ios::in);
file>>brand>>thickness>>quantity;
while(!file.eof()){
   cout<<"\n\t\t\tBrand demanded: "<<brand;
   cout<<"\n\t\t\tThickness demanded: "<<thickness;
   cout<<"\n\t\t\tQuantity demanded: "<<quantity;
   file>>brand>>thickness>>quantity;
}
}
class Pens{
int id;
string thickness;
string brand;
string color;
int quantity;
int price;
public:
void MainMenu();
void showAll();
void addPens();
void modify();
void checkPens();
void takeOrders();
void finishedOrders();
void buyPens(string,int,int);
};
void Pens::MainMenu(){
system("cls");
       int c;
       do{
        cout<<"\n                                   ===========================";
        cout<<"\n                                   WELCOME TO PENS STOCK\n";
        cout<<"                                   ===========================\n";
        cout<<"\n\n";
        cout<<"                 1.View All Pens in the stock\n\n";
        cout<<"                 2.Add Pens\n\n";
        cout<<"                 3.Edit Pens\n\n";
        cout<<"                 4.Find Pens\n\n";
        cout<<"                 5.View the placed orders to be manufactured\n\n";
        cout<<"                 6.Exit\n\n";
        cout<<"                 Please Enter Required Option: ";
        cin>>c;
        switch (c){
        case 1:
        showAll();
        break;
        case 2:
        addPens();
        break;
        case 3:
        modify();
        break;
        case 4:
        checkPens();
        break;
        case 5:
        takeOrders();
        break;
        case 6:
        cout<<"n\t\t\tExiting\n";
        system("cls");
        break;
        default:
            break;
        }}while(c!=6);     
}
void Pens::addPens(){
    fstream file;
    cout<<"\n               Enter the details of the pens you want to add:\n";
        cout<<"\n               ID: ";
        cin>>id;
        cout<<"\n               Brand: ";
        cin>>brand;
        cout<<"\n               Thickness: ";
        cin>>thickness;
        cout<<"\n               Quantity: ";
        cin>>quantity;
        cout<<"\n               Color: ";
        cin>>color;
        cout<<"\n               Price(in Rupees): ";
        cin>>price;
        cout<<"\n               Pen Added Successfully!";
        file.open("Pendata.txt",ios::app|ios::out);
        file << " " << id << " " << brand << " " << thickness << " " << color <<" "<< quantity<< " " << price <<"\n";
        file.close();
}
void Pens::showAll(){
    fstream file;
        cout<<"\n                                                   ALL PENS\n";
        cout<<"                                                   ===========";
        cout<<"\n\n";
    file.open("Pendata.txt", ios::in);
        file >> id >> brand >> thickness >> color >> quantity  >> price;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tId: " << id << endl;
            cout << "\t\t\tBrand: " << brand << "\n";
            cout << "\t\t\tThickness: " << thickness << "\n";
            cout<<"\t\t\tColor: "<<color<<"\n";
            cout << "\t\t\tQuantity: " << quantity<< "\n";
            cout << "\t\t\tPrice: " << price << "\n";
            file >> id >> brand >> thickness >> color >> quantity  >> price;
        }
        file.close();
}
void Pens::modify(){
Pens::showAll();
    fstream file,file1;
    file.open("Pendata.txt",ios::in);
    file1.open("Pendata1.txt",ios::out|ios::app);
    int count = 0;
    int id1;
    string brand1,thickness1,color1;
    int quantity1,price1;
    cout << "\n\n\t\t\t\tUpdate Pens Record";
    file.open("Pendata.txt",ios::in);
    file1.open("Pendata1.txt",ios::out|ios::app);
    if (!file)
        cout << "\n\n\t\t\tFile Opening Error!";
    else {
        cout << "\n\n\t\t\tPen ID : ";
        int m=10;
        cin >>id1;
        file >>id>>brand>>thickness>>color>>quantity>>price;
        while (!file.eof()) {
            if (id1==id&&m==10){
            cout << "\n\n\t\t\tId: " << id << endl;
            cout << "\t\t\tBrand: " << brand << "\n";
            cout << "\t\t\tThickness: " << thickness << "\n";
            cout<<"\t\t\tColor: "<<color<<"\n";
            cout << "\t\t\tQuantity: " << quantity << "\n";
            cout << "\t\t\tPrice: " << price << "\n";
            cout << "\n\t\t\t\t"<< "Update Pen Record";
    cout<<"\n\t\t\t               Id: ";
    cin>>id1;
    cout<<"\n\t\t\t               Brand: ";
    cin>>brand1;
    cout<<"\n\t\t\t               Thickness: ";
    cin>>thickness1;
    cout<<"\n\t\t\t               Color: ";
    cin>>color1;
    cout<<"\n\t\t\t               Quantity: ";
    cin>>quantity1;
    cout<<"\n\t\t\t               Price(each in rupees): ";
    cin>>price1;
    cout<<"\n\t\t\t               ClothData Updated Successfully!";
    file1 << " " << id1 << " "<< brand1<< " "<<thickness1<<" "<<color<<" "<<quantity1<<" "<<price1<< "\n\n";
                count++;
                m=5;
            }
    else {
    file1 << " " << id << " "<< brand << " "<<thickness<<" "<<color<<" "<<quantity<<" "<<price<< "\n\n";
    }
       file >> id >> brand >> thickness>>color >> quantity >> price;
        }
        if (count == 0)
            cout << "\n\nPen ID" << " Not Found...";
    }
    cout << endl;
    file.close();
    file1.close();
    remove("Pendata.txt");
    rename("Pendata1.txt","Pendata.txt");
}
void Pens::checkPens(){
fstream file;
    int count=0;
    int code1;
    cout << "\n\n\t\t\t\tCheck "<< "Particular Pen";
    file.open("Pendata.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        cout << "\n\n\t\t\tPen ID : ";
        cin >> code1;
        file >> id >> brand >> thickness>>color >> quantity >> price;
        while (!file.eof()) {
                if (code1 == id) {
             cout << "\n\n\t\t\tId: " << id << endl;
            cout << "\t\t\tBrand: " << brand << "\n";
            cout << "\t\t\tThickness: " << thickness<< "\n";
            cout<<"\t\t\tColor: "<<color<<"\n";
            cout << "\t\t\tQuantity: " << quantity << "\n";
            cout << "\t\t\tPrice: " << price << "\n";
                count++;
                break;
            }
           file >> id >> brand  >> thickness>>color >> quantity >> price;
        }
        file.close();
        if (count == 0)
            cout << "\n\nPen ID Not"<< " Found...";
    }
}
void Pens::buyPens(string name,int a,int b){
fstream file, file1;
fstream file2;
    int count = 0;
    file1.open("Pendata1.txt",ios::app | ios::out);
    file.open("Pendata.txt", ios::in);
    file2.open("PlacedOrdersPens.txt",ios::app|ios::out);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
        int m=10;
        file >>id>>brand>>thickness>>color>>quantity>>price;
        while (!file.eof()) {

            if (a==id&&m==10){
                if(quantity<b){
                    cout<<"\n\t\t\tProduct as per as your desire is not available\n\t\t\tIf you want to buy place an order of it\n";
               m=5;
               file1 << " " << id << " "<<brand<< " "<<thickness<<" "<<color<<" "<<quantity << " " <<price<<"\n\n";
                }
                else{
    fstream f;
        f.open("Bill1.txt",ios::app|ios::out);
        f << " " << brand << " " << price << " " << b<< "\n";
        f.close();
    file2<<" "<<name<<" "<<a<<" "<<brand<<" "<<thickness<<" "<<color<<" "<<b<<" "<<price<<"\n\n";
    file1 << " " << a << " "<< brand<< " "<<thickness<<" "<<color<<" "<<quantity-b <<" "<<price<< "\n\n";
                count++;
                m=5;}
            }
    else {
    file1 << " " << id << " "<<brand<< " "<<thickness<<color<<" "<<quantity << " " <<price<<"\n\n";
    }
       file >> id >> brand>> thickness>>color >> quantity >> price;
        }
        if (count == 0)
            cout << "\n\nPen ID" << " Not Found...";
    }
    cout << endl;
    file.close();
    file1.close();
    remove("Pendata.txt");
    rename("Pendata1.txt","Pendata.txt");
}
void Pens::finishedOrders(){
    fstream file; 
    string name;
    file.open("PlacedOrdersPens.txt",ios::in);
    file>>name>>id>>brand>>thickness>>color>>quantity>>price;
    while(!file.eof()){
        cout<<"\n\t\t\tName: "<<name;
        cout<<"\n\t\t\tId: "<<id;
        cout<<"\n\t\t\tBrand: "<<brand;
        cout<<"\n\t\t\tThickness: "<<thickness;
        cout<<"\n\t\t\tColor: "<<color;
        cout<<"\n\t\t\tQuantity: "<<quantity;
        cout<<"\n\t\t\tPrice: "<<price;
        file>>name>>id>>brand>>thickness>>color>>quantity>>price;
    }
 }
void Pens::takeOrders(){
fstream file;
file.open("PlaceordersPens.txt",ios::in);
file>>brand>>thickness>>color>>quantity;
while(!file.eof()){
   cout<<"\n\t\t\tBrand demanded: "<<brand;
   cout<<"\n\t\t\tThickness demanded: "<<thickness;
   cout<<"\n\t\t\tColor demanded: "<<color;
   cout<<"\n\t\t\tQuantity demanded: "<<quantity;
   file>>brand>>thickness>>color>>quantity;
}
}
class Factory:public Pencils,public Pens{
    public:
    void menu();
    void adminstrator();
    void customer();
};
void Factory::menu(){
   int choice;
    do{
    cout<<"\t\t\t\t***********************************************\n";
    cout<<"\t\t\t\t                                               \n";
    cout<<"\t\t\t\t             FACTORY MAIN MENU                    \n";
    cout<<"\t\t\t\t                                               \n";
    cout<<"\t\t\t\t***********************************************\n"; 
    cout<<"\t\t\t\tEnter your choice\n\t\t\t\t1 adminstrator\n\t\t\t\t2 CUSTOMER\n\t\t\t\t3 exit\n";
    cout<<"\t\t\t\tEnter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
        adminstrator();
        break;
        case 2:
        customer();
        break;
        default:
        break;
}
}while(choice!=3);
}
void BillGeneration(){
         fstream f;
         f.open("Bill1.txt",ios::app|ios::in);
         string name;
         int q,p;
         int amount=0;
         system("cls");
         cout<<"***************************************************************************"<<endl;
         cout<<"S.No.               Product Name               Price               Quantity"<<endl;
         cout<<"***************************************************************************"<<endl;
         if (!f){
         cout << "\n\nFile Opening Error!";
         }
         else {
        f >> name>> q >> p;
        int i=1;
        while (!f.eof()) {
        amount+=p*q;
        cout<<setw(2)<<i<<"\t"<<setw(24)<<name<<"\t"<<setw(12)<<q<<"\t"<<setw(19)<<p<<endl;
        f >> name>> q >> p;
        i++;
        }
        f.close();
       }
       cout<<"***************************************************************************"<<endl;
       cout<<"Total Amount"<<setw(63)<<amount<<endl;
       cout<<"***************************************************************************"<<endl;

       fstream ofs;
       ofs.open("Bill1.txt", std::ofstream::out | std::ofstream::trunc);
       ofs.close();

}
void Factory::adminstrator(){
int choice;
do{
cout<<"\n\n\t\t\t\t******************************\n";
cout<<"\t\t\t\t       ADMINSTRATOR MENU\n";
cout<<"\t\t\t\t******************************\n";
cout<<"\t\t\t\tEnter your choice\n\t\t\t\t1 Pencils\n\t\t\t\t2 Pens\n\t\t\t\t3  \n\t\t\t\t4 Exit\n";
cout<<"\t\t\tEnter your choice: ";
cin>>choice;
switch(choice){
    case 1:
    Pencils::MainMenu();
    break;
    case 2:
    Pens::MainMenu();
    break;
    case 3:
    break;
    case 4:
    cout<<"\t\t\tExisting\n";
    break;
    default:
    break;
}
}while(choice!=4);
}
void Factory::customer(){
    int choice;
    string name;
    do{
    cout<<"\n\n\t\t\t\t******************************\n";
    cout<<"\t\t\t\t       CUSTOMER MENU\n";
    cout<<"\t\t\t\t******************************\n";
    cout<<"\t\t\tPress 1 for pencils\n\t\t\tPress 2 for pens\n\t\t\t3 exit\n";
    cout<<"\n\t\t\t\tEnter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
        Pencils::showAll();
        int c1;
    do{
    cout<<"\n\t\t\t******************************\n";
    cout<<"\t\t\t  Do you want to buy????";
    cout<<"\n\t\t\t******************************\n";
    cout<<"\n\t\t\tEnter your choice\n\t\t\t1 YES\n\t\t\t2 NO\n\t\t\t3 PLACE ORDER";
    cout<<"\n\t\t\tEnter your choice: ";
    cin>>c1;
    switch(c1){
    case 1:
    int a,b1;
    Pencils::showAll();
    cout<<"\n\t\t\t******************************\n";
    cout<<"\t\t\t\t LETS SHOP";
    cout<<"\n\t\t\t******************************\n";
    cout<<"\n\t\t\tEnter your name: ";
    cin>>name;
    cout<<"\t\t\tEnter the item id: ";
    cin>>a;
    cout<<"\t\t\tEnter the item quantity: ";
    cin>>b1;
    Pencils::buyPencils(name,a,b1);
    break;
    case 2:
    cout<<"\t\t\tExiting\n";
    break;
    case 3:
    cout<<"\n\t\t\tPLACING ORDER\n";
    string b,t;
    int q;
    cout<<"\n\t\t\tEnter brand: ";
    cin>>b;
    cout<<"\n\t\t\tEnter thickness: ";
    cin>>t;
    cout<<"\n\t\t\tEnter the quantity: ";
    cin>>q;
    fstream file;
    file.open("PlaceordersPencils.txt",ios::out|ios::app);
    file<<b<<" "<<t<<" "<<q<<"\n";
    }}while(c1!=2);
        break;
        case 2:
     int a,b;
    Pens::showAll();
        int c2;
    do{
    cout<<"\n\t\t\t******************************\n";
    cout<<"\t\t\t  Do you want to buy????";
    cout<<"\n\t\t\t******************************\n";
    cout<<"\n\t\t\tEnter your choice\n\t\t\t1 YES\n\t\t\t2 NO\n\t\t\t3 PLACE ORDER";
    cout<<"\n\t\t\tEnter your choice: ";
    cin>>c2;
    switch(c2){
    case 1:
    int a,b1;
    Pens::showAll();
    cout<<"\n\t\t\t******************************\n";
    cout<<"\t\t\t\t LETS SHOP";
    cout<<"\n\t\t\t******************************\n";
    cout<<"\n\t\t\tEnter your name: ";
    cin>>name;
    cout<<"\t\t\tEnter the item id: ";
    cin>>a;
    cout<<"\t\t\tEnter the item quantity: ";
    cin>>b1;
    Pens::buyPens(name,a,b1);
    break;
    case 2:
    cout<<"\t\t\tExiting\n";
    break;
    case 3:
    cout<<"\n\t\t\tPLACING ORDER\n";
    string b,t,c;
    int q;
    cout<<"\n\t\t\tEnter brand: ";
    cin>>b;
    cout<<"\n\t\t\tEnter thickness: ";
    cin>>t;
    cout<<"\n\t\t\tEnter color: ";
    cin>>c;
    cout<<"\n\t\t\tEnter the quantity: ";
    cin>>q;
    fstream file;
    file.open("PlaceordersPens.txt",ios::out|ios::app);
    file<<b<<" "<<t<<" "<<c<<" "<<q<<"\n";
    }}while(c2!=2);
        break;
        case 3:
        cout<<"\t\t\texit\n";
        BillGeneration();
        break;
    }}while(choice!=3);
}
int main(){
    Factory s;
    s.menu();
}