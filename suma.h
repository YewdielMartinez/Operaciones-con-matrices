#ifndef SUMA_H
#define SUMA_H
#include <vector>
void MenuPrincipal();
// Variables para almacenar las matrices y el Historial
std::vector<std::vector<int>> matrizA, matrizB;
std::vector<std::vector<std::vector<int>>> HistorialSuma;

std::vector<std::vector<int>> sumaMatrices(const std::vector<std::vector<int>>& matrizA, const std::vector<std::vector<int>>& matrizB) {
    if (matrizA.size() != matrizB.size() || matrizA[0].size() != matrizB[0].size()) {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la suma.");

    }
    int filas = matrizA.size();
    int columnas = matrizA[0].size();
    // Inicializa la matriz resultante con las mismas dimensiones que las matrices de entrada
    std::vector<std::vector<int>> resultado(filas, std::vector<int>(columnas, 0));
    HistorialSuma.clear();  // Limpiar Historial
    // Realiza la suma de las matrices

    for (size_t i = 0; i < filas; ++i) {
        std::vector<std::vector<int>> paso;  // Historial de este paso
        for (size_t j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
            paso.push_back({matrizA[i][j], matrizB[i][j], resultado[i][j]});
        }
        HistorialSuma.push_back(paso);  // Agregar el paso al Historial
    }

    return resultado;
}
void mostrarHistorialSuma() {
    for (size_t i = 0; i < HistorialSuma.size(); ++i) {
        std::cout << "Paso " << i + 1 << ":\n";
        for (size_t j = 0; j < HistorialSuma[i].size(); ++j) {
            std::cout << HistorialSuma[i][j][0] << " + " << HistorialSuma[i][j][1] << " = " << HistorialSuma[i][j][2] << "\t";
        }
        std::cout << "\n\n";
    }
}
#endif