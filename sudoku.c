#include <iostream>
#include <fstream>
#include <cmath>
std::ifstream infile;


bool s;                     //'s' for sudoku. Global boolean becomes true to indicate that sudoku() can exit.

bool checkCell(int* cells, int X, int Y, int num){
    //Helper function - checks rows, columns and boxes.
    int boxX = (X/3) * 3;       //give the top left corner of the corresponding box.
    int boxY = (Y/3) * 3;       //0-2, boxX = 0, 3-5 boxX = 3, 6-8 boxX = 6
    for (int x = 0; x < 3; x++){
        for (int y = 0; y < 3; y++){
            if(cells[9 * (boxX+x) + boxY+y] == num && boxX+x != X && boxY+y != Y){
                return false;
            }
        }
    }
    for(int i = 0; i < 9; i++){
        if(cells[9 * X + i] == num && i != Y){
            return false;
        }
        if(cells[9 * i + Y] == num && i != X){
            return false;
        }
    }
    return true;
}

void sudoku(int* cells, int X, int Y){
        for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            std::cout << cells[9 * i + j];
            if (j != 8) std::cout << ',';
        }
        std::cout << '\n';
    }
    //Recursively solves a sudoku puzzle through backtracking.
    //What is the base case? When all elements have been checked; when the row has exceeded the bottom row.
    if (X >= 9){
        s = true;
        return;
    }
    if(cells[9 * X + Y] == 0){             //If the cell is zero, we can write into it. If not, call the function at the next space.
        for(int i = 1; i < 10; i++){
            if(checkCell(cells, X, Y, i)){
                cells[9 * X + Y] = i;
                if(Y == 8){
                    sudoku(cells, X+1, 0);
                }else{
                    sudoku(cells, X, Y+1);
                }
            }
            if(s) return;
        }
        cells[9 * X + Y] = 0;               //Erase cells that are incorrect when backtracking before returnin.
    } else{
        if(Y == 8){
            sudoku(cells, X+1, 0);
        }else{
            sudoku(cells, X, Y+1);
        }
    }

    return;
}

int main(int argc, char *argv[]){
    char ch;
    int cells[10000];
    int num[5];                         //store digits here, to be converted to multiple digit ints from infile.
    int i = 0;
    int j = 0;
    infile.open(argv[1]);
    while (infile.get(ch)){              //prints eaach character individually as long as characters are there to print
        if (ch >= '0' and ch <= '9'){    //convert two dimensional array into one dimensional. Only take 0's or 1's.
		    cells[i] = ch - '0';
		    i++;
        }
    }

    int X = 0;
    int Y = 0;
    sudoku(cells, X, Y);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            std::cout << cells[9 * i + j];
            if (j != 8) std::cout << ',';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

