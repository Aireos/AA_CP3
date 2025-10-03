#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string f(vector<auto> f_string) {
    return f_string.str();
}

int main() {
    string name = "John";
    int age = 30;
    
    cout << f(static_cast<stringstream>(stringstream() << "Hello, my name is " << name << ", and I am " << age << " years old."));
}
