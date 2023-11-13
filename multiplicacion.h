#ifndef MULTIPLICACION_H
#define MULTIPLICACION_H
#include <iostream>
#include <vector>
// Variables para almacenar las matrices y el HistorialMulti
std::vector<std::vector<std::vector<int>>> HistorialMulti;
std::vector<std::vector<int>> multiplicacionMatrices(const std::vector<std::vector<int>>& matrizA, const std::vector<std::vector<int>>& matrizB) {
    if (matrizA.size() != matrizB.size() || matrizA[0].size() != matrizB[0].size()) {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la suma.");
    }
    int filas = matrizA.size();
    int columnas = matrizA[0].size();
    // Inicializa la matriz resultante con las mismas dimensiones que las matrices de entrada
    std::vector<std::vector<int>> resultado(filas, std::vector<int>(columnas, 0));
    HistorialMulti.clear();  // Limpiar HistorialMulti
    // Realiza la multplicacion de las matrices

    for (size_t i = 0; i < filas; ++i) {
        std::vector<std::vector<int>> paso;  // HistorialMulti de este paso
        for (size_t j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] * matrizB[i][j];
            paso.push_back({matrizA[i][j], matrizB[i][j], resultado[i][j]});
        }
        HistorialMulti.push_back(paso);  // Agregar el paso al HistorialMulti
    }

    return resultado;
}
void mostrarHistorialMultiplicacion() {
    for (size_t i = 0; i < HistorialMulti.size(); ++i) {
        std::cout << "Paso " << i + 1 << ":\n";
        for (size_t j = 0; j < HistorialMulti[i].size(); ++j) {
            std::cout << HistorialMulti[i][j][0] << " * " << HistorialMulti[i][j][1] << " = " << HistorialMulti[i][j][2] << "\t";
        }
        std::cout << "\n\n";

    }
}
#endif 