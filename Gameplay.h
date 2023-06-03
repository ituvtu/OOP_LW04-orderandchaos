#pragma once
// ������������, �� ����������� ������ ���������� ���
enum class GameResult
{
    OrderWin,   // �������� ������ 1 (�������)
    ChaosWin,   // �������� ������ 2 (����)
    Continue    // ��� ������������, �� �� ���� ��� 
};
// ���� Gameplay, ���� ������� �� ������ �����
class Gameplay
{
public:
    Gameplay() {
        // ����������� ���� ��������� 0
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {this->grid[i][j] = 0;}
        }
    }

    // ���������� ������ Winner ��� ���������� ���������
    void Winner(int rowIndex, int colIndex);

    // ���������� ������ CheckWin ��� �������� ����� ��������
    GameResult CheckWin(int rowIndex, int colIndex);

    // ���������� ������ ResetGrid ��� �������� ����
    void ResetGrid();

    // ���������� ������ GetValue ��� ��������� �������� ������ ����
    int GetValue(int rowIndex, int colIndex) {return grid[rowIndex < 6][colIndex < 6];};

    // ���������� ������ SetValue ��� ������������ �������� ������ ����
    void SetValue(int rowIndex, int colIndex, int a) {grid[rowIndex][colIndex] = a;};

    // ���������� ������ NewGame ��� ������� ���� ���
    void NewGame();

    // ���������� ������ IsEmpty ��� ��������, �� � ������ ���������
    bool IsEmpty(int rowIndex, int colIndex);

    // ��������� ��������� ���� (true - ������� 1, false - ������� 2)
    bool GetTurn() { return isPlayer1Turn; };

    // ������������ ���������� ����
    void SetTurn() { isPlayer1Turn = !isPlayer1Turn; };
private:
    bool isPlayer1Turn = true;   // �����, �� ������� �������� ��� ������
    int grid[6][6];              // ѳ��� ��� ��� ������� 6x6
};