#include <iostream>
#include <limits>

using namespace std;

const char EMPTY = ' ';
const char X = 'X';
const char O = 'O';

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void printBoard(char board[3][3]) {
  clearScreen();
  cout << "  1 2 3\n";
  for (int i = 0; i < 3; i++) {
    cout << i + 1 << " ";
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

bool isValidMove(char board[3][3], int row, int col) {
  return (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == EMPTY);
}

bool checkWin(char board[3][3], char player) {

  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }


  for (int i = 0; i < 3; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }


  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}

bool isBoardFull(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == EMPTY) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  char board[3][3] = {EMPTY, EMPTY, EMPTY,
                     EMPTY, EMPTY, EMPTY,
                     EMPTY, EMPTY, EMPTY};

  char currentPlayer = X;

  while (true) {
    printBoard(board);

    int row, col;
    cout << currentPlayer << "'s turn. Enter row and column (1-3): ";

    while (!(cin >> row >> col) || !isValidMove(board, row, col)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid move ";
    }

    board[row - 1][col - 1] = currentPlayer;

    if (checkWin(board, currentPlayer)) {
      printBoard(board);
      cout << currentPlayer << " wins!" << endl;
      break;
    } else if (isBoardFull(board)) {
      printBoard(board);
      cout << " tie!" << endl;
      break;
    }

    currentPlayer = (currentPlayer == X) ? O : X;
  }

  return 0;
}
