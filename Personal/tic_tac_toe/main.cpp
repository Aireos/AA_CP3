//Alexander Anderson, Tic Tac Toe

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    string board[3][3] = {{"1","2","3"},{"4","5","6"},{"7","8","9"}};
    for (int i=0;i<9;i++){
        cout << "|" << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "|\n";
        cout << "|" << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "|\n";
        cout << "|" << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "|\n";
        cout << "Where do you want to put an X?: ";
        int placement;
        cin >> placement;
        int row = (placement - 1)/3;
        int column = (placement-1)%3;
        int column_one[3] = {1,2,3};
        int column_two[3] = {1,2,3};
        int column_three[3] = {1,2,3};
        bool placement_validitity = true;
        if (placement > 9 || placement < 1 || board[row][column] == "X" || board[row][column] == "O"){
            cout << "That is not a valid placement\n";
            placement_validitity = false;
        }
        if (placement_validitity){
            board[row][column] = "X";
            int num;
            int seconds;
            if (num != 1-9){
                seconds = time(nullptr);
                srand(seconds);
                num = rand() % 11;
            }
            cout << num << endl;
        }
    }

    return 0;
}