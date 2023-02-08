#include <iostream>
using namespace std;

// Example boards
int board[9][9] = {
   {5, 3, 0, 0, 7, 0, 0, 0, 0},
   {6, 0, 0, 1, 9, 5, 0, 0, 0},
   {0, 9, 8, 0, 0, 0, 0, 6, 0},
   {8, 0, 0, 0, 6, 0, 0, 0, 3},
   {4, 0, 0, 8, 0, 3, 0, 0, 1},
   {7, 0, 0, 0, 2, 0, 0, 0, 6},
   {0, 6, 0, 0, 0, 0, 2, 8, 0},
   {0, 0, 0, 4, 1, 9, 0, 0, 5},
   {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// int board[9][9] = {
//    {3, 0, 0, 8, 0, 1, 0, 0, 2},
//    {2, 0, 1, 0, 3, 0, 6, 0, 4},
//    {0, 0, 0, 2, 0, 4, 0, 0, 0},
//    {8, 0, 9, 0, 0, 0, 1, 0, 6},
//    {0, 6, 0, 0, 0, 0, 0, 5, 0},
//    {7, 0, 2, 0, 0, 0, 4, 0, 9},
//    {0, 0, 0, 5, 0, 9, 0, 0, 0},
//    {9, 0, 4, 0, 8, 0, 7, 0, 5},
//    {6, 0, 0, 1, 0, 7, 0, 0, 3}
// };

// int board[9][9] = {
//    {0, 8, 0, 0, 3, 0, 4, 0, 0},
//    {0, 0, 0, 0, 5, 0, 0, 0, 1},
//    {0, 0, 0, 0, 0, 4, 5, 8, 0},
//    {0, 5, 7, 0, 0, 0, 0, 9, 0},
//    {9, 0, 0, 0, 0, 0, 0, 0, 4},
//    {0, 3, 0, 4, 0, 0, 6, 5, 0},
//    {0, 7, 9, 2, 0, 0, 0, 0, 0},
//    {5, 0, 0, 0, 6, 0, 0, 0, 0},
//    {0, 0, 6, 0, 4, 0, 0, 2, 0}
// };

// Search the board for an empty tile - return false if incomplete
// Pass by ref allows solveBoard() to find the empty spot
bool isComplete(int &row, int &col) {
    for(row = 0; row < 9; row++) {
        for(col = 0; col < 9; col++) {
            if(board[row][col] == 0) {
                return false;
            }
        }
    }
    return true;
}

// Check 3x3 square containing the current tile to check for a number
bool checkInSquare(const int startRow, const int startCol, const int num) {
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(board[row+startRow][col+startCol] == num) {
                return true;
            }
        }
    }
    return false;
}

// Check the entire row of 9 containing the current tile to check for a number
bool checkInRow(const int row, const int num) {
    for(int col = 0; col < 9; col++) {
        if(board[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Check the entire column of 9 containing the current tile to check for a number
bool checkInCol(const int col, const int num) {
    for(int row = 0; row < 9; row++) {
        if(board[row][col] == num) {
            return true;
        }
    }
    return false;
}

// check if a num works for a given tile on the board
bool tryTile(int row, int col, int num) {
    int startingSquareRow = row - (row%3);
    int startingSquareCol = col - (col%3);
    if(!checkInRow(row, num) && !checkInCol(col, num) && !checkInSquare(startingSquareRow, startingSquareCol, num)) {
        return true;
    }
    return false;
}

// Recursive board solver
bool solveBoard() {
    // initialize row & col here so isComplete() can modify
    // these variables (pass by reference)
    int row, col;

    // Check for complete board
    if(isComplete(row, col)) {
        return true;
    }
    
    // Run through all possible numbers (1-9) for the given tile from isComplete()
    for(int num = 1; num <= 9; num++) {
        // Tests tile with given number. If fits, enter number, otherwise, iterate and try another
        if(tryTile(row, col, num)) {
            board[row][col] = num;
           
            // Recurses until board is solved. This means:
            //  - all recursions return true down to first recursion
            //  - there are no return false
            //  - if any solveBoard() call returns false, that means the board is impossible,
            //    so all recursions will return false until back at the original state
            if(solveBoard()) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

// Prints out a pretty version of the board
void printBoard() {
    for(int col = 0; col < 9; col++) {
        if((col%3) == 0) {
            cout << "- - - - - - - - - - - - - - - -\n";
        }
        for(int row = 0; row < 9; row++) {
            if(((row%3) == 0)) {
                cout << "|";
            }
            cout << " " << board[row][col] << " ";
        }
        cout << "|\n";
    }
    cout << "- - - - - - - - - - - - - - - -\n";
}

int main() {
    // solveBoard() returns true if successful, so that is utilized to return the board or failure to the user
    if(solveBoard()){
        printBoard();
    }
    else {
        cout << "impossible";
    }
}
