// Alexander Anderson, Arrays Notes

#include <iostream>
#include <string>
#include <limits>
using namespace std;

string fam[5] = {"Micheal", "Starli", "Alex", "Mara", "Madi"};
string sibs[3] = {"Alex", "Mara", "Madi"};

int search(string list[], int len, string item) {
    for(int i=0; i < len; i++){
        if(list[i] == item){
            cout << "You are a sibling\n";
            return 1;
        }
    }
    cout << "you are a parent!\n";
    return 0;
}

int un_compacted_sorter(int array[], int len){
    for(int i=0;i<len-1;i++){
        for(int i=0;i<len-1;i++){
            int item_1 = array[i];
            int item_2 = array[i+1];
            if(item_1 > item_2){
                array[i] = item_2;
                array[i+1] = item_1;
            }
        }
    }
    for(int i=0;i<len;i++){cout << array[i];}
    return 0;
}

int sorter(int array[], int len){for(int i=0;i<len-1;i++){for(int i=0;i<len-1;i++){int item_1 = array[i];int item_2 = array[i+1];if(item_1 > item_2){array[i] = item_2;array[i+1] = item_1;}}}for(int i=0;i<len;i++){cout << array[i];}return 0;}

int main(){
    for(int i=0;i <size(fam);i++){
        cout << fam[i] << " Anderson\n";
        search(sibs,size(sibs), fam[i]);
    }
    cout << numeric_limits<long long>::min() << endl;
    cout << numeric_limits<long long>::max() << endl;
    cout << numeric_limits<size_t>::min() << endl;
    cout << numeric_limits<size_t>::max() << endl;

    //structed binding
    auto [a,s,d,f,g] = fam;
    cout << a << endl;

    //multi-dimensional arrays
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int array[5] = {5,4,3,2,1};

    sorter(array, size(array));

    return 0;
}

// How are for loops constructed in C++
// for(int i=0;i <size(fam);i++){}

// When do you need to use curly brackets in C++
// because it defines the inside of the for loop and other variables and functions

// How do you compare items in arrays
// if (fam[i] == sibs[i-2]){}

// How do you use an array as an argument in a function
// string list, int len

// What is type_t
// data type used to represent the size of objects

// Why would we use type_t
// uzed to see the largest or smallest type of info your computer/type can handle

// How do you search an array
// int search(string list[], int len, string item) {
//     for(int i=0; i < len; i++){
//         if(list[i] == item){
//             cout << "You are a sibling\n";
//             return 1;
//         }
//     }
// }

// How do you sort an array
// bubble sorting as follows:
// loop for the length of the array
// loop array
// select 2nd item (i)
// compare to 1st item (i-1)
// if i-1 bigger than i switch

// How do you make a multi-dimensional array
// int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};