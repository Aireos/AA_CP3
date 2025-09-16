// AAA Structures

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Movie {
    string title;
    int releaseDate;
    bool isPopular = true;

    bool equals(Movie movie){
        if(title == movie.title){
            cout << "AHHHHHHH";
        }
    }
};

struct Customer {
    int id;
    string name;
    string email;
};

struct Date {
    short year = 100;
    short day = 20;
};

int main(){
    // Movie movie;
    // movie.title = "Terminator";
    // Movie movie = {"Terminator", 1984};

    // auto [title, releaseYear, isPopular] {movie};

    // cout << "Movie Title: " << movie.title << endl;

    vector<Movie> movies;

    for (auto movie: movies){
        auto [title, releaseDate, isPopular] {movie};
        cout << "Movie Title: " << title << endl;
        cout << "Movie Year: " << releaseDate << endl;
    }

    Movie movie1 = {"Terminator", 1984};
    Movie movie2 = {"Terminator", 1984};
    movie1.equals(movie2);

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
// 