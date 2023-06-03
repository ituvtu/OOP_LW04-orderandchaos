#include "ORDNCHS.h"
#include "Gameplay.h"

using namespace System;
using namespace System::Windows::Forms;

Gameplay gameplay;

int main(cli::array<String^>^ args) {
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    ORDNCHS form;
    Application::Run(% form);
}

// Обробник події "Paint" для панелі гри
Void ORDNCHS::gamepanel_Paint(Object^ sender, PaintEventArgs^ e)
{
    int cellSize = 50; // Розмір клітинки
    int rowCount = 6; // Кількість рядків
    int colCount = 6; // Кількість стовпців
    Drawing::Graphics^ g = e->Graphics;
    // Відображення ігрового поля
    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < colCount; col++)
        {
            int x = col * cellSize;
            int y = row * cellSize;
            g->DrawRectangle(Drawing::Pens::Black, x, y, cellSize, cellSize);
        }
    }
}

// Обробник події "MouseClick" для панелі гри
void ORDNCHS::gamepanel_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    int cellSize = 50; // Розмір клітинки
    int rowIndex = e->Y / cellSize; // Визначення індексу рядка на основі координати Y
    int colIndex = e->X / cellSize; // Визначення індексу стовпця на основі координати X
    // Перевірка допустимості індексів
    if (rowIndex >= 0 && rowIndex < 6 && colIndex >= 0 && colIndex < 6)
    {
        System::Drawing::Graphics^ g = panel1->CreateGraphics();
        // Розрахунок координат для відображення символа
        int x = colIndex * cellSize;
        int y = rowIndex * cellSize;
        // Перевірка, чи клітинка не зайнята
        if (gameplay.IsEmpty(rowIndex, colIndex))
        {
            // Визначення кольору символу в залежності від поточної теми
            System::Drawing::Color symbolColor;
            if (currenttheme == Theme::Dark)
            {
                symbolColor = System::Drawing::Color::White;
            }
            else if (currenttheme == Theme::Light)
            {
                symbolColor = System::Drawing::Color::Black;
            }
            // Відображення хрестика або нулика в обраній клітинці
            if (e->Button == System::Windows::Forms::MouseButtons::Left)
            {
                // Відображення нулика
                g->DrawEllipse(gcnew System::Drawing::Pen(symbolColor), x, y, cellSize, cellSize);
                gameplay.SetValue(rowIndex, colIndex, 1); // Запис значення в масив
            }
            else if (e->Button == System::Windows::Forms::MouseButtons::Right)
            {
                // Відображення хрестика
                g->DrawLine(gcnew System::Drawing::Pen(symbolColor), x, y, x + cellSize, y + cellSize);
                g->DrawLine(gcnew System::Drawing::Pen(symbolColor), x, y + cellSize, x + cellSize, y);
                gameplay.SetValue(rowIndex, colIndex, 2); // Запис значення в масив
            }
            gameplay.Winner(rowIndex, colIndex);
            gameplay.SetTurn();
            // Оновлення надпису про поточного гравця
            PlayerTurn(gameplay);
            turnLabel->Update();
        }
    }
}

// Обробник події для перемикання теми
void ORDNCHS::SwitchTheme(Object^ sender, EventArgs^ e)
{
    // Відображення діалогового вікна з питанням
    System::Windows::Forms::DialogResult result = MessageBox::Show("Ви впевнені, що хочете змінити тему, бо для цього гра почнеться з початку?", "Зміна теми", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

    // Перевірка вибраної відповіді
    if (result == System::Windows::Forms::DialogResult::Yes)
    {
        Switch_theme();
        gameplay.NewGame();
    }
}

System::Void ORDNCHS::початиСпочаткуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    gameplay.NewGame();
    this->PlayerTurn(gameplay);
}

System::Void ORDNCHS::покинутиГруToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void ORDNCHS::ORDNCHS_Load(System::Object^ sender, System::EventArgs^ e)
{
    gameplay.NewGame();
}