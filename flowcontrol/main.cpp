#include <iostream>

void ternaryOperator(){
	int max{};
    
    int a{35};
    int b{200};
	
    std::cout << std::endl;
	std::cout << "using regular if " << std::endl;
	
    /*
    if(a >  b){
        max = a;
    }else{
        max = b;
    }
    */

    max = (a > b)? a : b; // Ternary operator
	
    std::cout << "max : " << max << std::endl;
}

void ifConstExpr(){
    constexpr bool condition {false};

    if constexpr (condition){
        std::cout << "Condition is true" << std::endl;
    }else{
        std::cout << "Condition is false" << std::endl;
    }
    
}

void integerCondition(){
    int condition {5};

    bool bool_condition = condition;
    std::cout << std::boolalpha;

    if(bool_condition){
        std::cout << "We have a " << bool_condition << " in our variable from " << condition << std::endl; // different from 0
    }else
    {
        std::cout << "We have " << bool_condition << " in our variable from " << condition << std::endl; // zero
    }
}

void ifExpression(){
    bool go {false};

	if(int speed {10};go){
        std::cout << "speed : " << speed << std::endl;
		
		if(speed > 5){
			std::cout << "Slow down!" << std::endl;
		}else{
			std::cout << "All good!" << std::endl;
		}
	}else{
        std::cout << "speed : " << speed << std::endl;
		std::cout << "Stop" << std::endl;
	}

    //std::cout << "Out of the if block , speed : " << speed << std::endl;
}

void switchInitializer(){

    // Tools
    const int Pen{ 10 };
    const int Marker{ 20 };
    const int Eraser{ 30 };
    const int Rectangle{ 40 };
    const int Circle{ 50 };
    const int Ellipse{ 60 };

    int tool {Eraser};

    switch (double strength{3.56};tool)
    {
        case Pen : {
                std::cout << "Active tool is Pen. strength : " <<  strength << std::endl;
        }
        break;

        case Marker : {
                std::cout << "Active tool is Marker. strength : " <<  strength << std::endl;
        }
        break;


        case Eraser :
        case Rectangle : 
        case Circle : {
                std::cout << "Drawing Shapes. strength : " <<  strength << std::endl;
        }
        break;

        case Ellipse : {
                std::cout << "Active tool is Ellipse. strength : " <<  strength << std::endl;
        }
        break;

        default: {
            std::cout << "No match found. strength : " <<  strength << std::endl;
        }
        break;
    }

    std::cout << "Moving on" << std::endl;
    //strength++;

}

int main(){

	//ternaryOperator();
    //ifConstExpr();
    //integerCondition();
    //ifExpression();
    switchInitializer();
   
    return 0;
}