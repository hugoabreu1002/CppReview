#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <random>

void sizeOfArray(){

    int scores [] {1,2,5};
   
    int count { std::size(scores)}; // std::size( C++17)

    std::cout << "sizeof(scores) : " << sizeof(scores) << std::endl; //tamanho de todos os elementos juntos
    std::cout << "sizeof(scores[0]) : " << sizeof(scores[0]) << std::endl; //tamanho de um único elemento
    std::cout << "count of array: " << count << std::endl; //quantidade de elementos no array

    for ( auto i : scores){
        std::cout << "value  : " << i << std::endl;       
    }

}

void charArray(){
    //Declare array
    char message []  {"Hello"};
    std::cout << "message : " << message << std::endl;
    
    //Print out the array through looping
    
    std::cout << "message : ";
    for( auto c : message){
        std::cout << c ;
    }
    std::cout << std::endl;

    //Change characters in our array
    message[1] = 'a';
    //Print out the array through looping
    std::cout << "message : ";
    for( auto c : message){
        std::cout << c ;
    }
    std::cout << std::endl;

    // Will probably print garbage after your char array
    
    std::cout << "message : " << message << std::endl;
   
    //If a character array is null terminated, it's called as C-String
    
    char message1 [] {'H','e','l','l','o','\0'};
    std::cout << "message1 : " << message1 << std::endl;
    std::cout << "sizeof(message1) : " << sizeof(message1) << std::endl;
  
    char message2 [6] {'H','e','l','l','o'};
    std::cout << "message2 : " << message2 << std::endl;
    std::cout << "sizeof(message2) : " << sizeof(message2) << std::endl;
    char message3 [] {'H','e','l','l','o'}; // This is not a c string ,
											//as there is not null character
    std::cout << "message3 : " << message3 << std::endl;
    std::cout << "sizeof(message3) : " << sizeof(message3) << std::endl;

    //String literal
    
    char message4 [] {"Hello"};
    std::cout << "message4 : " << message4 << std::endl;
    std::cout << "sizeof(message4) : " << sizeof(message4) << std::endl;

    //Can't safely print out arrays other than those of characters
    int numbers [] {1,2,3,4,5};
    std::cout << "numbers :  " << numbers << std::endl;

}

namespace Math{
    template <typename T>
    T randomFrom(const T min, const T max){
        static std::random_device rdev;
        static std::default_random_engine re(rdev());
        typedef typename std::conditional<
            std::is_floating_point<T>::value,
            std::uniform_real_distribution<T>,
            std::uniform_int_distribution<T>>::type dist_type;
        dist_type uni(min, max);
        return static_cast<T>(uni(re));
    }
}

void randomValues(){
    
    std::srand(std::time(0)); // Seed
    int random_num = std::rand();
    std::cout << "random_num : " << random_num << std::endl; // 0 ~ RAND_MAX
    random_num = std::rand();
    std::cout << "random_num : " << random_num << std::endl; // 0 ~ RAND_MAX

    // Generate random numbers in a loop
    int random_num_loop;
    for(size_t i {0} ; i < 20 ; ++i){
        random_num_loop = std::rand();
        std::cout << "random_num_loop " << i << ":" <<  random_num_loop << std::endl; // 0 ~ RAND_MAX       
    }

    // Generate a range between 0 and 10
    int random_num_010 =  std::rand() % 11;                  // [ 0 ~10]
    for(size_t i {0} ; i < 20 ; ++i){
        random_num_010 = std::rand() % 11;
        std::cout << "random_num_010 " << i << "  :   " <<  random_num_010 << std::endl; // 0 ~ RAND_MAX       
    }

    int random_num_110 = std::rand() % 10 + 1 ; // [1~10]
    for(size_t i {0} ; i < 20 ; ++i){
        random_num_110 = std::rand() % 10 + 1;
        std::cout << "random_num_110 " << i << "  :   " <<  random_num_110 << std::endl; // 0 ~ RAND_MAX       
    }

    int random_num_func;
    for(size_t i {0} ; i < 20 ; ++i){
        random_num_func = Math::randomFrom(0,10);
        std::cout << "random_num_func " << i << "  :   " <<  random_num_func << std::endl; // 0 ~ RAND_MAX       
    }

}

int main(){

    //sizeOfArray();
    //charArray();
    randomValues();
   
    return 0;
}