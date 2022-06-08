#include <iostream>
#include <iomanip>
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

void testNumberSystems(){
    int number1 = 15;
    int number2 = 017;
    int number3 = 0x0f;
    int number4 = 0b00001111;

    cout << number1 << endl;
    cout << number2 << endl;
    cout << number3 << endl;
    cout << number4 << endl;

    int fonNumber{};
    cout << fonNumber << endl;
}

void testIntVars(){
    unsigned int number1 {10};
    unsigned int number2 {10};

    cout << number1 << endl;
    cout << number2 << endl;
}

void fracNumbers(){
       //Declare and initialize the variables
    float number1 {1.12345678901234567890f}; // Precision : 7
    double number2 {1.12345678901234567890}; // Precision : 15
    long double number3  {1.12345678901234567890L};
    
    //Print out the sizes
    cout << "sizeof float : " << sizeof(float) << endl;
    cout << "sizeof double : " << sizeof(double) << endl;
    cout << "sizeof long double : " << sizeof(long double) << endl;

    //Precision
    cout << setprecision(20); // Control the precision from cout.
    cout << "number1 is : " << number1 << endl; //7 digits
    cout << "number2 is : " << number2 << endl; // 15'ish digits
    cout << "number3 is : " << number3 << endl; // 15+ digits

    //Float problems : The precision is usually too limited
    //for a lot of applications
    float number4 = 192400023.0f;               // Error : narrowing conversion
    cout << "number4 : " << number4 << endl;

    //Scientific notation
    //What we have seen so far in terms of floating point types
    //is fixed notation. There is another notation, scientific
    //that is handy if you have really huge numbers or small numbers
    //to represent

    cout << "-------------------------" << endl;
    
    double number5 {192400023};
    double number6 {1.92400023e8};
    double number7 {1.924e8};           // Can ommit the lower 00023
                                        // for simplicity if our application allows that.
    double number8 {0.00000000003498};
    double number9 {3.498e-11}; // multiply with 10 exp(-11)
    
    cout << "number5 is : " << number5 << endl;
    cout << "number6 is : " << number6 << endl;
    cout << "number7 is : " << number7 << endl;
    cout << "number8 is : " << number8 << endl;
    cout << "number9 is : " << number9 << endl;

    //Infinity and Nan
    cout << endl;
    cout << "Infinity and NaN" << endl;
    
    double number10{ -5.6 };
    double number11{};//Initialized to 0
    double number12{};  //Initialized to 0

    //Infinity
    double result { number10 / number11 };
    
    
    cout << number10 << "/" << number11 << "  yields " << result << endl;
    cout << result << " + " << number10 << " yields " << result + number10 << endl;
    
    //NaN
    result = number11 / number12;
    
    cout << number11 << "/" << number12 << " = " << result << endl;
}

void booleanNumbers(){
    bool red_light {false};
    bool green_light{true};
    
    if(red_light == true){
        cout << "Stop!" << endl;
    }else{
        cout << "Go through!" << endl;
    }

    if(green_light){
        cout << "The light is green!" << endl;
    }else{
        cout << "The light is NOT green!" << endl;
    }

    //sizeof()
    cout << "sizeof(bool) : " << sizeof(bool) << endl;


    //Printing out a bool
    //1 -->> true
    //0 -->> false
    cout << endl;
    cout << "red_light : " << red_light << endl;
    cout << "green_light : " << green_light << endl;

    cout << boolalpha;
    cout << "red_light : " << red_light << endl;
    cout << "green_light : " << green_light << endl;
}

void testChars(){
    char character1 {'a'};
    char character2 {'r'};
    char character3 {'r'};
    char character4 {'o'};
    char character5 {'w'};
    
    cout << character1 << endl;
    cout << character2 << endl;
    cout << character3 << endl;
    cout << character4 << endl;
    cout << character5 << endl;

    //One byte in memory : 2^8 = 256 different values (0 ~ 255)
    cout << endl;
    
    char value = 65 ; // ASCII character code for 'A'
    cout << "value : " << value << endl; // A
    cout << "value(int) : " << static_cast<int>(value) << endl;
}

void autoType(){
    auto var1 {12};
    auto var2 {13.0};
    auto var3 {14.0f};
    auto var4 {15.0l};
    auto var5 {'e'};
    
    //int modifier suffixes
    auto var6 { 123u}; // unsigned
    auto var7 { 123ul}; //unsigned long
    auto var8 { 123ll}; // long long

    cout << "var1 occupies : " << sizeof(var1) << " bytes" << endl;
    cout << "var2 occupies : " << sizeof(var2) << " bytes" << endl;
    cout << "var3 occupies : " << sizeof(var3) << " bytes" << endl;
    cout << "var4 occupies : " << sizeof(var4) << " bytes" << endl;
    cout << "var5 occupies : " << sizeof(var5) << " bytes" << endl;
    cout << "var6 occupies : " << sizeof(var6) << " bytes" << endl;
    cout << "var7 occupies : " << sizeof(var7) << " bytes" << endl;
    cout << "var8 occupies : " << sizeof(var8) << " bytes" << endl;
}

int main() {

    //testOperations();
    //testIO1();
    //testIO2();
    //testNumberSystems();
    //testIntVars();
    //fracNumbers();
    //booleanNumbers();
    //testChars();
    autoType();
    
    return 0;
}
