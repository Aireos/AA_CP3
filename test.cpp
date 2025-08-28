#include <iostream>
#include <string>
#include <algorithm> // for std::find

using namespace std;

string fam[5] = {"Micheal", "Starli", "Alex", "Mara", "Madi"};
string sibs[3] = {"Alex", "Mara", "Madi"};

// Pass the C-style array as a pointer and its length separately.
void search(string* list, int len, string item) {
    // std::find can work with raw pointers and length.
    // The end iterator is calculated using pointer arithmetic: list + len.
    if (find(list, list + len, item) != list + len) {
        cout << "They are my sibling!\n";
    }
}

int main() {
    for (int i = 0; i < size(fam); i++) {
        cout << fam[i] << " Anderson: ";
        search(sibs, size(sibs), fam[i]);
    }
    return 0;
}
