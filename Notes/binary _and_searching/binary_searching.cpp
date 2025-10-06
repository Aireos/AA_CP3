#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

string d_t_i(double number, int precision){
    stringstream stream;
    stream << fixed << setprecision(precision) << number;
    return stream.str();
}

struct Movie{
    string title;
    int year;
};

int main(){
    double number = 3.14;
    cout << d_t_i(number, 2) << endl;

    string str = "10 20";
    stringstream stream;
    stream.str(str);
    int first;
    stream >> first;

    int second;
    stream >> second;

    cout << "first: " << first << endl << "second: " << second << endl;

    fstream file;
    file.open("file.txt",ios::in | ios::out | ios::app);
    if(file.is_open()){
        file.close();
    }

    string stri = "Terminator 1,1984";
    stringstream strem;
    stream.str(stri);
    Movie movie;
    getline(strem, movie.title, ',');
    strem >> movie.title;
    strem >> movie.year;
    cout << movie.title;
    cout << movie.year;

    return 0;
}

// What is a potential issue with converting values to strings without control?
// values after the value you wanted such as 3.140
// How can you control the way a value is converted to a string?
// stream << fixed << setprecision(precision) << number;
// Why is it useful to create a reusable function for converting values to strings?
// because then it is easy to use when needed
// What is parsing in the context of working with strings?
// splitting a string into multiple parts
// How do you extract specific information from a string in programming?
// by splitting it
// When a title contains a space, which function should you use to read it properly?
// 
// Why might extra zeros be added to a string when converting a value without control?
// because it goes to the maximum character limet. 
// How does controlling the string conversion process benefit your program?
// More understandable and storage is better
// Give an example scenario where parsing a string would be necessary in a program.
// to separate out a users response into two parts
// Why are images, audio, and PDFs not readable by humans when stored in files?
// because they are stored in 1's and 0's
// What file extensions are commonly used to create binary files?
// 
// When writing to a binary file, what does the first parameter (reinterpret_cast<char*>(&numbers)) represent?
// 
// Why does the binary file only take 12 bytes while the array of integers might be larger?
// 
// How does reading individual numbers from a binary file differ from reading the entire list at once?
// 
// What is the main difference between sequential search and binary search?
// 
// In which type of data structure is binary search most efficient?
// 
// What is a key requirement for binary search to work correctly on a list?
// 
// How does sequential search find an item in a list?
// 
// Why is binary search generally faster than sequential search for large, sorted lists?
// What is a potential issue with converting values to strings without control?