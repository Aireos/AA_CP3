// AAA Structures

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date {
    short year = 100;
    short month = 10;
    short day = 20;
};

struct Movie {
    string title;
    Date releaseDate;
    bool isPopular = true;
};

struct Customer {
    int id;
    string name;
    string email;
};

bool operator==(const Movie& first, const Movie& second){
    if(first.title == second.title &&
        first.releaseDate.year == second.releaseDate.year &&
        first.releaseDate.month == second.releaseDate.month &&
        first.releaseDate.day == second.releaseDate.day &&
        first.isPopular == second.isPopular){
            return true;
        }else{
            return false;
        }
}

ostream& operator<<(ostream& stream, Movie& movie){
    stream << movie.title;
    return stream;
}

int main(){
    // Movie movie;
    // movie.title = "Terminator";
    // Movie movie = {"Terminator", 1984};

    // auto [title, releaseYear, isPopular] {movie};

    // cout << "Movie Title: " << movie.title << endl;

    vector<Movie> movies;

    Movie movie1 = {"Terminator", 1987};
    Movie movie2 = {"Terminator 2", 1987};

    for (auto movie: movies){
        auto [title, releaseDate, isPopular] {movie};
        cout << "Movie Title: " << title << endl;
        cout << "Movie Year: " << releaseDate.year << endl;
        cout << "Movie Popular: " << isPopular << endl;
    }
    if(movie1 == movie2){
        cout << movie1 << "Equal" << endl;
    }

    // movie1.equals(movie2);

    Customer customer;
    customer.id = 1324;
    cout << "The customers id is: " << customer.id << endl;

    return 0;
}







// What are structures?
// way to define types to a variable sturctuer automaticly

// How do you build a structure?
// struct Structure_name {};

// What can be held in a structure?
// any variable type

// How do you access the information in a structure?
// Structure_name variable_name = "abasulatitly_realy_good_info";
// variable_name.info

// How do you overload an operator
// by defining a variable in a operator that is not a basic c++ symbol and tell it what to do