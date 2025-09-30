// AKA High Score Leaderboard


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
#include <fstream>
using namespace std;

enum menu {
    add = 1,
    display = 2,
    exiting = 3
};

int main() {
    vector<int> file;
    string string_line;
    fstream ifile("high_scores.csv");

    if (ifile.is_open()) {
        while (getline(ifile, string_line)) {
            try {
                int score = stoi(string_line);
                file.push_back(score);
            } catch (...){
                cout << "Error pulling scores from file.";
                return 1;
            }
        }
        ifile.close();
    }
    while(true){
        cout << endl <<
        "1. Add score\n" <<
        "2. Display leaderboard\n" <<
        "3. exit\n" <<
        "selection: ";
        int choice;
        cin >> choice;
        cout << endl;
        if (cin.fail()) {
            cout << "enter a number from 1 to 3 next time." << endl;
            continue;
        }
        if(choice == menu::add){
            cout << "What score did you get?: ";
            int input;
            cin >> input;
            cout << '\n';
            if (cin.fail()) {
                cout << "That was not a number!" << '\n';
                return 1;
            }

            file.push_back(input);
        
            sort(file.rbegin(), file.rend());
        }else if(choice == menu::display){
            cout << "High scores:" << '\n';
            for (int i = 0; i < file.size(); i++) {
                cout << file[i] << '\n';
            }
        }else if(choice == menu::exiting){
            break;
        }else{
            cout << "enter a number from 1 to 3 next time." << endl;
        }
    }
    fstream ofile("high_scores.csv");

    if (!ofile.is_open()) {
        cout << "Error saving to file." << '\n';
        return 1;
    }
    for (int score : file) {
        ofile << score << '\n';
    }
    ofile.close();

    return 0;
}
