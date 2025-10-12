
//Basic #includes and usings
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <memory>
#include <fstream>
using namespace std;

//Sorter:

void uncompacted_sorter(int a[], int s) {
    // ... (previous code to find mean and partition)
    int m = 0;
    for (int i = 0; i < s; i++) {
        m += a[i];
    }
    m = m / s;
    
    // FIRST PASS: Partition the array
    // Move all elements less than m to the beginning
    int next_pos = 0;
    for (int i = 0; i < s; i++) {
        if (a[i] < m) {
            int temp = a[i];
            a[i] = a[next_pos];
            a[next_pos] = temp;
            next_pos++;
        }
    }

    // SECOND PASS: Sort the first section (elements less than m)
    // You can use a bubble sort on the sub-array from index 0 to next_pos - 1
    for (int i = 0; i < next_pos; i++) {
        for (int j = 0; j < next_pos - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // THIRD PASS: Sort the second section (elements >= m)
    // Use a bubble sort on the sub-array from index next_pos to s - 1
    for (int i = next_pos; i < s; i++) {
        for (int j = next_pos; j < s - 1 - (i - next_pos); j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

//Compacted sorter
void sorter(int a[],int s){int m=0;for(int i=0;i<s;i++){m+=a[i];}m=m/s;int p = 0;for(int i=0;i<s;i++){if(a[i]<m){int b=a[i];a[i]=a[p];a[p]=b;p++;}}for(int i=0;i<p;i++){for(int j=0;j<p-i-1;j++){if(a[j]>a[j+1]){int b=a[j];a[j]=a[j+1];a[j+1]=b;}}}for(int i=p;i<s;i++){for(int j=p;j<s-1-(i-p);j++){if(a[j]>a[j+1]){int b=a[j];a[j]=a[j+1];a[j+1]=b;}}}}

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

// basic output and input to text file
int main(){
    // pulling from file
    ifstream ofile("high_scores.txt");
    if (!ofile.is_open()) {
        cout << "Error opening file!" << std::endl;
        return 1;
    }
    string line;
    while (getline(ofile, line)) {
        cout << line << endl;
    }
    ofile.close();

    //inputing to file
    ofstream ifile("high_scores.txt");
    if (!ifile.is_open()) {
        cout << "Error opening file!" << std::endl;
        return 1;
    }
    ifile << "hello!\nhi!";
    ifile.close();
}