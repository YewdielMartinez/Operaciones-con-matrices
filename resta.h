#ifndef RESTA_H
#define RESTA_H
#include <iostream>
#include <vector>
std::vector<std::vector<std::vector<int>>> HistorialResta;
std::vector<std::vector<int>> restaMatrices(const std::vector<std::vector<int>>& matrizA, const std::vector<std::vector<int>>& matrizB) {
    if (matrizA.size() != matrizB.size() || matrizA[0].size() != matrizB[0].size()) {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la suma.");
    }
    int filas = matrizA.size();
    int columnas = matrizA[0].size();
    // Inicializa la matriz resultante con las mismas dimensiones que las matrices de entrada
    std::vector<std::vector<int>> resultado(filas, std::vector<int>(columnas, 0));
    HistorialResta.clear();  // Limpiar HistorialResta
    // Realiza la resta de las matrices

    for (size_t i = 0; i < filas; ++i) {
        std::vector<std::vector<int>> paso;  // HistorialResta de este paso
        for (size_t j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
            paso.push_back({matrizA[i][j], matrizB[i][j], resultado[i][j]});
        }
        HistorialResta.push_back(paso);  // Agregar el paso al HistorialResta
    }

    return resultado;
}
void mostrarHistorialResta() {
    for (size_t i = 0; i < HistorialResta.size(); ++i) {
        std::cout << "Paso " << i + 1 << ":\n";
        for (size_t j = 0; j < HistorialResta[i].size(); ++j) {
            std::cout << HistorialResta[i][j][0] << " - " << HistorialResta[i][j][1] << " = " << HistorialResta[i][j][2] << "\t";
        }
        std::cout << "\n\n";
    }
}
#endif 