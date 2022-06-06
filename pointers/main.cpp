#include <iostream>
#include <new>
#include <vector>

void declaringAndInitiaizing(){
    
    //Declare and initialize pointer
    int* p_number {}; // Will initialize with nullptr
    double*  p_fractional_number{};
    //Explicitly initialize with nullptr
    int* p_number1{nullptr};
    int* p_fractional_number1{nullptr};
    //Pointers to different variables are  of the same size
    std::cout << "sizeof(int) : " << sizeof(int) << std::endl; // 4
    std::cout << "sizeof(double) : " << sizeof(double) << std::endl; // 8
    std::cout << "sizeof(double*) : " << sizeof(double*) << std::endl;
    std::cout << "sizeof(int*) : " << sizeof(int*) << std::endl;
    std::cout << "sizeof(p_number1) : " << sizeof(p_number1) << std::endl;
    std::cout << "sizeof(p_fractional_number1) : " << sizeof(p_fractional_number1) << std::endl;
    //It doesn't matter if you put the * close to data type or to varible name
    int*  p_number2{nullptr};
    int * p_number3{nullptr};
    int  *p_number4{nullptr};
    int *p_number5{}, other_int_var{};
    int* p_number6{}, other_int_var6{};	// Confusing as you wonder if other_int_var6
										//is also a pointer to int. It is not
										// The structure is exactly the same for the
										//previous statement
    std::cout << "sizeof(p_number5) : " << sizeof(p_number5) << std::endl;
    std::cout << "sizeof(other_int_var) : " << sizeof(other_int_var) << std::endl;
    std::cout << "sizeof(p_number6) : " << sizeof(p_number6) << std::endl;
    std::cout << "sizeof(other_int_var6) : " << sizeof(other_int_var6) << std::endl;
    //It is better to separate these declarations on different lines though
    int *p_number7{};
    int other_int_var7{}; // No room for confusion this time

    //Initializing pointers and assigning them data
    //We know that pointers store addresses of variables
    int int_var {43};
    int *p_int{&int_var};// The address of operator (&);
    
    std::cout << "Int var : " << int_var << std::endl;
    std::cout << "p_int (Address in memory)  : " << p_int << std::endl;

    //You can also change the address stored in a pointer any time
    int int_var1 {65};
    p_int = &int_var1; // Assign a different address to the pointer
    std::cout << "p_int (with different address)  : " << p_int << std::endl;

    //Can't cross assign between pointers of different types
    int *p_int1{nullptr};
    double double_var{33};

    //p_int = &double_var; // Compiler error

    //Dereferencing a pointer : 
    int* p_int2 {nullptr};
    int int_data {56};
    p_int2 = &int_data;

    std::cout << "value from pointer: " << *p_int2 << " var address from pointer: " << p_int2 << " var address : "<< &int_data << std::endl; // Dereferencing a pointer
}

void pointerToChar(){
    const char *message {"Hello World!"}; //read-only
    std::cout << "message : " << message << std::endl;

    //*message = "B"; // Compiler error because is read-only
    std::cout << "*message : " << *message << std::endl;

    //Allow users to modify the string
    char message1[] {"Hello World!"};
    message1[0] = 'B';
    std::cout << "message1 : " << message1 << std::endl;
}

void dynamicMemory(){
    //It is also possible to initialize the pointer with a valid
    //address up on declaration. Not with a nullptr
    
    int *p_number5{ new int}; // Memory location contains junk value
    int *p_number6{ new int (22) }; // use direct initialization
    int *p_number7{ new int { 23 } }; // use uniform initialization
    
    std::cout << std::endl;
    std::cout << "Initialize with valid memory address at declaration : " << std::endl;
    std::cout << "p_number5 : " << p_number5 << std::endl;
    std::cout << "*p_number5 : " << *p_number5 << std::endl; // Junk value
    
    std::cout << "p_number6 : " << p_number6 << std::endl;
    std::cout << "*p_number6 : " << *p_number6 << std::endl;
    
    std::cout << "p_number7 : " << p_number7 << std::endl;
    std::cout << "*p_number7 : " << *p_number7 << std::endl;
    
	 //Remember to release the memory
    delete p_number5;
    p_number5 = nullptr;
    
    delete p_number6;
    p_number6 = nullptr;
    
    delete p_number7;
    p_number7 = nullptr;

    //Can reuse pointers
    p_number5 = new int(81);
    std::cout << "*p_number : " << *p_number5 << std::endl;

    delete p_number5;
    p_number5 = nullptr;

    //Calling delete twice on a pointer : BAD!
    p_number5 = new int(99);
    std::cout << "*p_number5 : " << *p_number5 << std::endl;

    delete p_number5;

   std::cout << "Program is ending well" << std::endl;
}

void danglingPointer(){

    //Case1 : Uninitialized pointer

    int * p_number; // Dangling uninitialized pointer

    std::cout << std::endl;
    std::cout << "Case 1 : Uninitialized pointer : ." << std::endl;
    std::cout << "p_number : " << p_number << std::endl;
    std::cout << "*p_number : " << *p_number << std::endl; //CRASH!

    //Case 2 : deleted pointer
   
    std::cout << std::endl;
    std::cout << "Case 2 : Deleted pointer" << std::endl;
    int * p_number1 {new int{67}};

    std::cout << "*p_number1 (before delete) : " << *p_number1 << std::endl;

    delete p_number1;
        
    std::cout << "*p_number1(after delete) : " << *p_number1 << std::endl;
   
	//Case 3 : Multiple pointers pointing to same address
    
	std::cout << std::endl;
	std::cout << "Case 3 : Multiple pointers pointing to same address : " << std::endl;
	
    int *p_number3 {new int{83}};
    int *p_number4 {p_number3};
    
    std::cout << "p_number3 - " << p_number3 << " - " << *p_number3 << std::endl;
    std::cout << "p_number4 - " << p_number4 << " - " << *p_number4 << std::endl;
    
    //Deleting p_number3
    delete p_number3;
    
    //p_number4 points to deleted memory. Dereferncing it will lead to
	//undefined behaviour : Crash/ garbage or whatever
    std::cout<< "p_number4(after deleting p_number3) - " << p_number4 << " - " << *p_number4 << std::endl;

    //Solution1 : Initialize your pointers immediately upon declaration
    
	std::cout << std::endl;
	std::cout << "Solution 1 : " << std::endl;
    int *p_number5{nullptr};
    int *p_number6{new int(87)};
	
	//Check for nullptr before use
	if(p_number6!= nullptr){
		std::cout << "*p_number6 : " << *p_number6 << std::endl;
	}else{
        std::cout << "Invalid address" << std::endl;
    }

	//Solution 2 : 
    //Right after you call delete on a pointer, remember to reset
	//the pointer to nullptr to make it CLEAR it doesn't point anywere
    
	std::cout << std::endl;
	std::cout << "Solution 2 : " << std::endl;
    int *p_number7{new int{82}};
    
    //Use the pointer however you want
    std::cout << "p_number7 - " << p_number7 << " - " << *p_number7 << std::endl;
   
    delete p_number7;
    p_number7 = nullptr; // Reset the pointer
	
	//Check for nullptr before use
	if(p_number7!= nullptr){
		std::cout << "*p_number7 : " << *p_number7 << std::endl;
	}else{
        std::cout << "Invalid memory access!" << std::endl;
    }

	//Solution 3 
	//For multiple pointers pointing to the same address ,  Make sure there is
	//one clear pointer (master pointer) that owns the memory ( responsible for releasing when
    // necessary) , other pointers should only be able to dereference when the master pointer is valid
    
	std::cout << std::endl;
	std::cout << "Solution 3 : " << std::endl;
    int * p_number8 {new int{382}};// Let's say p_number8 is the master pointer
    int * p_number9 {p_number8};
    
    //Dereference the pointers and use them
    std::cout << "p_number8 - " << p_number8 << " - " << *p_number8 << std::endl;
    
    if(!(p_number8 == nullptr)){ // Only use slave pointers when master pointer is valid
        std::cout<< "p_number9 - " << p_number9 << " - " << *p_number9 << std::endl;
    }
    
    delete p_number8; // Master releases the memory
    p_number8 = nullptr;
    
    if(!(p_number8 == nullptr)){ // Only use slave pointers when master pointer is valid
        std::cout<< "p_number9 - " << p_number9 << " - " << *p_number9 << std::endl;
    }else{
        std::cerr << "WARNING : Trying to use an invalid pointer" << std::endl;
    }

    std::cout << "Program is ending well" << std::endl;

}

void nothrowTest(){
    try {
        while (true) {
            new int[100000000ul];   // throwing overload
        }
    } catch (const std::bad_alloc& e) {
        std::cout << e.what() << '\n';
    }
 
    while (true) {
        int* p = new(std::nothrow) int[100000000ul]; // non-throwing overload
        if (p == nullptr) {
            std::cout << "Allocation FAILED, returned nullptr\n";
            break;
        }
    }
}

void dynamicAllocatedArrays(){
    const size_t array_size{10};
    
    //Different ways you can declare an array
	//dynamically and how they are initialized
	
    double *p_salaries { new double[array_size]}; // salaries array will
															//contain garbage  values
    int *p_students { new(std::nothrow) int[array_size]{} }; // All values initialized to 0 
    
    double *p_scores { new(std::nothrow) double[array_size]{1,2,3,4,5}}; // Allocating memory space
																	// for an array  of size double
																	//vars. First 5 will be initialized
																	//with 1,2,3,4,5, and the 
																	//rest will be 0's.

    //nullptr check and use the allocated array
    if(p_scores){
        std::cout << "size of scores (it's a regular pointer) : " << sizeof(p_scores) << std::endl;
        std::cout << "Successfully allocated memory for scores."<< std::endl;
        
        //Print out elements. Can use regular array access notation, or pointer arithmetic
        for( size_t i{}; i < array_size ; ++i){
           std::cout << "value : " << p_scores[i] << " : " << *(p_scores + i) << std::endl; 
        }
    }

    delete [] p_salaries;
    p_salaries = nullptr;

    delete [] p_students;
    p_students = nullptr;

    delete [] p_scores;
    p_scores = nullptr;

    //Static arrays Vs dynamic arrays
    std::cout << "=====================================" << std::endl;

    int scores[10] {1,2,3,4,5,6,7,8,9,10}; // Lives on the stack

    std::cout << "scores size : " << std::size(scores) << std::endl;
    for( auto s : scores){
        std::cout << "value : " << s << std::endl;
    }

    int* p_scores1 = new int[10] {1,2,3,4,5,6,7,8,9,10}; // Lives on the heap.

    for( size_t i = 0 ; i < 10 ; i++ )
    {
        std::cout << i << ':' << p_scores1[i] << std::endl;
    }
    
}

int main(){

    //declaringAndInitiaizing();
    //pointerToChar();
    //dynamicMemory();
    //danglingPointer();
    //nothrowTest();
    dynamicAllocatedArrays();
    
    return 0;
}