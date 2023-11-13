#ifndef SUMA_H
#define SUMA_H
#include <vector>
// Variables para almacenar las matrices y el historial
std::vector<std::vector<double>> matrizA, matrizB;
std::vector<std::vector<std::vector<double>>> historial;

std::vector<std::vector<double>> sumaMatrices(const std::vector<std::vector<double>>& matrizA, const std::vector<std::vector<double>>& matrizB) {
    if (matrizA.size() != matrizB.size() || matrizA[0].size() != matrizB[0].size()) {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la suma.");
    }
    int filas = matrizA.size();
    int columnas = matrizA[0].size();
    // Inicializa la matriz resultante con las mismas dimensiones que las matrices de entrada
    std::vector<std::vector<double>> resultado(filas, std::vector<double>(columnas, 0.0));

    // Realiza la suma de las matrices
    for (size_t i = 0; i < filas; ++i) {
        for (size_t j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    return resultado;
}

#endif