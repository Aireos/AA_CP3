// AKA Enumeration

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <memory>
using namespace std;

enum Action{
    List = 1,
    Add,
    Update
};

enum class Action_2{
    List = 1,
    Add,
    Update
};

int main(){
    int input;

    cout <<
    "1: List invoices" << endl <<
    "2: Add invoices" << endl <<
    "3: Update invoices" << endl <<
    "Select: ";
    cin >> input;

    if (input == static_cast<int>(Action::List)){
        cout << "List invoices";
    }else if(input == Action::Add){
        cout << "I have not built this yet.";
    }else if(input == Action::Update){
        cout << "Suprisingly, I have not built this either";
    }else{
        cout << "Womp womp, not a option";
    }
}

// What is enumeration?
// where you can add options 
// How do you build enumeration?
// enum name{}
// How do we display our enumerator? 
// name::variable
// Why does it matter that enumerators are constants??
// because otherwise they could cover over the other one
// What is the default beginning enumerator? 
// 0
// How do you give a different default value?
// variable = value
// What is a strongly typed enumerator?
// where it will not let you cover over it
// How are strongly typed enumerators different from a normal one?
// because you can not cover over it