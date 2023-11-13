#include <iostream>
#include <vector>
#include <stdexcept>
#include "suma.h"
#include "resta.h"
#include "division.h"
#include "multiplicacion.h"
#include "Validaciones.h"


// Función para solicitar las filas y columnas de una matriz
void solicitarDimensiones(std::vector<std::vector<int>>& matriz, const std::string& nombre) {
    size_t filas, columnas;
    std::cout << "Ingrese el número de filas de la matriz " << nombre << ": ";
    std::cin >> filas;
    std::cout << "Ingrese el número de columnas de la matriz " << nombre << ": ";
    std::cin >> columnas;

    matriz.resize(filas, std::vector<int>(columnas, 0.0));

    std::cout << "Ingrese los elementos de la matriz " << nombre << ":\n";
    for (size_t i = 0; i < filas; ++i) {
        for (size_t j = 0; j < columnas; ++j) {
            std::cout << nombre << "[" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
        }
    }
}
void agregarNuevasMatrices() {
    solicitarDimensiones(matrizA, "A");
    solicitarDimensiones(matrizB, "B");
}
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
        std::cout << "5. Agregar nuevas matrices" << std::endl;
        std::cout << "6. Cerrar Programa. " << std::endl;

        opcion = pedirNumeroMM();//Aqui hace la llamada a la funcion para que pueda validar el numero
        //Aqui hacemos que un switch case para elegir la opcion y llame a su respectiva funcion
        do{
     
            switch(opcion){
            case 1:HistorialSuma.push_back(sumaMatrices(matrizA,matrizB));
            std::cout<<"Resultado de la matriz\n";
            imprimirMatriz(sumaMatrices(matrizA,matrizB));
            mostrarHistorialSuma();
            waitForEnter();
            MenuPrincipal();
            break;
            case 2:HistorialResta.push_back(restaMatrices(matrizA, matrizB));
            LimpiarPantalla();
            std::cout<<"Resultado de la matriz\n";
            imprimirMatriz(restaMatrices(matrizA,matrizB));
            mostrarHistorialResta();
            waitForEnter();
            MenuPrincipal();
            break;
            case 3:
            HistorialMulti.push_back(multiplicacionMatrices(matrizA, matrizB));
            LimpiarPantalla();
            std::cout<<"Resultado de la matriz\n";
            imprimirMatriz(multiplicacionMatrices(matrizA,matrizB));
            mostrarHistorialMultiplicacion();
            waitForEnter();
            MenuPrincipal();
            break;
            case 4:
            LimpiarPantalla();
            break;
            case 5:
            agregarNuevasMatrices();
            case 6:
            std::cout << "Saliendo del programa. ¡Hasta luego!" << std::endl;
            break;
            default: std:: cout <<"Elige una opcion del 1 al 6";break;

            }   
        } while (opcion!=5);

}
int main ()
{
    agregarNuevasMatrices();
    MenuPrincipal();

    return 0;
}