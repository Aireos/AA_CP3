#include <iostream>
#include <string>
#include <limits>
#include <vector> // Note: std::vector would be the standard C++ solution
#include <cstdlib>
#include <ctime>
#include <utility>
#include <memory> // Required for unique_ptr and shared_ptr

using namespace std;

// This function takes a shared_ptr to demonstrate its use.
// It shares ownership of the pointer with the main function.
void demonstrateSharedPointer(shared_ptr<string> book_name) {
    cout << "\nShared pointer demonstrating a single book: " << *book_name << endl;
}

int main() {
    // Defining all the variables that will be used later in the program
    int initial_capacity = 5;
    
    // Replace the raw pointer with a std::unique_ptr for exclusive ownership.
    // Use std::make_unique for a modern, safer way to create it.
    auto book_array = make_unique<string[]>(initial_capacity);
    int capacity = initial_capacity;
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
            
            // Create a new unique_ptr for the larger array.
            auto new_array = make_unique<string[]>(capacity);
            
            // Copy elements from the old array to the new one.
            for (int i = 0; i < positions; i++) {
                new_array[i] = move(book_array[i]); // Using move is more efficient
            }
            
            // Move ownership from the old unique_ptr to the new one.
            // The old array is automatically deleted here.
            book_array = move(new_array);
        }

        book_array[positions] = book_title;
        positions++;
    }

    // Outputs the final array and all the book names the user listed
    cout << "\nYour book list:\n";
    for (int i = 0; i < positions; i++) {
        cout << book_array[i] << endl;
    }

    // Demonstrates a shared pointer.
    // Not a necessary part of the core logic, but shows a use case.
    if (positions > 0) {
        // Create a shared pointer to a book from the array.
        // We need to access the element via a raw pointer using .get().
        auto first_book = make_shared<string>(book_array[0]);
        demonstrateSharedPointer(first_book);
    }
    
    // No need for 'delete[] book_array;'.
    // The unique_ptr will automatically clean up the memory when it goes out of scope.

    return 0;
}
