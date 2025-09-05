// AKA Pointers

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
using namespace std;

int numbers[] = {4,2,6,8,14,24,65};
void divide(int* list, int size){
    for(int i; i < size; i++){
        list[i] = list[i]/2;
        cout << list[i] << endl;
    }
    cout << "this is my numbers list location " << list << endl;
    cout << "the first item in my numbers list is " << *list << endl;
}
int main(){
    int num = 4;
    int* pnum = &num;

    const double pi = 3.141592;

    cout << "The number is " << num << endl;
    cout << "The location of num is " << pnum << endl;
    divide(numbers,size(numbers));

    return 0;
}

// What is a pointer?
// hold addresses instead of info

// Why do we use pointers?
// To save room by getting info from a location instead of copying it over

// How do I create a pointer?
// int* variable = &second_variable;

// What is indirection or de-referencing? 
// using pointers you are able to get the location as well as getting the info over: pvariable: location, *pvariable: value

// What are constant pointers? How are the different types used? 
// they are where the data is constant but the pointer is constant as well: const variable_type* psecond_variable = &variable
// value of the item can not be changed, pointer can be changed: const variable_type* pvariable = &variable; | used so that you can use the value without accidently changing it and can change what the pointer is pointing to
// value of the item can be changed, pointer can not be changed: variable_type* const pvariable = &variable; | used so you cannot change where the pointer is pointing to and change the value
// value of the item and the pointer cannot be changed: const variable_type* const pvariable = &variable;    | used so you can use the value of a variable without changing the thing it is pointing at or the value of it

// How do you pass a pointer into a function?
// functon(int* list, int size){}

// Why would you pass a pointer to a function?
// so you can use data outside the function and being able to only do certain things with it

// How do you compare pointers?
// 

// What is dynamic memory allocation?
// it is when you use diffrent types of pointers to usethe memory better

// What is the Stack?
// 

// What is the Heap?
// 

// What are smart pointers?
// 
