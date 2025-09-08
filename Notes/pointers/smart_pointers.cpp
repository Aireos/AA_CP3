// AKA Smart pointers

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <memory>
using namespace std;

int main(){
    unique_ptr <int> x(new int);
    unique_ptr <int> y = make_unique<int>();
//  auto y = make_unique<int>();
    *x = 10;
    *y = 7;
    cout << *x << endl;

    auto z = make_shared<int>();
    *z = 4;

    cout << *x << ", " << *y << ", " << *z << endl;
    return 0;
}