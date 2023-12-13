#ifndef RESTA_H
#define RESTA_H
#include <iostream>
#include <vector>
void MenuPrincipal();
std::vector<std::vector<std::vector<double>>> HistorialResta;
std::vector<std::vector<double>> restaMatrices(const std::vector<std::vector<double>>& matrizA, const std::vector<std::vector<double>>& matrizB) {
    if (matrizA.size() != matrizB.size() || matrizA[0].size() != matrizB[0].size()) {
        std::cout << "Las matrices deben tener las mismas dimensiones para la resta.\n";
        MenuPrincipal();
    }

    if (matrizA.empty() || matrizB.empty() || matrizA[0].empty() || matrizB[0].empty()) {
        std::cout << "Las matrices no pueden estar vacías para la resta.\n";
        MenuPrincipal();
    }

    if (matrizA.size() == 0 || matrizA[0].size() == 0 || matrizB.size() == 0 || matrizB[0].size() == 0) {
        std::cout << "Las matrices deben tener al menos una fila y una columna para la resta.\n";
        MenuPrincipal();
    }
    int filas = matrizA.size();
    int columnas = matrizA[0].size();
    // Inicializa la matriz resultante con las mismas dimensiones que las matrices de entrada
    std::vector<std::vector<double>> resultado(filas, std::vector<double>(columnas, 0));
    HistorialResta.clear();  // Limpiar HistorialResta
    // Realiza la resta de las matrices

    for (size_t i = 0; i < filas; ++i) {
        std::vector<std::vector<double>> paso;  // HistorialResta de este paso
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