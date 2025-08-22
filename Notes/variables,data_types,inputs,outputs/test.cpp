// Alexander Anderson, Variables, Data Types, Inputs and Outputs notes

#include <iostream>
using namespace std;

int main(){
    //way to do it:
    // int students;
    // students = 11;
    //recomended to always do it this way though:
    int students = 11;
    //best practice is to do it the way up above and not to intitilize multiple variables in one line
    // const makes it so you can't change the value of the variable
    const float pi = 3.14f;
    //float will complile to double without f at the end
    short days = 5;
    long years = 2554l;
    bool on = true;
    char name = 'V';
    // simple print statement with line ender (acts like \n)
    std::cout << name<<std::endl;
    // multiple print statements in one line
    std::cout << "Number of students "<< students<<std::endl;
    //how to do an input:
    cout << "Tell me your age: ";
    int age;
    cin >> age;
    // how to do division
    cout << students/days;
    // how to make it so that it remains a certain data type:
    double divide = students/days;
    cout << divide;
    return 0;
}

//data types:
//short|2bytes|-32,768-32,768
//int|4bytes|-26-26
//long|4bytes|-26-26
//longlong|8bytes|big #'s
//floats|4bytes|3.4E38
//doubles|8bytes|1.7E308
//longdouble|8bytes|3.4E932
//bool|1bytes|true/false
//char|1bytes|single letter