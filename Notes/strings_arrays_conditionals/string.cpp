// Alexander Anderson, Strings, Arrays, conditionals

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    // low level verison of random number generator
    int seconds = time(nullptr);
    srand(seconds);
    int num = rand() % 11;
    cout << num;
    return 0;
}