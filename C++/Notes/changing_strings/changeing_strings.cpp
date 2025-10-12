// AKA Changing Strings

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
using namespace std;

string name = "Alexander Anderson";
string sentance = "The slow yellow cat got thrown under the log";

int main(){
    string first_name = name.substr(0,name.find(' '));
    string last_name = name.substr(name.find(' ')+1);
    first_name[0] = toupper(first_name[0]);
    //tolower does the opposite (makes it lowercase)
    cout <<first_name<<endl<<last_name<<endl;
    for(int i=0; i < size(sentance); i++){
        if (isspace(sentance[i])){
            sentance[i] = '_';
        }else if(isupper(sentance[i])){
            sentance[i] = tolower(sentance[i]);
        }else{
            sentance[i] = char((int(sentance[i]) + 4) %26 + 97);
        }
    }
    cout << sentance << endl;
    cout << R"(This is a "Question". . . I think)" << endl;
    return 0;
}

// How do I get a substring from within a string?
// name.substr(i)
// How do I create an escape character in C++
// \
// How do I convert a string to another data type?
// sto(first letter of data type)(string)
// What is a raw string and when would I use it?
// R"(text)", can be used to print what is in the string exactly 