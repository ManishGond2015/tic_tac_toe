#include <bits/stdc++.h>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int ptr, col, row;
char marker;
int player, won;
void board_layout()
{
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << '\n';
    cout << "---------" << '\n';
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << '\n';
    cout << "---------" << '\n';
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << '\n'
         << '\n';
}
int moves()
{
    if (ptr % 3 == 0)
    {
        col = 2;
        row = (ptr / 3) - 1;
    }
    else
    {
        col = (ptr % 3) - 1;
        row = ptr / 3;
    }
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = marker;
        return 1;
    }
    else
    {
        return 0;
    }
}
int winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return player;
        }
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return player;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return player;
    }

    return 0;
}
void swap_plyrs()
{
    if (player == 1)
        player = 2;
    else
        player = 1;
    if (marker == 'x' || marker == 'X')
        marker = 'O';
    else
        marker = 'X';
}
void game()
{
    player = 1;
    cout << "player " << player << " choose your marker X or O : " << '\n';
    cin >> marker;
    board_layout();
    for (int i = 0; i < 9; i++)
    {
        cout << "player " << player << " choose your slot : " << '\n';
        cin >> ptr;
        if (ptr < 1 || ptr > 9)
        {
            cout << "Invalid move Try Again!"<<'\n';
            i--;
            continue;
        }
        if (moves()!=1)
        {
            cout << "Invalid move Try Again!"<<'\n';
            i--;
            continue;
        }
        
        board_layout();
        won = winner();
        if (won == 1)
        {
            cout << "Player 1 Wins";
            break;
        }
        if (won == 2)
        {
            cout << "player 2 Wins";
            break;
        }
        swap_plyrs();
    }
    if (won == 0)
    {
        cout << "Tie";
    }
}
int main()
{
    game();
}