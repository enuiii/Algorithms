#include <iostream>
#include <vector>

// Функция сортировки методом "Вставки"
void insertionSort(std::vector<int>& sequence) {
	int n = sequence.size();

	for (int i = 1; i < n; i++) {
		int key = sequence[i]; // Текущий элемент, который нужно вставить в отсортированную последовательность
		int j = i - 1;

		// Перемещение элементов, больших key, вперед
		while (j >= 0 && sequence[j] > key) {
			sequence[j + 1] = sequence[j];
			j--;
		}

		sequence[j + 1] = key; // Вставка текущего элемента в правильную позицию
	}
}

int main() {
	std::cout << "Enter a sequence of numbers (-1 to stop): ";

	std::vector <int> sequence; // Вектор для хранения последовательности чисел
	int num;

	while (std::cin >> num && num != -1) { // Ввод последовательности чисел (-1 для остановки)
		sequence.push_back(num); // Добавление числа в вектор
	}

	insertionSort(sequence); // Сортировка последовательности методом "Вставки"

	std::cout << "Sorted sequence: ";
	for (int i = 0; i < sequence.size(); i++) { // Вывод отсортированной последовательности
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}