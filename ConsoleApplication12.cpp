#include <iomanip>
#include <iostream>
#include <vector>

void task952() {
    std::cout << "Task: 952\n";
    const int rows = 3;
    const int cols = 4;
    int arr[rows][cols] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };

    std::cout << "Исходный массив:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int choice;
    std::cout << "Выберите действие:\n1. Замена строки\n2. Замена столбца\n";
    std::cin >> choice;

    if (choice != 1 && choice != 2) {
        std::cout << "Некорректный выбор действия. Попробуйте снова.\n";
        return;
    }

    int index, num;
    std::cout << "Введите индекс (0-" << (choice == 1 ? rows - 1 : cols - 1) << "): ";
    std::cin >> index;

    if ((choice == 1 && (index < 0 || index >= rows)) || (choice == 2 && (index < 0 || index >= cols))) {
        std::cout << "Некорректный индекс.\n";
        return;
    }

    std::cout << "Введите число для замены: ";
    std::cin >> num;

    if (choice == 1) {
        for (int j = 0; j < cols; ++j) {
            arr[index][j] = num;
        }
    }
    else if (choice == 2) {
        for (int i = 0; i < rows; ++i) {
            arr[i][index] = num;
        }
    }

    std::cout << "Массив после замены:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void task959() {
    std::cout << "Task: 959\n";
    const int classes = 11;
    const int streams = 4;
    int students[classes][streams];

    std::srand(std::time(0));

    std::cout << "Массив инициализирован случайными значениями:\n";
    for (int i = 0; i < classes; ++i) {
        for (int j = 0; j < streams; ++j) {
            students[i][j] = std::rand() % 31;
            std::cout << students[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int totalStudentsIn5th = 0;

    for (int j = 0; j < streams; ++j) {
        totalStudentsIn5th += students[4][j];
    }

    std::cout << "Общее количество учеников в 5-х классах: " << totalStudentsIn5th << std::endl;
}

void task978() {
    std::cout << "Task: 978\n";
    int n;
    std::cout << "Введите порядок блока n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Некорректный порядок блока. Он должен быть положительным.\n";
        return;
    }

    int size = 2 * n;
    double** matrix = new double* [size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new double[size];
    }

	std::srand(std::time(0));

    std::cout << "Матрица инициализирована случайными значениями:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = (std::rand() % 1000) / 10.0; 
            std::cout << std::fixed << std::setprecision(1) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::swap(matrix[i][j], matrix[i + n][j + n]);
            std::swap(matrix[i][j + n], matrix[i + n][j]);
        }
    }

    std::cout << "Новая матрица после перестановки блоков:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::fixed << std::setprecision(1) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void task1015() {
    std::cout << "Task: 1015\n";
    int n;
    std::cout << "Введите размер матрицы n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Некорректный размер матрицы. Он должен быть положительным.\n";
        return;
    }

    double** matrix = new double* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[n];
    }

    std::cout << "Введите элементы матрицы размером " << n << " x " << n << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            while (true) {
                std::cin >> matrix[i][j];
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Некорректный ввод. Введите число: ";
                }
                else {
                    break;
                }
            }
        }
    }

    bool isOrthonormal = true;

    for (int i = 0; i < n && isOrthonormal; ++i) {
        double rowLength = 0.0;

        for (int j = 0; j < n; ++j) {
            rowLength += matrix[i][j] * matrix[i][j];

            for (int k = 0; k < n; ++k) {
                if (i != k) {
                    double dotProduct = 0.0;
                    for (int l = 0; l < n; ++l) {
                        dotProduct += matrix[i][l] * matrix[k][l];
                    }
                    if (std::abs(dotProduct) > 1e-9) {
                        isOrthonormal = false;
                        break;
                    }
                }
            }

            if (!isOrthonormal) break;
        }

        if (std::abs(rowLength - 1.0) > 1e-9) {
            isOrthonormal = false;
        }
    }

    if (isOrthonormal) {
        std::cout << "Матрица является ортонормированной.\n";
    }
    else {
        std::cout << "Матрица не является ортонормированной.\n";
    }

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    //task952();
    //task959();
	//task978();
    //task1015();
    //Как самурай, я обрел настоящее умиротворение и гармонию, когда задания совпали.Мне не нужно больше их выполнять, и это наполнило меня радостью, как будто луна озарила мой путь.
}
