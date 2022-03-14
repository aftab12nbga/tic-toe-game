#include <iostream>
#include <stdlib.h>
using namespace std;
const int size = 3;
int play = 0;
char board[size][size];
int i = 0, j = 0;
int count = 0;
int row_no = -1, col_no = -1;
char symbol = ' ';
// _________________________for row checker__________________________
bool checkRows(char symbol)
{
    int count = 0;
    for (int row = 0; row < size; row = row + 1)
    {
        count = 0;
        for (int col = 0; col < size; col = col + 1)
        {
            if (board[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == size)
        {
            return 1;
        }
    }
    return 0;
}
// __________________for columb check_________________________
bool checkColumns(char symbol)
{
    int count = 0;
    for (int col = 0; col < size; col = col + 1)
    {
        count = 0;
        for (int row = 0; row < size; row = row + 1)
        {
            if (board[row][col] == symbol)
            {
                count = count + 1;
            }
        }
        if (count == size)
        {
            return 1;
        }
    }
    return 0;
}
// ________________________________for daignol check____________________
bool checkDiagonals(char symbol)
{
    int count = 0;
    for (int idx = 0; idx < size; idx = idx + 1)
    {
        if (board[idx][idx] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == size)
    {
        return 1;
    }
    count = 0;
    for (int row = 0, col = 2; row < size; row++, col--)
    {
        if (board[row][col] == symbol)
        {
            count = count + 1;
        }
    }
    if (count == size)
    {
        return 1;
    }
    return 0;
}
// _______________________winner_________________________
bool isWinner(char symbol)
{
    if (checkRows(symbol) || checkColumns(symbol) || checkDiagonals(symbol))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// _______________________for display board_____________________________
void initilizarray()
{
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            board[x][y] = ' ';
        }
    }
}
void displayboard()
{

    int row_num = 0;
    for (int row = 0; row < size; row++)
    {
        cout << "  ";
        // _________for upper part___________

        for (int firstline = 0; firstline < size; firstline++)
        {
            cout << "___"
                 << " ";
        }

        cout << "\n";

        cout << row_num;
        // ________________middlepart________________________
        for (int innerpart = 0; innerpart < size; innerpart++)
        {

            cout << "| " << board[row][innerpart] << " ";

            if (innerpart == size - 1)
            {
                cout << "|";
            }
        }

        cout << "\n";
        row_num++;
        // _______________last line_________________
        if (row == size - 1)
        {
            cout << "  ";
            for (int firstline = 0; firstline < size; firstline++)
            {
                cout << "___"
                     << " ";
            }
        }
    }
    cout << "\n";
}
// ___________take input____________________
void takeinput()
{
    if (play % 2 == 0)
    {
        symbol = 'x';
        cout << "enter row" << endl;
        cin >> row_no;

        cout << "enter columb" << endl;
        cin >> col_no;
        play++;
        if (board[row_no][col_no] == ' ')
        {
            board[row_no][col_no] = symbol;
        }
    }
    else
    {
        symbol = 'o';
        cout << "enter row" << endl;
        cin >> row_no;

        cout << "enter columb" << endl;
        cin >> col_no;
        play++;
        if (board[row_no][col_no] == ' ')
        {
            board[row_no][col_no] = 'o';
        }
    }
}
// ______________player____________
void player(string player1, string player2)
{
    if (count % 2 == 0)
    {
        cout << "player 1  " << player1 << endl;
    }
    else
    {
        cout << "player 2  " << player2 << endl;
    }
    count++;
}
// __________________tie match_________________
int endcondition = 0;
void tie()
{
    endcondition = 0;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (board[x][y] != ' ')
            {
                endcondition++;
            }
        }
    }
    if (endcondition == size * size)
    {
        cout << "match is tie" << endl;
    }
}
int main()
{
    initilizarray();

    string player1, player2;

    cout << "enter player 1 name" << endl;
    cin >> player1;
    cout << "enter player 2 name" << endl;
    cin >> player2;
    while (true)
    {

        displayboard();

        player(player1, player2);
        cout << endcondition << endl;
        tie();
        takeinput();

        checkRows(symbol);
        checkColumns(symbol);
        checkDiagonals(symbol);
        int result = isWinner(symbol);

        if (result == 1)
        {
            system("cls");
            displayboard();
            if (symbol == 'x')
            {
                cout << "the winner is " << player1;
                break;
            }
            else
            {
                cout << "the winner is " << player2;
                break;
            }
        }
        // cout << endcondition << endl;
        // tie();
        if (endcondition == size * size)
        {
            break;
        }
        // system("cls");
    }
}