#include <iostream>
using namespace std;
class TicTacToe {
private:
    char sticks[3][3]; 
    char player; 
public:
    TicTacToe() {
        for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
                sticks[a][b] = ' ';
            }
        }
        player = '0'; 
    }
    void ab() {
        cout << " --------------" << endl;
        for (int a = 0; a < 3; ++a) {
            cout << "|";
            for (int b = 0; b < 3; ++b) {
                cout << " " << sticks[a][b] << " |";
            }
            cout << endl;
            cout << " --------------" << endl;
        }
    }
    bool bc(int ab, int cd) {
        return ab >= 0 && ab < 3 && cd >= 0 && cd < 3 && sticks[ab][cd] == ' ';
    }
    void cd(int ab, int bc) {
        sticks[ab][bc] = player;
    }
    bool de() {
        for (int a = 0; a < 3; ++a) {
            if (sticks[a][0] != ' ' && sticks[a][0] == sticks[a][1] && sticks[a][0] == sticks[a][2]) {
                return true;
            }
        }
        for (int b = 0; b < 3; ++b) {
            if (sticks[0][b] != ' ' && sticks[0][b] == sticks[1][b] && sticks[0][b] == sticks[2][b]) {
                return true;
            }
        }
        if (sticks[0][0] != ' ' && sticks[0][0] == sticks[1][1] && sticks[0][0] == sticks[2][2]) {
            return true;
        }
        if (sticks[0][2] != ' ' && sticks[0][2] == sticks[1][1] && sticks[0][2] == sticks[2][0]) {
            return true;
        }
        return false;
    }
    bool ef() {
        for (int a = 0; a < 3; ++a) {
           for (int b = 0; b < 3; ++b) {
                if (sticks[a][b] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
    char fg() {
        player = (player == '0') ? 'X' : '0';
        return player;
    }
};
int main() {
    TicTacToe game;
    int ab, bc;
    cout << "Welcome to Tic Tac Toe!\n";
    game.ab();
    while (true) {
        cout << "Player " << game.fg() << "'s turn. Enter row and column (0-2): ";
        cin >> ab >> bc;
        if (!game.bc(ab, bc)) {
            cout << "Invalid move! Please try again.\n";
            continue;
        }
        game.cd(ab, bc);
        game.ab();
        if (game.de()) {
            cout << "Player " << game.fg() << " wins!\n";
            break;
        }
        if (game.ef()) {
            cout << "It's a draw!\n";
            break;
        }
    }
    return 0;
}