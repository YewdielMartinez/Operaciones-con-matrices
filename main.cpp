#include <iostream>
#include <vector>
#include <fstream>
#include <Eigen/Dense>
#include "suma.h"
#include "resta.h"
#include "division.h"
#include "multiplicacion.h"
#include "Validaciones.h"


void solicitarDimensiones(std::vector<std::vector<double>>& matriz, const std::string& nombre) {
    matriz.clear();
    size_t filas, columnas;
    // Validar la entrada para el número de filas
    while (true) {
        std::cout << "Ingrese el número de filas de la matriz " << nombre << ": ";
        if (std::cin >> filas && filas > 0) {
            // La entrada es un número válido y mayor que cero, salir del bucle
            break;
        } else {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada incorrecta
            std::cout << "Error. Ingrese un número de filas válido mayor que cero.\n";
        }
    }

    // Validar la entrada para el número de columnas
    while (true) {
        std::cout << "Ingrese el número de columnas de la matriz " << nombre << ": ";
        if (std::cin >> columnas && columnas > 0) {
            // La entrada es un número válido y mayor que cero, salir del bucle
            break;
        } else {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada incorrecta
            std::cout << "Error. Ingrese un número de columnas válido mayor que cero.\n";
        }
    }
    matriz.resize(filas, std::vector<double>(columnas, 0.0));

    std::cout << "Ingrese los elementos de la matriz " << nombre << ":\n";
    for (size_t i = 0; i < filas; ++i) {
        for (size_t j = 0; j < columnas; ++j) {
            while (true) {
                std::cout << nombre << "[" << i << "][" << j << "]: ";
                if (std::cin >> matriz[i][j]) {
                    // La entrada es un número válido, salir del bucle
                    break;
                } else {
                    std::cin.clear(); // Limpiar el estado de error
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada incorrecta
                    std::cout << "Error. Ingrese un número válido.\n";
                }
            }
        }
    }
}

void guardarEnArchivo(const std::string& operacion,
                      const std::vector<std::vector<double>>& matrizA,
                      const std::vector<std::vector<double>>& matrizB,
                      const std::vector<std::vector<double>>& resultado) {
    std::ofstream archivo("historial.txt",std::ios::app);

    if (archivo.is_open()) {
        // Guardar información en el archivo
        archivo << "Operacion: " << operacion << "\n\n";
        archivo << "Matriz A:\n";
        for (const auto& fila : matrizA) {
            for (double elemento : fila) {
                archivo << elemento << " ";
            }
            archivo << "\n";
        }
        archivo << "\nMatriz B:\n";
        for (const auto& fila : matrizB) {
            for (double elemento : fila) {
                archivo << elemento << " ";
            }
            archivo << "\n";
        }
        archivo << "\nResultado:\n";
        for (const auto& fila : resultado) {
            for (double elemento : fila) {
                archivo << elemento << " ";
            }
            archivo << "\n";
        }

        archivo.close();
        std::cout << "Guardado exitoso en el archivo: historial.txt\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para escritura.\n";
    }
}

void leerMatrizDesdeArchivo(std::ifstream& archivo, std::vector<std::vector<double>>& matriz) {
    std::string linea;
    matriz.clear();
    while (std::getline(archivo, linea) && !linea.empty()) {
        std::istringstream iss(linea);
        double valor;
        std::vector<double> fila;
        while (iss >> valor) {
            fila.push_back(valor);
        }
        matriz.push_back(fila);
    }
}

void cargarDesdeArchivo(std::string& operacion,
                        std::vector<std::vector<double>>& matrizA,
                        std::vector<std::vector<double>>& matrizB,
                        std::vector<std::vector<double>>& resultado) {
    std::ifstream archivo("historial.txt");

    if (archivo.is_open()) {
        // Leer información desde el archivo
        std::string linea;
        while (std::getline(archivo, linea)) {
            if (linea.find("Operacion: ") != std::string::npos) {
                operacion = linea.substr(11);
            } else if (linea == "Matriz A:") {
                leerMatrizDesdeArchivo(archivo, matrizA);
            } else if (linea == "Matriz B:") {
                leerMatrizDesdeArchivo(archivo, matrizB);
            } else if (linea == "Resultado:") {
                leerMatrizDesdeArchivo(archivo, resultado);
            }
        }

        archivo.close();
        std::cout << "Carga exitosa desde el archivo: historial.txt\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para lectura.\n";
    }
}
void mostrarHistorialCompleto() {
    std::ifstream archivo("historial.txt");

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::cout << linea << "\n";
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para lectura.\n";
    }
}
void limpiarHistorial() {
    std::ofstream archivo("historial.txt", std::ios::trunc); // Abrir el archivo en modo truncar para eliminar el contenido
    archivo.close();
    std::cout << "Historial limpiado exitosamente.\n";
}
void agregarNuevasMatrices() {
    solicitarDimensiones(matrizA, "A");
    solicitarDimensiones(matrizB, "B");
    MenuPrincipal();
}
void MenuPrincipal(){
        // Mostrar las matrices y el historial
        std::string operacion;
        std::cout << "Matriz A:\n";
        imprimirMatriz(matrizA);
        std::cout << "\nMatriz B:\n";
        imprimirMatriz(matrizB);
        int opcion {0};//Declaramos una variable local para el MenuPrincipalPacientes
        std::cout << "=== Hola bienvenido a la calculadora de matrices ===" << std::endl;
        std::cout << "1. Suma de matrices" << std::endl;
        std::cout << "2. Resta de matrices" << std::endl;
        std::cout << "3. Multiplicacion de matrices" << std::endl;
        std::cout << "4. Division de matrices" << std::endl;
        std::cout << "5. Agregar nuevas matrices" << std::endl;
        std::cout << "6.Mostrar el historial completo  " << std::endl;
        std::cout << "7. Limpiar Historial. " << std::endl;
        std::cout << "8. Cerrar Programa. " << std::endl;

        opcion = pedirNumeroMC();//Aqui hace la llamada a la funcion para que pueda validar el numero
        //Aqui hacemos que un switch case para elegir la opcion y llame a su respectiva funcion
        do{
     
            switch(opcion){
            case 1: 
            {       
                std::vector<std::vector<double>> resultado = sumaMatrices(matrizA, matrizB);
                
                HistorialSuma.push_back(resultado);

                // Mostrar resultado
                std::cout << "Resultado de la suma:\n";
                imprimirMatriz(resultado);
                mostrarHistorialSuma();
                waitForEnter();

                // Guardar en archivo
                guardarEnArchivo("Suma", matrizA, matrizB, resultado);
                        // Cargar desde archivo (ejemplo)
                std::vector<std::vector<double>> matrizACargada, matrizBCargada, resultadoCargado;
                cargarDesdeArchivo( operacion, matrizACargada, matrizBCargada, resultadoCargado);
       
                MenuPrincipal();
                break;
            }
            case 2:
            {       
                std::vector<std::vector<double>> resultado = restaMatrices(matrizA, matrizB);
                HistorialResta.push_back(resultado);

                // Mostrar resultado
                std::cout << "Resultado de la resta:\n";
                imprimirMatriz(resultado);
                mostrarHistorialResta();
                waitForEnter();

                // Guardar en archivo
                guardarEnArchivo("Resta", matrizA, matrizB, resultado);
                        // Cargar desde archivo (ejemplo)
                std::vector<std::vector<double>> matrizACargada, matrizBCargada, resultadoCargado;
                cargarDesdeArchivo( operacion, matrizACargada, matrizBCargada, resultadoCargado);
       
                MenuPrincipal();
                break;
            }
            case 3:
            {       
                std::vector<std::vector<double>> resultado = multiplicacionMatrices(matrizA, matrizB);
                HistorialMulti.push_back(resultado);

                // Mostrar resultado
                std::cout << "Resultado de la multiplicacion:\n";
                imprimirMatriz(resultado);
                mostrarHistorialMultiplicacion();
                waitForEnter();

                // Guardar en archivo
                guardarEnArchivo("Multiplicacion", matrizA, matrizB, resultado);
                        // Cargar desde archivo (ejemplo)
                std::vector<std::vector<double>> matrizACargada, matrizBCargada, resultadoCargado;
                cargarDesdeArchivo( operacion, matrizACargada, matrizBCargada, resultadoCargado);
       
                MenuPrincipal();
                break;
            }
            case 4:
            {       
                std::vector<std::vector<double>> resultado = divisionMatrices(matrizA, matrizB);
                HistorialDivision.push_back(resultado);

                // Mostrar resultado
                std::cout << "Resultado de la Division:\n";
                imprimirMatriz(resultado);
                mostrarHistorialDivision();
                waitForEnter();

                // Guardar en archivo
                guardarEnArchivo("Division", matrizA, matrizB, resultado);
                        // Cargar desde archivo (ejemplo)
                std::vector<std::vector<double>> matrizACargada, matrizBCargada, resultadoCargado;
                cargarDesdeArchivo( operacion, matrizACargada, matrizBCargada, resultadoCargado);
       
                MenuPrincipal();
                break;
            }
            case 5:
                agregarNuevasMatrices();
            break;
            case 6:
                mostrarHistorialCompleto();
                waitForEnter();
                MenuPrincipal();
                break;
            case 7: 
                limpiarHistorial();
                waitForEnter();
                MenuPrincipal();
                break;
            case 8:
            std::cout << "Saliendo del programa. ¡Hasta luego!" << std::endl;
            cerrarPrograma();
            break;
            default: std:: cout <<"Elige una opcion del 1 al 8";break;

            }   
        } while (opcion!=8);

}
int main ()
{
    agregarNuevasMatrices();
    MenuPrincipal();

    return 0;
}