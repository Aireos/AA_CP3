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
    bool found = false;
    vector<User> users = {{"Jerry", "2", true}, {"Bob", "5", false}, {"Snap", "8", true}, {"Crackle", "8", false}, {"Pop", "8", true}, {"Larose", "8", false}, {"Alex", "8", true}, {"Wakefeild", "8", false}, {"Nick", "8", true}, {"Jonas", "8", false}};
    User newUser;
    cout << "Pick your username: ";
    cin >> newUser.name;
    for(const auto user: users){
        if(user.name == newUser.name){
            cout << "Welcome back, ";
            if (user.admin) {
                cout << "Admin ";
            }
            cout << newUser.name << endl;
            found = true;
        }
    }
    if(!found){}
    cout << "Pick your password: ";
    cin >> newUser.password;
    cout << "Are you a admin?(t or f): ";
    cin >> newUser.admin;

    return 0;
}