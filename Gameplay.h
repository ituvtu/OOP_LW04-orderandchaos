#pragma once
// Перечислення, що представляє можливі результати гри
enum class GameResult
{
    OrderWin,   // Перемога гравця 1 (порядок)
    ChaosWin,   // Перемога гравця 2 (хаос)
    Continue    // Гра продовжується, бо не існує нічиї 
};
// Клас Gameplay, який відповідає за ігрову логіку
class Gameplay
{
public:
    Gameplay() {
        // Ініціалізація сітки значенням 0
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {this->grid[i][j] = 0;}
        }
    }

    // Оголошення методу Winner для визначення переможця
    void Winner(int rowIndex, int colIndex);

    // Оголошення методу CheckWin для перевірки умови перемоги
    GameResult CheckWin(int rowIndex, int colIndex);

    // Оголошення методу ResetGrid для скидання сітки
    void ResetGrid();

    // Оголошення методу GetValue для отримання значення комірки сітки
    int GetValue(int rowIndex, int colIndex) {return grid[rowIndex < 6][colIndex < 6];};

    // Оголошення методу SetValue для встановлення значення комірки сітки
    void SetValue(int rowIndex, int colIndex, int a) {grid[rowIndex][colIndex] = a;};

    // Оголошення методу NewGame для початку нової гри
    void NewGame();

    // Оголошення методу IsEmpty для перевірки, чи є комірка порожньою
    bool IsEmpty(int rowIndex, int colIndex);

    // Отримання поточного ходу (true - гравець 1, false - гравець 2)
    bool GetTurn() { return isPlayer1Turn; };

    // Встановлення наступного ходу
    void SetTurn() { isPlayer1Turn = !isPlayer1Turn; };
private:
    bool isPlayer1Turn = true;   // Змінна, що відстежує поточний хід гравця
    int grid[6][6];              // Сітка для гри розміром 6x6
};