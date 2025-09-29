// AKA Text Files

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
#include <fstream>
#include <iomanip>
using namespace std;

int getNumber(string promt){
    int num;
    while(true){
        cout << promt;
        cin >> num;
        if(cin.fail()){
            cout << "Enter a valid number!\n";
        }else{break;}
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return num;
}

int main(){
    int first = getNumber("First: \n");
    int second = getNumber("First: \n");
    cout << "you entered " << first << " and " << second;

    ofstream file;
    file.open("data.csv");
    if(file.is_open()){
        file << "id, title, year\n1, Terminator 1, 1984\n2, Terminator 1, 1991";
        file.close();
    }

    return 0;
}

// What are the 3 main sources of data for a program
// Terminal: cout, cin (user given) | File: txt, csv, binary | Network: internet, other computers

// What are streams? 
// data source / destination

// What are the different streams we might need to include in a program? 
// istream, ostream

// What is the base class for all streams?
// 

// What is buffer?
// temporary storage in memory for reading values

// How do you clear the buffer?
// cin.ignore()

// How do you handle invalid inputs from the terminal
// cin.fail()

// What streams are for files specifically
// ifstream: input files to stream & ofstream ouput files from stream & fstream: combines first two

// How do you write to a text file?
// file << "text";

// What do stream manipulators let us do?
// ignore/change streams

// How do you write to a CSV?
// file << "text";

// How do you read a text file?
// file.open("name.txt")

// How do you read a CSV file?
// file.open("name.csv")

// What is a delimiter?
// 

// How do you read an entire CSV?
// 

// How do you turn items from a CSV into objects of a structure?
// 
