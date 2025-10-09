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
#include <algorithm>
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

    bool operator==(const movie_parts& other) const {
        return name == other.name &&
               director == other.director &&
               year == other.year &&
               genre == other.genre &&
               rating == other.rating;
    }
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
            cout << "enter a number from 1 to 5 next time.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(choice == menu::input_file){
            cout << "What is the files name followed by .csv (example: movies.csv)?: ";
            string file_title;
            cin >> file_title;
            cout << endl;

            if (cin.fail()) {
            cout << "enter a string next time.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
                cout << "No data was read or file could not be opened.\n";
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
            movie_parts movie;
            cout << "What is the name of the movie?: ";
            cin >> movie.name;
            cout << endl;
            cout << "What is the director of the movie?: ";
            cin >> movie.director;
            cout << endl;
            cout << "What is the year of the movie?: ";
            cin >> movie.year;
            cout << endl;
            if(cin.fail()){
                cout << "enter a number next time.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "What is the genre of the movie?: ";
            cin >> movie.genre;
            cout << endl;
            cout << "What is the rating of the movie?: ";
            cin >> movie.rating;
            cout << endl;
            movies.push_back(movie);
        }else if(choice == menu::deleting){
            movie_parts movie_choice;
            cout << "What is the name of the movie?: ";
            cin >> movie_choice.name;
            cout << endl;
            cout << "What is the director of the movie?: ";
            cin >> movie_choice.director;
            cout << endl;
            cout << "What is the year of the movie?: ";
            cin >> movie_choice.year;
            cout << endl;
            if(cin.fail()){
                cout << "enter a number next time.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "What is the genre of the movie?: ";
            cin >> movie_choice.genre;
            cout << endl;
            cout << "What is the rating of the movie?: ";
            cin >> movie_choice.rating;
            cout << endl;
            auto i = find_if(movies.begin(), movies.end(), [&movie_choice](movie_parts m){
                return m.name == movie_choice.name &&
               m.director == movie_choice.director &&
               m.year == movie_choice.year &&
               m.genre == movie_choice.genre &&
               m.rating == movie_choice.rating;
            });
            if(i != movies.end()){
                movies.erase(i);
                cout << "The movie has been removed!";
            } else {
                cout << "That movie does not exist!";
            }
        }else if(choice == menu::search){
            while (true) {
                cout << "Search by:\n"
                    << "1. Name\n"
                    << "2. Director\n"
                    << "3. Year\n"
                    << "4. Genre\n"
                    << "5. Rating\n"
                    << "6. Return to main menu\n"
                    << "selection: ";
                int search_choice;
                cin >> search_choice;
                cout << endl;

                if (cin.fail()) {
                    cout << "Invalid input. Please enter a number from 1 to 6.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                string query;
                cout << "Enter the value to search for: ";
                getline(cin, query);
                cout << endl;

                vector<movie_parts> results;

                if (search_choice == 6){
                    break;
                } 

                for (int i = 0; i < movies.size(); ++i) {
                    movie_parts current_movie = movies[i];
                    if (search_choice == 1) {
                        if (current_movie.name.find(query) != string::npos) {
                            results.push_back(current_movie);
                        }
                    } else if (search_choice == 2) {
                        if (current_movie.director.find(query) != string::npos) {
                            results.push_back(current_movie);
                        }
                    } else if (search_choice == 3) {
                        try {
                            int year_query = stoi(query);
                            if (current_movie.year == year_query) {
                                results.push_back(current_movie);
                            }
                        } catch (...) {
                            cout << "please enter a number.\n";
                        }
                    } else if (search_choice == 4) {
                        if (current_movie.genre.find(query) != string::npos) {
                            results.push_back(current_movie);
                        }
                    } else if (search_choice == 5) {
                        if (current_movie.rating.find(query) != string::npos) {
                            results.push_back(current_movie);
                        }
                    }else {
                        cout << "please enter a number from 1-6.\n";
                        break;
                    }
                }

                if (results.empty()) {
                    cout << "No movies found matching your search criteria.\n";
                } else {
                    cout << "Found " << results.size() << " result(s):\n";
                    for (int i = 0; i < results.size(); ++i) {
                        cout << "--------------------\n";
                        cout << "Name: " << results[i].name << endl;
                        cout << "Director: " << results[i].director << endl;
                        cout << "Year: " << results[i].year << endl;
                        cout << "Genre: " << results[i].genre << endl;
                        cout << "Rating: " << results[i].rating << endl;
                    }
                    cout << "--------------------\n";
                }
            }

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
