#include "Gameplay.h"
#include <iostream>
#include "ORDNCHS.h"

GameResult Gameplay::CheckWin(int rowIndex, int colIndex)
{
    int symbol = grid[rowIndex][colIndex];
    int count = 0;
    int row=0, col=0;

    // Проверка горизонтальных линий
    count = 0;
    for (col = 0; col < 6; col++)
    {
        if (grid[rowIndex][col] == symbol)
            count++;
        else
            count = 0;

        if (count >= 5)
            return GameResult::OrderWin;
    }

    // Проверка вертикальных линий
    count = 0;
    for (row = 0; row < 6; row++)
    {
        if (grid[row][colIndex] == symbol)
            count++;
        else
            count = 0;

        if (count >= 5)
            return GameResult::OrderWin;
    }

    // Проверка прямых диагоналей
    count = 0;
    row = rowIndex;
    col = colIndex;
    while (row > 0 && col > 0)
    {
        row--;
        col--;
    }

    while (row < 6 && col < 6)
    {
        if (grid[row][col] == symbol)
            count++;
        else
            count = 0;

        if (count >= 5)
            return GameResult::OrderWin;

        row++;
        col++;
    }

    // Проверка обратных диагоналей
    count = 0;
    row = rowIndex;
    col = colIndex;
    while (row > 0 && col < 5)
    {
        row--;
        col++;
    }

    while (row < 6 && col >=0)
    {
        
        if (grid[row][col] == symbol)
            count++;
        else
            count = 0;

        if (count >= 5)
            return GameResult::OrderWin;

        row++;
        col--;
    }

    for (row = 0; row < 6; row++)
    {
        for (col = 0; col < 6; col++)
        {
            if (IsEmpty(row, col))
                return GameResult::Continue; // Есть доступный ход, игра продолжается
        }
    }

    return GameResult::ChaosWin;
}
void Gameplay::Winner(int rowIndex, int colIndex) {
    GameResult win = CheckWin(rowIndex, colIndex);

    if (win == GameResult::OrderWin) {

        System::Windows::Forms::MessageBox::Show("Гравець 1 (Порядок) переміг!");
        NewGame();
    }
    else if (win == GameResult::ChaosWin) {

        System::Windows::Forms::MessageBox::Show("Гравець 2 (Хаос) переміг!");
        NewGame();
    }
}
void Gameplay::ResetGrid()
{
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            grid[row][col] = 0;
        }
    }
}
bool Gameplay::IsEmpty(int rowIndex, int colIndex)
{
    if (grid[rowIndex][colIndex] == 0) {
        return true;
    }
    else{ return false; }
   
}
void Gameplay::NewGame()
{
    isPlayer1Turn = true;
    ResetGrid();
    ORDNCHS^ form = dynamic_cast<ORDNCHS^>(System::Windows::Forms::Application::OpenForms[0]);
    Panel^ panel1 = form->GetPanel();
    panel1->Invalidate();
}
