//Written with Microsoft Copilot Assistance on Jan. 1st 2025

char board[3][3] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
};

char currentPlayer = 'X';

void setup() {
  Serial.begin(9600);
  printBoard();
}

void loop() {
  if (Serial.available() > 0) {
    char move = Serial.read();
    if (makeMove(move)) {
      printBoard();
      if (checkWin()) {
        Serial.print("Player ");
        Serial.print(currentPlayer);
        Serial.println(" wins!");
        while (true); // Stop the game
      }
      if (isBoardFull()) {
        Serial.println("It's a draw!");
        while (true); // Stop the game
      }
      switchPlayer();
    }
  }
}

void printBoard() {
  Serial.println();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      Serial.print(board[i][j]);
      if (j < 2) Serial.print(" | ");
    }
    Serial.println();
    if (i < 2) Serial.println("---------");
  }
  Serial.println();
}

bool makeMove(char move) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == move) {
        board[i][j] = currentPlayer;
        return true;
      }
    }
  }
  return false;
}

void switchPlayer() {
  if (currentPlayer == 'X') {
    currentPlayer = 'O';
  } else {
    currentPlayer = 'X';
  }
}

bool checkWin() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
  }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
  return false;
}

bool isBoardFull() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != 'X' && board[i][j] != 'O') {
        return false;
      }
    }
  }
  return true;
}
