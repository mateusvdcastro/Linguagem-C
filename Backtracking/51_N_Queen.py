global N
N = 4

def solveNQueens():
    board = [[0, 0, 0, 0],
             [0, 0, 0, 0],
             [0, 0, 0, 0],
             [0, 0, 0, 0]]
    printSolution(board)

def printSolution(board):
    for i in range(N):
        for j in range(N):
            if (board[i][j] == 1):
                print("Q", end=" ")
            else:
                print(".", end=" ")
        print()

if __name__ == "__main__":
    solveNQueens()
