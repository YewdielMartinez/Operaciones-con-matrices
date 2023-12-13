#ifndef MULTIPLICACION_H
#define MULTIPLICACION_H

#include "Validaciones.h"
void MenuPrincipal();
// Variables para almacenar las matrices y el HistorialMulti
std::vector<std::vector<std::vector<double>>> HistorialMulti;
std::vector<std::vector<double>> multiplicacionMatrices(const std::vector<std::vector<double>>& matrizA, const std::vector<std::vector<double>>& matrizB) {
    if (matrizA[0].size() != matrizB.size()) {
        std::cout << "El número de columnas de la matriz A debe ser igual al número de filas de la matriz B para la multiplicación.\n";
        MenuPrincipal();
    }

    if (matrizA.empty() || matrizB.empty() || matrizA[0].empty() || matrizB[0].empty()) {
        std::cout << "Las matrices no pueden estar vacías para la multiplicación.\n";
        MenuPrincipal();
    }

    if (matrizA.size() == 0 || matrizA[0].size() == 0 || matrizB.size() == 0 || matrizB[0].size() == 0) {
        std::cout << "Las matrices deben tener al menos una fila y una columna para la multiplicación.\n";
        MenuPrincipal();
    }
    int filasA = matrizA.size();
    int columnasA = matrizA[0].size();
    int filasB = matrizB.size();
    int columnasB = matrizB[0].size();

    // Inicializa la matriz resultante con las mismas filas de la matrizA y las mismas columnas de la matrizB
    std::vector<std::vector<double>> resultado(filasA, std::vector<double>(columnasB, 0));

    HistorialMulti.clear();  // Limpiar HistorialMulti

    // Realiza la multiplicación de las matrices
    for (int i = 0; i < filasA; ++i) {
        std::vector<std::vector<double>> paso;  // HistorialMulti de este paso
        for (int j = 0; j < columnasB; ++j) {
            for (int k = 0; k < columnasA; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
                paso.push_back({matrizA[i][k], matrizB[k][j], resultado[i][j]});
            }
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