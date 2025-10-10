// AKA Calculator Menu Options

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <memory>
using namespace std;

double Addition(double x, double y){
    return(x+y);
};

double Subtraction(double x, double y){
    return(x-y);
};

double Multiplcation(double x, double y){
    return(x*y);
};

double Division(double x, double y){
    return(x/y);
};

enum Action{
    Add = 1,
    Minus = 2,
    Times = 3,
    Divide = 4,
    Update
};

int main(){
    while(true){
        int input;

        cout << endl <<
        "1: Addition" << endl <<
        "2: Subtraction" << endl <<
        "3: Multiplication" << endl <<
        "4: Division" << endl <<
        "5: Exit" << endl <<
        "Select: ";
        cin >> input;
        double x;
        double y;
        cout << endl;
        if (input == Action::Add){
            cout << "First variable: ";
            cin >> x;
            cout << "Second variable: ";
            cin >> y;
            cout << "Answer: " << Addition(x,y) << endl;
        }else if(input == Action::Minus){
            cout << "First variable: ";
            cin >> x;
            cout << "Second variable: ";
            cin >> y;
            cout << "Answer: " << Subtraction(x,y) << endl;
        }else if(input == Action::Times){
            cout << "First variable: ";
            cin >> x;
            cout << "Second variable: ";
            cin >> y;
            cout << "Answer: " << Multiplcation(x,y) << endl;
        }else if(input == Action::Divide){
            cout << "First variable: ";
            cin >> x;
            cout << "Second variable: ";
            cin >> y;
            cout << "Answer: " << Division(x,y) << endl;
        }else if(input == Action::Update){
            cout << "Goodbye!";
            return 0;
        }else{
            cout << "Not a option.\n";
        }
    }
}