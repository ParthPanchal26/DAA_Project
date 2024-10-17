#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 100

int rollDice() {
    return (rand() % 6) + 1;
}

void playGame(int board[], int n) {
    int player1Pos = 0, player2Pos = 0;
    int currentPlayer = 1;

    while (player1Pos < n - 1 && player2Pos < n - 1) {
        int dice;
        int *playerPos = (currentPlayer == 1) ? &player1Pos : &player2Pos;

        printf("\n-------------------------------------\nPlayer_%d Roll dice: press any key...\n-------------------------------------\n", currentPlayer);
        getchar();
        dice = rollDice();
        printf("Player_%d rolled a %d!\n", currentPlayer, dice);
        
        int newPos = *playerPos + dice;
        if (newPos >= n)
            newPos = *playerPos;
        
        if (board[newPos] != -1) {
            if (newPos < board[newPos]) {
                printf("Player_%d climbs a ladder from %d to %d!\n", currentPlayer, newPos, board[newPos]);
            } else {
                printf("Player_%d falls down a snake from %d to %d!\n", currentPlayer, newPos, board[newPos]);
            }
            newPos = board[newPos];
        }

        printf("Player_%d moves from %d to %d\n", currentPlayer, *playerPos, newPos);
        *playerPos = newPos;

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    if (player1Pos >= n - 1) {
        printf("\nPlayer_1 wins the game!\n");
    } else {
        printf("\nPlayer_2 wins the game!\n");
    }
}

int main() {
    srand(time(0));
    int board[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++)
        board[i] = -1;

    /* Ladders cells */
    board[2] = 21; 
    board[4] = 7;
    board[10] = 25;
    board[19] = 28;

    /* Snake cells */
    board[16] = 3;
    board[18] = 6;
    board[20] = 8;
    board[26] = 0;

    playGame(board, BOARD_SIZE);

    
    return 0;
}
