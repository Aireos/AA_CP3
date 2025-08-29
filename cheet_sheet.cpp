

//Sorter: (still need to make it return the array and not just print it)
int sorter(int array[], int len){for(int i=0;i<len-1;i++){for(int i=0;i<len-1;i++){int item_1 = array[i];int item_2 = array[i+1];if(item_1 > item_2){array[i] = item_2;array[i+1] = item_1;}}}for(int i=0;i<len;i++){cout << array[i];}return 0;}
// needs: sorter(array_name,size(array_name))


//Basic #includes and usings
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;