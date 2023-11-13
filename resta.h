#ifndef RESTA_H
#define RESTA_H
#include <iostream>
#include <vector>

// Función para realizar la resta de dos matrices
std::vector<std::vector<double>> restaMatrices(const std::vector<std::vector<double>>& matrizA,const std::vector<std::vector<double>>& matrizB) {
    std::vector<std::vector<double>> resultado;
    for (size_t i = 0; i < matrizA.size(); ++i) {
        std::vector<double> fila;
        for (size_t j = 0; j < matrizA[i].size(); ++j) {
            fila.push_back(matrizA[i][j] - matrizB[i][j]);
        }
        resultado.push_back(fila);
    }
    return resultado;
}
#endif 