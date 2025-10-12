// Alexander Anderson, Strings, Arrays, conditionals

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    // low level verison of random number generator
    int seconds = time(nullptr);
    srand(seconds);
    int num = rand() % 11;
    cout << num << endl;

    // Arrays needed the index # listed in bracked when the variable is set
    int grades[11] = {99,88,77,66,55,44,33,22,11,13,24};
    cout << grades[3] << endl;

    // Strings 
    string name = "Alexander";
    cout << name << endl;
    string sentence = "The slow yellow cat got thrown under the log";
    cout << sentence << endl;
    cout << sentence.length() << endl;
    cout << (name > sentence) << endl;
    // .starts_with()
    // .empty()

    name.append(" Anderson");
    name.insert(10, "K ");
    int first = sentence.find("cat");
    int end = first + 3;

    // searching the string
    cout << sentence.find("Alexander") << endl;
    cout << name.find("a") << endl;
    cout << name.find_first_of("a") << endl;
    cout << sentence.find_first_not_of("The slow") << endl;

    cout << sentence.substr(0,4) << endl;

    if(name < sentence){
        cout << name.front() << " is eariler in the alphabet than " << sentence.front() << endl;
    }else if(name > sentence){
        cout << name.front() << " is later in the alphabet than " << sentence.front() << endl;
    }else{
        cout << name.front() << " is the same as " << sentence.front() << endl;
    }

    return 0;
}

// What is Narrowing?
// converting a doable or float to a intiger or long

// What is a basic way to generate random numbers in C++?
// int seconds = time(nullptr);
// srand(seconds);
// int num = rand() % 11;
// cout << num << endl;

// What is an array?
// a list

// How do I create an array?
// int grades[11] = {99,88,77,66,55,44,33,22,11,13,24};

// How do you make strings in C?
// string sentence = "The slow yellow cat got thrown under the log";

// How did C++ improve creating strings? 
// it made a library for making strings simpler

// How do I search a string?
// using string methods listed bel

// How do I modify a string?
// using 

// What are some string methods?
// .length()           | returns the length
// .starts_with()      | checks if it starts with somthing
// .empty()            |
// .front()            | returns the first character
// .back()             | returns the last character
// .rfind()            | starts the search at the end of the string
// .find_first_of()    | gets first occurance of any character in the given string
// .find_last_of()     | gets last occurance of any character in the given string
// .find_first_not_of()| gets the first non-occurance of any character in the given string
// .find_last_not_of() | gets the last non-occurance of any character in the given string
// ----------------------------------------------------------
// .append()           | adds to the end of the string
// .erase()            | deletes the string
// .clear()            | emptys the string
// .replace()          | replaces the text inside the string

