#include <iostream>
#include <vector>
#include <random>

int main() {
    int numRows = 3;
    int numCols = 3;

    unsigned int seed = 12345; // Use the same seed for all matrices

    // Create multiple matrices using the same seed
    std::vector<std::vector<double>> matrix1(numRows, std::vector<double>(numCols));
    std::vector<std::vector<double>> matrix2(numRows, std::vector<double>(numCols));

    // Set up the random number generator with the fixed seed
    std::mt19937 gen(seed);

    // Create two different distribution objects for different matrices
    std::uniform_real_distribution<double> dist1(0.0, 1.0);
    std::uniform_real_distribution<double> dist2(0.0, 1.0);

    // Populate matrix1 with random numbers
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrix1[i][j] = dist1(gen); // Generate a random number using dist1
        }
    }

    // Populate matrix2 with random numbers (using dist2)
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrix2[i][j] = dist2(gen); // Generate a random number using dist2
        }
    }

    // Print matrix1
    std::cout << "Matrix 1:" << std::endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Print matrix2
    std::cout << "Matrix 2:" << std::endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << matrix2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

