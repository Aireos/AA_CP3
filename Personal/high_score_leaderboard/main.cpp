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

int string_to_intiger(string& s) {
    int result = 0;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            result = result * 10 + (c - '0');
        } else {
            cout << "Error getting scores from file!" << endl;
            return string("error");
        }
    }
    return result;
}

int main(){
    ifstream ofile("high_scores.txt");
    if (!ofile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    string string_line;
    vector<int> file;
    while (getline(ofile, string_line)) {
        int score = string_to_intiger(string_line);
        try{
            file.push_back(score);
        }catch(...){
            return 1;
        }
    }
    ofile.close();

    cout << "What score did you get?: ";
    int input;
    cin >> input;
    cout << endl;
    if(cin.fail()){
        cout << "That was not a number!";
        return 1;
    }

    file.push_back(input);
    for(int i = 0; i < file.size(); i++){
        cout << file[i];
    }

    ofstream ifile("high_scores.txt");
    if (!ifile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    for(int i = 0; i < size(file); i++){
        ifile << file[i] << endl;
    }
    ifile.close();
    return 0;
}