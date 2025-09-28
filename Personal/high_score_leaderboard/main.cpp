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

int main() {
    vector<int> file;
    string string_line;
    ifstream ifile("high_scores.txt");

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
    cout << endl;
    if (cin.fail()) {
        cout << "That was not a number!" << endl;
        return 1;
    }

    file.push_back(input);
    
    sort(file.rbegin(), file.rend());

    cout << "High scores:" << endl;
    for (int i = 0; i < file.size(); i++) {
        cout << file[i] << endl;
    }

    ofstream ofile("high_scores.txt");

    if (!ofile.is_open()) {
        cout << "Error saving to file." << endl;
        return 1;
    }
    for (int score : file) {
        ofile << score << endl;
    }
    ofile.close();

    return 0;
}
