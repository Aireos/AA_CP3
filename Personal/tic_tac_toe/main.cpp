//Alexander Anderson, Tic Tac Toe

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
using namespace std;

bool winner_checker(string board[3][3]) {
    // checking rows for winners
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            cout << board[row][0] << " wins!\n";
            return true;
        }
    }
    // checking columns for winners
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            cout << board[0][col] << " wins!\n";
            return true;
        }
    }
    // checking diagonals for winners
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        cout << board[0][0] << " wins!\n";
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        cout << board[0][2] << " wins!\n";
        return true;
    }
    int used_tiles = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == "X" || board[row][col] == "O"){
                used_tiles++;
            }
        }
    }
    if (used_tiles == 9){
        cout << "It's a tie!\n";
        return true;
    }
    return false;
}

int main() {
    string board[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
    srand(time(nullptr));
    cout << "three x's in a row and you win! But if the computer gets three o's in a row...";
    for (int i = 0; i < 5; i++) {
        cout<<endl<<endl<<endl<<endl<<endl<<endl;

        cout << "|" << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "|\n";
        cout << "|" << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "|\n";
        cout << "|" << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "|\n";

        //input asking for where they want to place a x at
        cout << "Where do you want to put an X?: ";
        int placement;
        cin >> placement;

        // turning the users input into the correct placement
        int row = (placement - 1) / 3;
        int column = (placement - 1) % 3;

        // checking to make sure the users input is valid
        if (placement < 1 || placement > 9 || board[row][column] == "X" || board[row][column] == "O") {
            cout << "That is not a valid placement\n";
            i--;
            continue;
        }

        board[row][column] = "X";

        if(winner_checker(board)){break;}

        if (i != 4) {
            // computers turn
            bool computer_placed = false;
            while (!computer_placed) {
                row = rand() % 3;
                column = rand() % 3;

                // checking to see if the spot is availiable
                if (board[row][column] != "X" && board[row][column] != "O") {
                    board[row][column] = "O";
                    computer_placed = true;
                }
            }
        }
        
        if(winner_checker(board)){break;}
    }

    return 0;
}