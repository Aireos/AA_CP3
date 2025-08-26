//Alexander Anderson, User Login

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    set<string> admins = {"Bob","Joe"};
    set<string> users = {"Billy","Jerald","Max","Alex","Willy"};
    cout << "User login!" << std::endl;
    cout << "What is your username?: ";
    string username;
    cin >> username;
    if (admins.count(username) > 0) {
        cout << "Hello Admin " << username;
    } else if (users.count(username) > 0) {
        cout << "Welcome back " << username;
    } else {
        cout << "Lets get you signed up " << username;
    }
    return 0;
}   