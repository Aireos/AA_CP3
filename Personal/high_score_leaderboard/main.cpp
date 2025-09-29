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
    exit = 3
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

    cout << "High scores:" << '\n';
    for (int i = 0; i < file.size(); i++) {
        cout << file[i] << '\n';
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
