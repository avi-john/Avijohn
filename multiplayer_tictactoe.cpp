#include <iostream>
using namespace std;
int checking(int player_playes[9]);
void display(char board[9]);
int player_plays(int &player_choice, char board[9]);
int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int rounds = 1;
    int player_choice;
    int player_playes1[9] = {0}, player_playes2[9] = {0};

    while (rounds <= 9) {
        display(board);

        if (rounds % 2 == 1) {
            cout << "\nPlayer X's turn.\n";
            player_choice = player_plays(player_choice, board);
            board[player_choice - 1] = 'X';
            player_playes1[player_choice - 1] = 1;

            if (checking(player_playes1)) {
                display(board);
                cout << "Player X wins!\n";
                return 0;
            }
        } else {
            cout << "\nPlayer O's turn.\n";
            player_choice = player_plays(player_choice, board);
            board[player_choice - 1] = 'O';
            player_playes2[player_choice - 1] = 1;

            if (checking(player_playes2)) {
                display(board);
                cout << "Player O wins!\n";
                return 0;
            }
        }

        rounds++;
    }

    display(board);
    cout << "It's a draw!\n";
    return 0;
}

void display(char board[9]) {
    cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        cout << " " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << "\n";
        if (i < 6) cout << "---|---|---\n";
    }
}

int player_plays(int &player_choice, char board[9]) {
    cout << "\nEnter the position (1-9): ";
    cin >> player_choice;
    while (player_choice < 1 || player_choice > 9 || board[player_choice - 1] == 'X' || board[player_choice - 1] == 'O') {
        cout << "Invalid move. Try again: ";
        cin >> player_choice;
    }
    return player_choice;
}

int checking(int player_playes[9]) {
    int win_combinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}             
    };

    for (int i = 0; i < 8; i++) {
        int a = win_combinations[i][0];
        int b = win_combinations[i][1];
        int c = win_combinations[i][2];

        if (player_playes[a] == 1 && player_playes[b] == 1 && player_playes[c] == 1) {
            return 1;
        }
    }
    return 0; 
}
