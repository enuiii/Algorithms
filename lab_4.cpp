#include <iostream>
#include <vector>

// Функция сортировки методом "Пузырёк"
void bubbleSort(std::vector<int>& sequence) {
	int n = sequence.size(); // Размер последовательности чисел

	for (int i = 0; i < n - 1; i++) { // Внешний цикл для прохода по элементам
		for (int j = 0; j < n - 1 - i; j++) { // Внутренний цикл для сравнения и обмена элементов
			if (sequence[j] > sequence[j + 1]) { // Если текущий элемент больше следующего
				std::swap(sequence[j], sequence[j + 1]); // Обмен элементов
			}
		}
	}
}

int main() {
	std::cout << "Enter a sequence of numbers (-1 to stop): ";

	std::vector <int> sequence; // Вектор для хранения последовательности чисел
	int num;

	while (std::cin >> num && num != -1) { // Ввод последовательности чисел (-1 для остановки)
		sequence.push_back(num); // Добавление числа в вектор
	}

	bubbleSort(sequence); // Сортировка последовательности методом "Пузырёк"

	std::cout << "Sorted sequence: ";
	for (int i = 0; i < sequence.size(); i++) { // Вывод отсортированной последовательности
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}