// Alexander Anderson, Fahrenheit to Celsius

//importing iostream and making std easyer to use
#include <iostream>
using namespace std;

//defining main function
int main(){
    //doing two print statments for telling them what the program is and what i need them to import
    cout << "Fahrenheit to Celsius converter!" << std::endl;
    cout << "What is the temprature in fahrenheit?: ";
    //doing the input and defining both needed variables
    double fahrenheit;
    cin >> fahrenheit;
    double celsius;
    //doing the calculation to turn fahrenheit to celsius
    celsius = (fahrenheit - 32) * (5.0/9.0);
    //printing the conversion
    cout << fahrenheit << " in fahrenheit is equal to " << celsius << " in celsius.";
    return 0;
}