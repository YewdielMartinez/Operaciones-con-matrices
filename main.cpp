#include <iostream>
#include <vector>
#include <stdexcept>
#include "suma.h"
#include "resta.h"
#include "division.h"
#include "multiplicacion.h"
#include "Validaciones.h"


void MenuPrincipal(){
        // Mostrar las matrices y el historial
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
        std::cout << "5. Cerrar Programa. " << std::endl;

        opcion = pedirNumeroMM();//Aqui hace la llamada a la funcion para que pueda validar el numero
        //Aqui hacemos que un switch case para elegir la opcion y llame a su respectiva funcion
        do{
     
            switch(opcion){
            case 1:historial.push_back(sumaMatrices(matrizA,matrizB));
           
            break;
            case 2:
            historial.push_back(restaMatrices(matrizA, matrizB));
            LimpiarPantalla();
            break;
            case 3:
            historial.push_back(multiplicacionMatrices(matrizA, matrizB));
            LimpiarPantalla();
            break;
            case 4:
            LimpiarPantalla();
            break;
            case 5: std::cout << "Saliendo del programa. ¡Hasta luego!" << std::endl; 

            break;
        
            default: std:: cout <<"Elige una opcion del 1 al 5";break;

            }   
        } while (opcion!=5);

}
int main ()
{

    // Solicitar dimensiones de la matriz A
    size_t filasA, columnasA;
    std::cout << "Ingrese el número de filas de la matriz A: ";
    std::cin >> filasA;
    std::cout << "Ingrese el número de columnas de la matriz A: ";
    std::cin >> columnasA;

    // Solicitar dimensiones de la matriz B
    size_t filasB, columnasB;
    std::cout << "Ingrese el número de filas de la matriz B: ";
    std::cin >> filasB;
    std::cout << "Ingrese el número de columnas de la matriz B: ";
    std::cin >> columnasB;

    // Validar que las matrices sean conformables para las operaciones
    if (columnasA != filasB) {
        std::cerr << "Error: Las matrices no son conformables para la multiplicación." << std::endl;
        return 1;
    }

    // Inicializar la matriz A
    std::cout << "Ingrese los elementos de la matriz A:" << std::endl;
    matrizA.resize(filasA, std::vector<double>(columnasA, 0.0));
    for (size_t i = 0; i < filasA; ++i) {
        for (size_t j = 0; j < columnasA; ++j) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> matrizA[i][j];
        }
    }

    // Inicializar la matriz B
    std::cout << "Ingrese los elementos de la matriz B:" << std::endl;
    matrizB.resize(filasB, std::vector<double>(columnasB, 0.0));
    for (size_t i = 0; i < filasB; ++i) {
        for (size_t j = 0; j < columnasB; ++j) {
            std::cout << "B[" << i << "][" << j << "]: ";
            std::cin >> matrizB[i][j];
        }
    }

    MenuPrincipal();
    std::cout << "Historial de operaciones:\n";
    for (size_t i = 0; i < historial.size(); ++i) {
        std::cout << "Operación " << i + 1 << ":\n";
        imprimirMatriz(historial[i]);
        std::cout << std::endl;
    }

    return 0;
}