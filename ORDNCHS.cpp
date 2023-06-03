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

// �������� ��䳿 "Paint" ��� ����� ���
Void ORDNCHS::gamepanel_Paint(Object^ sender, PaintEventArgs^ e)
{
    int cellSize = 50; // ����� �������
    int rowCount = 6; // ʳ������ �����
    int colCount = 6; // ʳ������ ��������
    Drawing::Graphics^ g = e->Graphics;
    // ³���������� �������� ����
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

// �������� ��䳿 "MouseClick" ��� ����� ���
void ORDNCHS::gamepanel_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    int cellSize = 50; // ����� �������
    int rowIndex = e->Y / cellSize; // ���������� ������� ����� �� ����� ���������� Y
    int colIndex = e->X / cellSize; // ���������� ������� ������� �� ����� ���������� X
    // �������� ����������� �������
    if (rowIndex >= 0 && rowIndex < 6 && colIndex >= 0 && colIndex < 6)
    {
        System::Drawing::Graphics^ g = panel1->CreateGraphics();
        // ���������� ��������� ��� ����������� �������
        int x = colIndex * cellSize;
        int y = rowIndex * cellSize;
        // ��������, �� ������� �� �������
        if (gameplay.IsEmpty(rowIndex, colIndex))
        {
            // ���������� ������� ������� � ��������� �� ������� ����
            System::Drawing::Color symbolColor;
            if (currenttheme == Theme::Dark)
            {
                symbolColor = System::Drawing::Color::White;
            }
            else if (currenttheme == Theme::Light)
            {
                symbolColor = System::Drawing::Color::Black;
            }
            // ³���������� �������� ��� ������ � ������ �������
            if (e->Button == System::Windows::Forms::MouseButtons::Left)
            {
                // ³���������� ������
                g->DrawEllipse(gcnew System::Drawing::Pen(symbolColor), x, y, cellSize, cellSize);
                gameplay.SetValue(rowIndex, colIndex, 1); // ����� �������� � �����
            }
            else if (e->Button == System::Windows::Forms::MouseButtons::Right)
            {
                // ³���������� ��������
                g->DrawLine(gcnew System::Drawing::Pen(symbolColor), x, y, x + cellSize, y + cellSize);
                g->DrawLine(gcnew System::Drawing::Pen(symbolColor), x, y + cellSize, x + cellSize, y);
                gameplay.SetValue(rowIndex, colIndex, 2); // ����� �������� � �����
            }
            gameplay.Winner(rowIndex, colIndex);
            gameplay.SetTurn();
            // ��������� ������� ��� ��������� ������
            PlayerTurn(gameplay);
            turnLabel->Update();
        }
    }
}

// �������� ��䳿 ��� ����������� ����
void ORDNCHS::SwitchTheme(Object^ sender, EventArgs^ e)
{
    // ³���������� ���������� ���� � ��������
    System::Windows::Forms::DialogResult result = MessageBox::Show("�� �������, �� ������ ������ ����, �� ��� ����� ��� ��������� � �������?", "���� ����", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

    // �������� ������� ������
    if (result == System::Windows::Forms::DialogResult::Yes)
    {
        Switch_theme();
        gameplay.NewGame();
    }
}

System::Void ORDNCHS::��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    gameplay.NewGame();
    this->PlayerTurn(gameplay);
}

System::Void ORDNCHS::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void ORDNCHS::ORDNCHS_Load(System::Object^ sender, System::EventArgs^ e)
{
    gameplay.NewGame();
}