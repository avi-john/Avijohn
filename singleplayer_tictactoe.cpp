#include <iostream>
#include <random>
using namespace std;

int board[9] = {0};
const char LETTERS[3] = {'X', ' ', 'O'};
const int lines[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

void display_board();
int score(int cell1, int cell2, int cell3);
bool playerwins(int playerletter);
bool canwin(int playerletter, int &winningsqaure);
void gethuman_move(int humanLetter);
void getcomputer_move(int computer_player);

int main() {
    bool ishumanturn;
    int human_player, computer_player, turn;

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dis(0, 1);

    human_player = 1 - 2 * dis(mt);
    computer_player = -human_player;
    ishumanturn = (human_player == 1);

    for (turn = 0; turn < 9; turn++) {
        if (ishumanturn) {
            gethuman_move(human_player);
        } else {
            getcomputer_move(computer_player);
        }
        int current_player = ishumanturn ? human_player : computer_player;
        if (playerwins(current_player)) {
            display_board();
            if (ishumanturn) {
                cout << "\nYou won";
            } else {
                cout << "\nComputer won";
            }
            return 0;
        }
        ishumanturn = !ishumanturn;
    }
    display_board();
    cout << "\nIt's a tie";
    return 0;
}

void display_board() {
    cout << "   |   |\n "
         << LETTERS[board[0] + 1] << " | " << LETTERS[board[1] + 1] << " | " << LETTERS[board[2] + 1] << "\n"
         << "   |   |\n"
         << "---+---+---\n"
         << "   |   |\n "
         << LETTERS[board[3] + 1] << " | " << LETTERS[board[4] + 1] << " | " << LETTERS[board[5] + 1] << "\n"
         << "   |   |\n"
         << "---+---+---\n"
         << "   |   |\n "
         << LETTERS[board[6] + 1] << " | " << LETTERS[board[7] + 1] << " | " << LETTERS[board[8] + 1] << "\n"
         << "   |   |\n";
}

int score(int cell1, int cell2, int cell3) {
    return board[cell1] + board[cell2] + board[cell3];
}

bool playerwins(int playerletter) {
    for (auto line : lines) {
        if (score(line[0], line[1], line[2]) * playerletter == 3)
            return true;
    }
    return false;
}

bool canwin(int playerletter, int &winningsqaure) {
    for (auto line : lines) {
        if (score(line[0], line[1], line[2]) * playerletter == 2) {
            if (board[line[0]] == 0) winningsqaure = line[0];
            else if (board[line[1]] == 0) winningsqaure = line[1];
            else if (board[line[2]] == 0) winningsqaure = line[2];
            return true;
        }
    }
    return false;
}

void getcomputer_move(int computerletter) {
    int winningSquare;

    if (canwin(computerletter, winningSquare)) {
        board[winningSquare] = computerletter;
    } else if (canwin(-computerletter, winningSquare)) {
        board[winningSquare] = computerletter;
    } else if (board[4] == 0) {
        board[4] = computerletter;
    } else {
        for (int i : {0, 2, 6, 8}) {
            if (board[i] == 0) {
                board[i] = computerletter;
                return;
            }
        }
        for (int i = 0; i < 9; ++i) {
            if (board[i] == 0) {
                board[i] = computerletter;
                return;
            }
        }
    }
}

void gethuman_move(int humanLetter) {
    display_board();
    int choice;
    do {
        cout << "Enter a move (1-9): ";
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8 || board[choice] != 0) {
            cout << "Invalid move. Try again.\n";
        }
    } while (choice < 0 || choice > 8 || board[choice] != 0);
    board[choice] = humanLetter;
}
