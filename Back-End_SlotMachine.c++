#include <iostream>
#include <random>
#include <math.h>

using namespace std;

// Grid dimensions for our slot machine board
const int TableWidth = 3;
const int TableHeight = 3;

// Generates a random number between 1 and 7 for the slots
int NumberGenerator()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 7);

    return distrib(gen);
}

// Fills the 2D array grid with random slot symbols
void FillTable(int _table[TableWidth][TableHeight])
{
    for (int row = 0; row < TableHeight; row++)
    {
        for (int column = 0; column < TableWidth; column++)
        {
            _table[row][column] = NumberGenerator();
        }
    }
}

// !!! Debug
// Renders the current state of the slot grid to the console
void PrintTable(int _table[TableWidth][TableHeight])
{
    for (int row = 0; row < TableHeight; row++)
    {
        for (int column = 0; column < TableWidth; column++)
        {
            cout << _table[row][column] << "  ";
        }
        cout << endl;
    }
}

// Evaluates rows, columns, and diagonals for matching lines.
// NOTE: Hardcoded for 3x3 grids right now.
void CheckWins(int _table[TableWidth][TableHeight])
{
    int Wins = 0;
    double WinningSum = 0;

    // 1. Check horizontal rows
    for (int row = 0; row < TableHeight; row++)
    {
        bool WinningTeam = true;
        for (int column = 0; column < TableWidth - 1; column++)
        {
            if (_table[row][column] != _table[row][column + 1])
            {
                WinningTeam = false;
                break; // mismatch found, drop out early
            }
        }

        if (WinningTeam)
        {
            WinningSum += pow((_table[row][0] + 1), 8);
            Wins++;
        }
    }

    // 2. Check vertical columns
    for (int column = 0; column < TableWidth; column++)
    {
        bool WinningTeam = true;
        for (int row = 0; row < TableHeight - 1; row++)
        {
            if (_table[row][column] != _table[row + 1][column])
            {
                WinningTeam = false;
                break;
            }
        }

        if (WinningTeam)
        {
            WinningSum += pow((_table[0][column] + 1), 8);
            Wins++;
        }
    }

    // 3. Check main diagonal (top-left to bottom-right)
    if (_table[0][0] == _table[1][1] && _table[1][1] == _table[2][2])
    {
        WinningSum += pow((_table[1][1] + 1), 8);
        Wins++;
    }

    // 4. Check anti-diagonal (top-right to bottom-left)
    if (_table[0][2] == _table[1][1] && _table[1][1] == _table[2][0])
    {
        WinningSum += pow((_table[1][1] + 1), 8);
        Wins++;
    }

    // !!! Debug
    cout << "Times win: " << Wins << endl;
    cout << "Winnings:  " << WinningSum << "$" << endl;
}

int main()
{
    int response;

    // Temp player loop
    do {
        int Table[TableWidth][TableHeight];

        FillTable(Table);
        PrintTable(Table);
        CheckWins(Table);

        cout << "Type 1 to spin again, otherwise the program stops: ";
        cin >> response;
        system("cls"); // clears console for the next spin

    } while (response == 1);

    return 0;
}
