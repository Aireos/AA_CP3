//Alexander Anderson, Tic Tac Toe

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main(){
    for (int i=0;i<9;i++){
        string board[3][3] = {{" "," "," "},{" "," "," "},{" "," "," "}};
        cout << "|" << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "|" << endl;
        cout << "|" << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "|" << endl;
        cout << "|" << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "|" << endl;

        
    }

    return 0;
}