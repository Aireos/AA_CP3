// AAA User Structure

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <memory>
#include <set>
using namespace std;

struct User {
    string name;
    string password;
    bool admin;
};

int main(){
    string users[10][3] = {{"Jerry", "2", "t"}, {"Bob", "5", "f"}, {"Snap", "8", "t"}, {"Crackle", "8", "f"}, {"Pop", "8", "t"}, {"Larose", "8", "t"}, {"Alex", "8", "t"}, {"Wakefeild", "8", "t"}, {"Nick", "8", "t"}, {"Jonas", "8", "t"}};
    User newUser;
    cout << "Pick your username: ";
    cin >> newUser.name;
    for(auto user: users){
        if(user[0] == newUser.name){
            cout << "Welcome back, ";
            if (newUser.admin = true){
                cout << "Admin " << newUser.name << endl;
            }
        }
    }
    cout << "Pick your password: ";
    cin >> newUser.password;
    cout << "Are you a admin?(t or f): ";
    cin >> newUser.admin;

    return 0;
}