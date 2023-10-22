#include <iostream>
#include <fstream>
#include <iomanip>

const int size = 100;

void read(int matA[size][size], int matB[size][size], int& matrixSize, const std::string& file);
void print(const int matrix[size][size], int size);
void add(const int mat1[size][size], const int mat2[size][size], int result[size][size], int size);
void mult(const int mat1[size][size], const int mat2[size][size], int result[size][size], int size);
void sub(const int mat1[size][size], const int mat2[size][size], int result[size][size], int size);

std::string user_file() {
    return "matrix_input.txt";
}

void read(int matA[size][size], int matB[size][size], int& matrixSize, const std::string& file) {
    std::ifstream inputFile(file);
    if (inputFile.is_open()) {
        inputFile >> matrixSize;
        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                inputFile >> matA[i][j];
            }
        }
        for (int i = 0; i < matrixSize; ++i) {
            for (int j = 0; j < matrixSize; ++j) {
                inputFile >> matB[i][j];
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to access input file." << std::endl;
        exit(1);
    }
}

void print(const int matrix[size][size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::left << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void add(const int mat1[size][size], const int mat2[size][size], int result[size][size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void mult(const int mat1[size][size], const int mat2[size][size], int result[size][size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void sub(const int mat1[size][size], const int mat2[size][size], int result[size][size], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

int main() {
    int matA[size][size];
    int matB[size][size];
    int result[size][size];

    std::string file = user_file();

    int matrixSize;
    read(matA, matB, matrixSize, file); 

    std::cout << "\nWesley McDougal\nLab #6: Matrix manipulation" << std::endl;

    std::cout << "\nMatrix A:" << std::endl;
    print(matA, matrixSize);

    std::cout << "\nMatrix B:" << std::endl;
    print(matB, matrixSize);

    add(matA, matB, result, matrixSize);
    std::cout << "\nMatrix Sum (A + B):" << std::endl;
    print(result, matrixSize);

    mult(matA, matB, result, matrixSize);
    std::cout << "\nMatrix Product (A * B):" << std::endl;
    print(result, matrixSize);

    sub(matA, matB, result, matrixSize);
    std::cout << "\nMatrix Difference (A - B):" << std::endl;
    print(result, matrixSize);

    return 0;
}
