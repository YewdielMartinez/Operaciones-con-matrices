#ifndef DIVISION_H
#define DIVISION_H

#include "Validaciones.h"
#include <Eigen/Dense>

void MenuPrincipal();

std::vector<std::vector<std::vector<double>>> HistorialDivision;

std::vector<std::vector<double>> divisionMatrices(const std::vector<std::vector<double>>& matrizA, const std::vector<std::vector<double>>& matrizB) {
    if (matrizB.size() != matrizB[0].size()) {
        std::cout << "La matriz B debe ser cuadrada para calcular la inversa.\n";
        MenuPrincipal();
    }
    if (matrizA.empty() || matrizB.empty() || matrizA[0].empty() || matrizB[0].empty()) {
    std::cout << "Las matrices no pueden estar vacías para la división.\n";
    MenuPrincipal();
    }
    if (matrizA.size() == 0 || matrizA[0].size() == 0 || matrizB.size() == 0 || matrizB[0].size() == 0) {
    std::cout << "Las matrices deben tener al menos una fila y una columna para la división.\n";
    MenuPrincipal();
    }
    int filasA = matrizA.size();
    int columnasA = matrizA[0].size();
    int filasB = matrizB.size();
    int columnasB = matrizB[0].size();

    // Convertir las matrices de entrada a matrices Eigen
    Eigen::MatrixXd eigenMatrizA(filasA, columnasA);
    Eigen::MatrixXd eigenMatrizB(filasB, columnasB);

    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasA; ++j) {
            eigenMatrizA(i, j) = matrizA[i][j];
        }
    }

    for (int i = 0; i < filasB; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            eigenMatrizB(i, j) = matrizB[i][j];
        }
    }

    // Validar que la matrizB sea invertible utilizando FullPivLU
    Eigen::FullPivLU<Eigen::MatrixXd> luDecomposition(eigenMatrizB);
    if (!luDecomposition.isInvertible()) {
        std::cout<<"La matriz no es invertible\n";
        MenuPrincipal();
        
    }

    // Calcular la inversa de la matrizB
    Eigen::MatrixXd eigenMatrizBInversa = eigenMatrizB.inverse();

    // Realizar la multiplicación A * B^{-1}
    Eigen::MatrixXd eigenResultado = eigenMatrizA * eigenMatrizBInversa;

    // Convertir el resultado a una matriz de C++
    std::vector<std::vector<double>> resultado(filasA, std::vector<double>(columnasB, 0.0));
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            resultado[i][j] = eigenResultado(i, j);
        }
    }

    // Crear el historial paso a paso
    HistorialDivision.clear();
    for (int i = 0; i < filasA; ++i) {
        std::vector<std::vector<double>> paso;
        for (int j = 0; j < columnasB; ++j) {
            paso.push_back({matrizA[i][j], eigenMatrizBInversa(j, 0), resultado[i][j]});
        }
        HistorialDivision.push_back(paso);
    }

    return resultado;
}

void mostrarHistorialDivision() {
    for (size_t i = 0; i < HistorialDivision.size(); ++i) {
        std::cout << "Paso " << i + 1 << ":\n";
        for (size_t j = 0; j < HistorialDivision[i].size(); ++j) {
            std::cout << HistorialDivision[i][j][0] << " / " << HistorialDivision[i][j][1] << " = " << HistorialDivision[i][j][2] << "\t";
        }
        std::cout << "\n\n";
    }
}

#endif
