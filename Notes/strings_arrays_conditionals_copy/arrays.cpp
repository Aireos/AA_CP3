// Alexander Anderson, Arrays Notes

#include <iostream>
using namespace std;

string fam[5] = {"Micheal","Starli","Alex","Mara","Madi"};
string sibs[3] = {"Alex","Mara","Madi"};

int main(){
    for(int i=0;i <size(fam);i++){
        cout << fam[i] << " Anderson\n";
        if (fam[i] == sibs[i-2]){
            cout << "They are my sibling!\n";
        }
    }
    return 0;
}

// How are for loops constructed in C++
// 
// When do you need to use curly brackets in C++
// 
// How do you compare items in arrays
// 
// How do you use an array as an argument in a function
// 
// What is type_t
// 
// Why would we use type_t
// 
// How do you search an array
// 
// How do you sort an array
// 
// How do you make a multi-dimensional array
// 