#include <iostream>
using namespace std;
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'X';
string p1 = "";
string p2 = "";
bool tie = false;

void functionOne()
{
    // empty spaces
    cout << endl;

    cout << "  |     |  " << endl;
    cout << " " << space[0][0] << "| " << space[0][1] << "   | " << space[0][2] << endl;
    cout << "__|_____|__" << endl;
    cout << "  |     |  " << endl;
    cout << " " << space[1][0] << "| " << space[1][1] << "   | " << space[1][2] << endl;
    cout << "__|_____|__" << endl;
    cout << "  |     |  " << endl;
    cout << " " << space[2][0] << "| " << space[2][1] << "   | " << space[2][2] << endl;
    cout << "  |     |  " << endl;
}

void functionTwo()
{
    int digit;
    bool validInput = false;

    while (!validInput)
    {
        if (tie)
        {
            return;
        }
        if (token == 'X')
        {
            cout << p1 << " Please Enter: ";
        }
        else
        {
            cout << p2 << " Please Enter: ";
        }
        cin >> digit;

        if (digit < 1 || digit > 9)
        {
            cout << "Invalid input! Please enter a number between 1 and 9." << endl;
            validInput = false;
            continue;
        }

        // Map digit to row and column
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        // Check if the space is empty
        if (space[row][column] != 'X' && space[row][column] != 'O')
        {
            validInput = true;
        }
        else
        {

            cout << "The cell is already occupied! Try again." << endl;
            validInput = false;
        }
    }

    // Update the board
    space[row][column] = token;

    // Switch token
    token = (token == 'X') ? 'O' : 'X';

    functionOne();
}
bool functionThree()
{
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++)
    {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
        {
            return true;
        }
    }

    // Check diagonals for a win
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
    {
        return true;
    }

    // Check for a tie
    tie = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != 'O')
            {
                tie = false; // There are still empty spaces
                break;
            }
        }
        if (!tie)
        {
            break; // Exit early if any empty space is found
        }
    }

    return tie; // If tie remains true, it means the board is full
}
int main()
{
    cout << "Enter the name of first player:" << endl;
    getline(cin, p1);
    cout << "Enter the name of second player:" << endl;
    getline(cin, p2);
    cout << p1 << " is player1 so he/she will play first!" << endl;
    cout << p2 << " is player2 so he/she will play second!" << endl;

    functionOne(); // Display the initial board

    while (true)
    {
        functionTwo(); // Take input and update the board

        if (functionThree()) // Check if there's a win or a tie
        {
            break; // Exit the loop if the game is over
        }
    }

    if (tie)
    {
        cout << "It's a draw!" << endl;
    }
    else
    {
        if (token == 'O') // Previous player made the winning move
        {
            cout << p1 << " Wins!!" << endl;
        }
        else
        {
            cout << p2 << " Wins!!" << endl;
        }
    }

    return 0;
}
