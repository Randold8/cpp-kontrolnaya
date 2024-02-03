#include <iostream>
#include <cstdlib> // Для функций rand() и srand()
#include <ctime>   // Для функции time()

// Функция для создания двумерного динамического массива
int** createArray(int rows, int cols) {
    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }
    return array;
}

// Функция для заполнения массива случайными числами от 1 до 100
void fillArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 100 + 1;
        }
    }
}

// Функция для показа массива на экране
void printArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// Функция для подсчета суммы элементов на главной диагонали матрицы
int sumMainDiagonal(int** array, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < std::min(rows, cols); ++i) {
        sum += array[i][i];
    }
    return sum;
}

// Основная функция программы
int main() {
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

    int rows, cols;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;

    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;
    int** myArray = createArray(rows, cols);

    fillArray(myArray, rows, cols);

    std::cout << "Заполненный массив: " << std::endl;
    printArray(myArray, rows, cols);
    // Подсчет и вывод суммы элементов на главной диагонали
    int diagonalSum = sumMainDiagonal(myArray, rows, cols);
    std::cout << "Сумма элементов на главной диагонали: " << diagonalSum << std::endl;

    for (int i = 0; i < rows; ++i) {
        delete[] myArray[i]; // Удаление каждого подмассива столбцов
    }
    delete[] myArray; // Удаление основного массива указателей

    return 0;
}
