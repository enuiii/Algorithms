#include <iostream>
#include <vector>

// Функция для вывода чисел, удовлетворяющих условию
void printNumbers(int x) {
	std::vector <int> numbers;

// Вложенные циклы для перебора всех возможных комбинаций значений K, L и M
	for (int k = 0; k <= log(x) / log(3); k++) {
		for (int l = 0; l <= log(x) / log(5); l++) {
			for (int m = 0; m <= log(x) / log(7); m++) {
				int number = pow(3, k) * pow(5, l) * pow(7, m); // Вычисление числа
				if (number <= x) {
					numbers.push_back(number); // Добавление числа в вектор, если оно меньше или равно x
				}
			}
		}
	}

	// Вывод найденных чисел
	for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int x;
	std::cout << "Enter a number: ";
	std::cin >> x;
	std::cout << "Numbers satisfying the condition: ";
	printNumbers(x);
	return 0;
}