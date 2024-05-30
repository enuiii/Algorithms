#include <iostream>
#include <vector>
#include <string>

// Функция для вычисления таблицы переходов
std::vector<int> computeTransitionTable(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> transition(m + 1, 0);
    // Инициализация таблицы переходов нулями
    transition[0] = -1;
    // Начальное значение для первого элемента таблицы
    int k = -1;
    for (int q = 1; q <= m; ++q) {
        while (k >= 0 && pattern[k] != pattern[q - 1]) {
            k = transition[k];
          // Обновление значения
        }
        k++;
        transition[q] = k;
      // Запись значения в таблицу
    }
    return transition;
}

// Функция для поиска подстроки в тексте
void searchPattern(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();
    std::vector<int> transition = computeTransitionTable(pattern);
  // Вычисление таблицы переходов
    int q = 0;
    for (int i = 0; i < n; ++i) {
        while (q >= 0 && pattern[q] != text[i]) {
            q = transition[q];
        }
      // Обновление значения
        q++;
        if (q == m) {
            std::cout << "Pattern found at index " << i - m + 1 << std::endl;
          // Вывод индекса найденного шаблона
            q = transition[q];
          // Возврат к начальному значению
        }
    }
}

int main() {
    std::string text = "ababcababcabcabc";
    std::string pattern = "abcabc";

    searchPattern(text, pattern);
    return 0;
}
