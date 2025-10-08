// AKA Movie Library

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <memory>
#include <set>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

enum menu {
    input_file = 1,
    view = 2,
    add = 3,
    deleting = 4,
    search = 5,
    exiting = 6
};

struct movie_parts {
    string name;
    string director;
    int year;
    string genre;
    string rating;
};

vector<movie_parts> movies;

int main() {
    while(true){
        cout << endl <<
            "1. input movies\n" <<
            "2. view all movies\n" <<
            "3. add movie\n" <<
            "4. remove movie\n" <<
            "5. search movies\n" <<
            "6. exit\n" <<
            "selection: ";
        int choice;
        cin >> choice;
        cout << endl;

        if (cin.fail()) {
            cout << "enter a number from 1 to 5 next time." << endl;
            continue;
        }

        if(choice == menu::input_file){
            cout << "What is the files name followed by .csv (example: movies.csv)?: ";
            string file_title;
            cin >> file_title;
            cout << endl;

            if (cin.fail()) {
            cout << "enter a string next time." << endl;
            continue;
            }

            ifstream ifile(file_title);
         

            if (ifile.is_open()) {
                string line;
                getline(ifile, line); 

                while (getline(ifile, line)) {
                    stringstream iss(line);
                    movie_parts current_movie;
                    string year_str;
                    
                    getline(iss, current_movie.name, ',');
                    getline(iss, current_movie.director, ',');
                    getline(iss, year_str, ',');
                    getline(iss, current_movie.genre, ',');
                    getline(iss, current_movie.rating, '\n');

                    try {
                        current_movie.year = stoi(year_str);
                        movies.push_back(current_movie);
                    } catch (...) {
                        if(!(line == "Movie Name,Director,Year,Genre,Rating")){
                        cout << "Invalid year data: " << year_str << " on line: " << line << endl;
                        }
                    }
                }
                ifile.close();
            }

            if (movies.empty()) {
                cout << "No data was read or file could not be opened." << endl;
            }
        }else if(choice == menu::view){
            for(int i = 0; i < movies.size(); i++){
                cout << "Movie #: " << i+1 << endl;
                cout << movies[i].name << endl;
                cout << movies[i].director << endl;
                cout << to_string(movies[i].year) << endl;
                cout << movies[i].genre << endl;
                cout << movies[i].rating << endl << endl;
            }
        }else if(choice == menu::add){

        }else if(choice == menu::deleting){

        }else if(choice == menu::search){

        }else if(choice == menu::exiting){
            break;
        }
    }

    ofstream ofile("movies.csv");
    ofile << "Movie Name,Director,Year,Genre,Rating\n";
    if(ofile.is_open()){
        for(int i = 0; i < movies.size(); i++){
            ofile << movies[i].name << ",";
            ofile << movies[i].director << ",";
            ofile << to_string(movies[i].year) << ",";
            ofile << movies[i].genre << ",";
            ofile << movies[i].rating << endl;
        }
    }



    return 0;
}
