#include <iostream>
using namespace std;

int main() {
   
    const int ROWS = 4;
    const int COLS = 5;

   
    int matrix[ROWS][COLS] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    
    int nonZeroCount = 0;
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (matrix[r][c] != 0)
                nonZeroCount++;

   
    int sparseRep[3][nonZeroCount];

    int index = 0;  // Index for sparseRep columns
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (matrix[r][c] != 0) {
                sparseRep[0][index] = r;             // row index
                sparseRep[1][index] = c;             // column index
                sparseRep[2][index] = matrix[r][c]; // non-zero value
                index++;
            }

    
    cout << "Sparse Matrix Representation (row, col, value):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < nonZeroCount; j++) {
            cout << sparseRep[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
