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
using namespace std;

struct Movie {
    int id;
    string title;
    int year;
};

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
    cout << "you entered " << first << " and " << second << endl;

    ofstream ofile;
    ofile.open("data.csv");
    if(ofile.is_open()){
        ofile << "1, Terminator 1, 1984\n2, Terminator 1, 1991";
        ofile.close();
    } else {
        cout << "error opening file";
    }

    vector<string> all_info;
    ifstream ifile;
    ifile.open("data.csv");
    if(ifile.is_open()){
        string str;
        while(getline(ifile, str, ',')){
            all_info.push_back(str);
        }
        string stri;
        vector<Movie> movies;
        while(getline(ifile, stri)){
            Movie movie;
            movie.id = stoi(all_info[0]);
            movie.title = all_info[1];
            movie.year = stoi(all_info[2]);
            movies.push_back(movie);

        }
        for (Movie i: movies){
        cout << "The movies id is " << i.id << ", name is " << i.title << ", and it was made in " << i.year << endl;
        }
    } else {
        cout << "error opening file";
    }
    ifile.close();

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
// while(getline(ifile, str, ',')){
// makes it seperate it out into more lines

// How do you read an entire CSV?
// while(getline(ifile, str, ',')){
// all_info.push_back(str);
// }

// How do you turn items from a CSV into objects of a structure?
//Structure_name variable;
//variable.type_name = type_change_if_applicable(string_from_line);
