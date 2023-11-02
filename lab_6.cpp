#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
  
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        
        // Находим индекс наименьшего элемента в оставшейся части массива
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
  
        // Меняем местами текущий элемент с наименьшим элементом
        std::swap(arr[minIndex], arr[i]);
    }
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};
  
    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
  
    selectionSort(arr);
  
    std::cout << "\nОтсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
  
    return 0;
}
