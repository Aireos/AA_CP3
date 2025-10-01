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

struct date_parts {
    int day;
    int month;
    int year;
};

struct score_parts {
    int score;
    string name;
    date_parts date;
};

bool compareScores(score_parts a, score_parts b) {
    return a.score > b.score;
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<score_parts> file;
    fstream ifile("high_scores.csv");
    string line_part;
    
    if (ifile.is_open()) {
        score_parts complete_line;
        char comma;
        while (ifile >> complete_line.score >> comma && comma == ',' &&
               getline(ifile, complete_line.name, ',') &&
               ifile >> complete_line.date.day >> comma && comma == ',' &&
               ifile >> complete_line.date.month >> comma && comma == ',' &&
               ifile >> complete_line.date.year) {
            file.push_back(complete_line);
        }
        ifile.close();
    }
    
    sort(file.begin(), file.end(), compareScores);

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
            clearInputBuffer();
            cout << "enter a number from 1 to 3 next time." << endl;
            continue;
        }

        if(choice == menu::add){
            score_parts input;
            cout << "What score did you get?: ";
            cin >> input.score;
            if (cin.fail()) { clearInputBuffer(); cout << "That was not a number!" << '\n'; continue; }
            clearInputBuffer();
            
            cout << "What is your name?: ";
            getline(cin, input.name);
            if (cin.fail()) { clearInputBuffer(); cout << "That was not a name!" << '\n'; continue; }
            
            cout << "What is the current year?: ";
            cin >> input.date.year;
            if (cin.fail()) { clearInputBuffer(); cout << "That was not a number!" << '\n'; continue; }
            
            cout << "What is the current month (number)?: ";
            cin >> input.date.month;
            if (cin.fail()) { clearInputBuffer(); cout << "That was not a number!" << '\n'; continue; }
            
            cout << "What is the current day (number)?: ";
            cin >> input.date.day;
            if (cin.fail()) { clearInputBuffer(); cout << "That was not a number!" << '\n'; continue; }
            clearInputBuffer();

            file.push_back(input);
            sort(file.begin(), file.end(), compareScores);
        }else if(choice == menu::display){
            cout << "High scores:" << '\n';
            for (auto& entry : file) {
                cout << "Score: " << entry.score << ", Name: " << entry.name 
                     << ", Date: " << entry.date.month << "/" << entry.date.day 
                     << "/" << entry.date.year << '\n';
            }
        }else if(choice == menu::exiting){
            break;
        }else{
            cout << "enter a number from 1 to 3 next time." << endl;
        }
    }
    
    fstream ofile("high_scores.csv", ios::out | ios::trunc);

    if (!ofile.is_open()) {
        cout << "Error saving to file." << '\n';
        return 1;
    }
    for (auto& i : file) {
        ofile << i.score << "," << i.name << "," << i.date.day << "," << i.date.month << "," << i.date.year << '\n';
    }
    ofile.close();

    return 0;
}