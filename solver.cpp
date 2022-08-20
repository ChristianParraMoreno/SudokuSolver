#include <iostream>
#include <cmath>
using namespace std;

bool posible(int row, int col, int num, int sudoku[9][9]);

bool emptySpot(int sudoku[9][9], int locations[]);

bool solve(int sudoku[9][9]);

void printSudoku(int sudoku[9][9]);




int main(){

    int sudoku[9][9] = 
    {
        {1,7,4,  0,0,2,  0,0,5},
        {0,0,0,  0,0,0,  0,0,0},
        {9,0,0,  0,0,4,  0,8,0},

        {0,0,3,  2,0,0,  0,5,0},
        {0,0,0,  6,3,0,  0,0,0},
        {2,0,0,  0,0,9,  0,1,0},

        {0,0,9,  0,4,6,  0,0,7},
        {3,0,0,  0,0,0,  0,0,6},
        {8,0,0,  0,0,5,  0,0,4}
    };

    //cout << posible(0,6,9,sudoku) << endl;
    printSudoku(sudoku);

    solve(sudoku);

    printSudoku(sudoku);




};

bool posible(int row, int col, int num, int sudoku[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        if(sudoku[i][col] == num && i != row)
        {
            return false;
        } 
    }

    for(int i = 0; i < 9; i++)
    {
        if(sudoku[row][i] == num && i != col)
        {
            return false;
        }
    }

    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;

    for(int i = 0 ; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(sudoku[boxRow + i][boxCol + j] == num && (boxRow + i != row || boxCol + j != col))
            {
                return false;
            }
        }
    }

    return true;


};


bool solve(int sudoku[9][9])
{
    int locations[2];
    printSudoku(sudoku);

    if(emptySpot(sudoku, locations) == false)
    {
        return true;
    }

    cout << "row: " << locations[0] << " col:  " << locations[1] << endl;

    for(int num = 1; num < 10; num++)
            {
                if(posible(locations[0],locations[1],num,sudoku) == true)
                {
                    sudoku[locations[0]][locations[1]] = num;

                    if(solve(sudoku) == true){
                        return true;
                    }

                    sudoku[locations[0]][locations[1]] = 0;

                    
                    
                }
            }
            return false;






}

bool emptySpot(int sudoku[9][9], int locations[])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(sudoku[i][j] == 0)
            {
                locations[0] = i;
                locations[1] = j;
                return true; 
            }
        }
    }
    return false;

}




void printSudoku(int sudoku[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        if(i != 0 && (i % 3 == 0))
        {
            cout << "------------------" << endl;
        }
        for(int j = 0; j < 9; j++)
        {
            if(j!= 0 && j % 3 == 0)
            {
                cout << '|';
            }
            cout << sudoku[i][j];
        }
        cout << endl;
    }

    cout << '\n' << '\n' << '\n';
}