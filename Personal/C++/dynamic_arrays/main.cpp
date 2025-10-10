// AKA Dynamic Arrays

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <memory>

using namespace std;

int main() {
    // Defining all the variables that will be used later in the program
    int capacity = 5;
    auto book_array = make_unique<string[]>(capacity);
    int positions = 0;
    string book_title;

    // Tells the user what the program does and how it works
    cout << "Welcome to the book list maker, list as many books as you can!\n";
    cout << "Type done to finish.\n";

    // Starting the while true loop that will run until they type done
    while (true) {
        cout << "Book: ";
        getline(cin, book_title);

        // Checks to see if the user is done
        if (book_title == "done") {
            break;
        }

        // Checks to make sure the user input something
        if (book_title.empty()) {
            continue;
        }

        // Checking if array needs to be increased in size
        if (positions >= capacity) {
            capacity++; // Increases the capacity of the array by one
            
            // Creates a new unique pointer for the larger array
            auto new_array = make_unique<string[]>(capacity);
            
            // Copy elements from the old array to the new one
            for (int i = 0; i < positions; i++) {
                new_array[i] = book_array[i];
            }
            
            book_array = move(new_array);
        }

        book_array[positions] = book_title;
        positions++;
    }

    // Outputs the final array and all the book names the user listed
    cout << "\nYour book list:\n";
    for (int i = 0; i < positions; i++) {
        cout << book_array[i] << "\n\n";
    }

    return 0;
}