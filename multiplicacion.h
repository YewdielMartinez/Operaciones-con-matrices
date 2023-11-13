#ifndef MULTIPLICACION_H
#define MULTIPLICACION_H
#include <iostream>
#include <vector>

std::vector<std::vector<double>> multiplicacionMatrices(const std::vector<std::vector<double>>& matrizA,const std::vector<std::vector<double>>& matrizB) {
    std::vector<std::vector<double>> resultado(matrizA.size(), std::vector<double>(matrizB[0].size(), 0.0));
    for (size_t i = 0; i < matrizA.size(); ++i) {
        for (size_t j = 0; j < matrizB[0].size(); ++j) {
            for (size_t k = 0; k < matrizA[0].size(); ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    return resultado;
}
#endif 