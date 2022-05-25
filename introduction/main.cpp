#include <iostream>
#include<string.h>

using namespace std;

int addInt(int a, int b){
    return a+b;
}

double mulDouble(double a, double b){
    return a*b;
}

void testOperations(){
    cout << "Value Sum Int : "<< addInt(2,2) << endl;
    cout << "Value Sum Double: "<< mulDouble(6.7,5.3) << endl;
}

void testIO1(){
    cerr << "Hi are you joseph ?" << endl;
    string name, surname;
    cin >> name >> surname;
    
    if (name != "joseph") {
        cerr << "not joseph error" << endl;
        cerr << "get off " + name + " " + surname << endl;
    }
    else{
        clog << "hello " + name + " " + surname + " how U doing?" << endl;
    }
}

void testIO2(){
  string name;
  cout << "Please, enter your full name: ";
  getline (cin,name);
  cout << "Hello, " << name << "!\n";
}

int main() {

    //testOperations();
    testIO1();
    //testIO2();
    
    return 0;
}
