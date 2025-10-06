// AKA Movie Library

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <memory>
#include <set>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

struct movie_parts {
    
};

int main(){
    vector<movie_parts> file;
    if (ifile.is_open()) {
        score_parts complete_line;
        char comma;
        while (ifile >> complete_line.score >> comma && comma == ',' &&
               getline(ifile, complete_line.name, ',') &&
               ifile >> complete_line.date.day >> comma && comma == ',' &&
               ifile >> complete_line.date.month >> comma && comma == ',' &&
               ifile >> complete_line.date.year) {
            file.push_back(complete_line);
        }
        ifile.close();
    }
    return 0;
}