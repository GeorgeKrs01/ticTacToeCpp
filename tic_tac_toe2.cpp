#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>


void drawBoard(char board[3][3]) {
  printf("TRILIZA \n");
  printf("---------------------\n\n");

  printf("    1   2   3\n");
  for (int i = 0; i < 3; ++i) {
    printf("  ---+---+-----\n");
    printf("%d |", i + 1);
    for (int j = 0; j < 3; ++j) {
      printf(" %c |", toupper(board[i][j]));
    }
    printf("\n");
  }
}


bool checkWin(char board[3][3], char symbol) {

  for (int i = 0; i < 3; ++i) {
    if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) || 
        (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) { 
      return true;
    }
  }
    //Digonies
  if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) || 
      (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
    return true;
  }
  return false;
}


bool boardFull(char board[3][3]) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  };

  char player1Symbol, player2Symbol;

  bool validSymbol = false;
  while (!validSymbol) {
    printf("PAIKTH 1, me ti simvolo thes na paikseis? Apanta me 'O', 'o', 'X', 'x': ");
    scanf(" %c", &player1Symbol); 

    if (player1Symbol == 'X' || player1Symbol == 'x') {
        validSymbol = true;
        player2Symbol = 'O'; 
    }else if (player1Symbol == 'O' || player1Symbol == 'o'){
        validSymbol = true;
        player2Symbol = 'X'; 
    } 
    else {
      printf("Akyro symvolo, dwse 'x','X','o','O'.\n");
    }
  }

  bool player1Turn = true;
  bool gameOver = false;


    while (!gameOver) {

        drawBoard(board);
        int row, col;
        printf(player1Turn ? "PAIKTHS 1: " : "PAIKTHS 2: ");
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Akyri Eisagwgh! Try again.\n");
            continue;
        }

        system("CLS");

        if (player1Turn) {
            board[row - 1][col - 1] = player1Symbol;
            if (checkWin(board, player1Symbol)) {
                system("CLS");
				drawBoard(board);
                printf("PAIKTHS 1 WINS!\n");
                gameOver = true;
            } else if (boardFull(board)) {
                system("CLS");
				drawBoard(board);
                printf("Isopalia!\n");
                gameOver = true;
            }
            player1Turn = false;
        } else {
            board[row - 1][col - 1] = player2Symbol;
            if (checkWin(board, player2Symbol)) {
                system("CLS");
				drawBoard(board);
                printf("PAIKTHS 2 WINS!\n");
                gameOver = true;
            } else if (boardFull(board)) {
                system("CLS");
				drawBoard(board);
                printf("Isopalia!\n");
                gameOver = true;
            }
            player1Turn = true;
        }
    }

    return 0;
}
