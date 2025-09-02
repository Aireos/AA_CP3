
//Basic #includes and usings
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
using namespace std;

//Sorter:

void sorter(int a[],int s){
    for (int i=0;i<s-1;i++){
        for (int j=0;j<s-i-1;j++){
            if (a[j]>a[j+1]) {
                int b=a[j];
                a[j]=a[j+1];
                a[j + 1]=b;
            }
        }
    }
}

int main() {
    int array[] = {3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    // Print the array before sorting
    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Call the sorter function (no return value needed)
    sorter(array, size);

    // Print the array after sorting
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
