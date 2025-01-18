#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
int playerTurn = 0;

// Function Prototypes
void initializeBoard();
void displayBoard();
int isValidMove(int move);
void updateBoard(int move, char symbol);
int checkWinner();
int isDraw();
void switchPlayer();

int main() {
    int move, gameOn = 1;
    char symbols[] = {'X', 'O'};

    srand(time(0));
    playerTurn = rand() % 2;  // Randomly selecting starting player

    printf("Welcome to Two-Player Tic-Tac-Toe!\n");
    printf("Player 1: X\nPlayer 2: O\n\n");

    while (gameOn) {
        initializeBoard();
        int winner = 0;

        while (!winner && !isDraw()) {
            displayBoard();
            printf("Player %d's Turn (%c): Enter your move (1-9): ", playerTurn + 1, symbols[playerTurn]);
            scanf("%d", &move);

            if (isValidMove(move)) {
                updateBoard(move, symbols[playerTurn]);
                winner = checkWinner();

                if (!winner && !isDraw()) {
                    switchPlayer();
                }
            } else {
                printf("Invalid move! Try again.\n");
            }
        }

        displayBoard();

        if (winner) {
            printf("Congratulations! Player %d (%c) wins!\n", playerTurn + 1, symbols[playerTurn]);
        } else if (isDraw()) {
            printf("It's a draw!\n");
        }

        printf("Do you want to play another game? (1 for Yes, 0 for No): ");
        scanf("%d", &gameOn);

        if (gameOn) {
            playerTurn = rand() % 2;  // Randomize the starting player again
        }
    }

    printf("Thanks for playing! Goodbye.\n");
    return 0;
}

void initializeBoard() {
    int position = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + position++;
        }
    }
}

void displayBoard() {
    system("clear");  // Use "clrscr()" for Turbo C
    printf("\nTic-Tac-Toe Board:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int isValidMove(int move) {
    if (move < 1 || move > 9) return 0;
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return board[row][col] >= '1' && board[row][col] <= '9';
}

void updateBoard(int move, char symbol) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = symbol;
}

int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

int isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') return 0;
        }
    }
    return 1;
}

void switchPlayer() {
    playerTurn = 1 - playerTurn;
}
