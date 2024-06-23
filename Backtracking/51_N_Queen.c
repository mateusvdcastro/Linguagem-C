/*
N_queen problem solution using backtracking

Pseudocode:
1. Start in the leftmost column
2. If all queens are placed return true
3. Try all rows in the current column. Check if queen can be placed here safely. If yes, place the queen.~
4. Recur to place rest of the queens
5. If placing queen in this row doesn't lead to a solution then remove the queen from this row and try next row.
6. If all rows have been tried and nothing worked, return false to trigger backtracking.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 4

bool is_valid_state(int state){
    if (state == 1){
        return true;
    }
}

int * get_candidates(int * state){
    return state;
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    
}

int main(){
    int * state = (int *)malloc(N *sizeof(int)); 
    /* State holds each queens positions, like: [1, 3, 0, 2] or [2, 0, 3, 1]*/

    if (is_valid_state(1) == true)
        printf("foi");

    
}
