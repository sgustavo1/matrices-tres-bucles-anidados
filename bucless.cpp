#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <stdexcept>

using namespace std;
using namespace std::chrono;

// Función para multiplicar dos matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& matrixA, const vector<vector<int>>& matrixB) {
    int size = matrixA.size();
    vector<vector<int>> result(size, vector<int>(size, 0)); // Inicializar la matriz de resultados con ceros

    // Realizar la multiplicación de matrices utilizando tres bucles anidados
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j]; // Realizar la suma acumulativa de los productos
            }
        }
    }

    return result; // Devolver la matriz resultante
}

int main() {
    int size;

    // Solicitar al usuario ingresar el tamaño de la matriz cuadrada
    cout << "Ingrese el tamaño de la matriz cuadrada (por ejemplo, 2 para 2x2, 3 para 3x3): ";
    cin >> size;

    if (size <= 0) {
        cerr << "El tamaño de la matriz debe ser un número positivo." << endl; // Mostrar un error si el tamaño es no positivo
        return 1; // Salir del programa con un código de error
    }

    int numRepetitions = 5; // Número de repeticiones
    double totalElapsedTime = 0.0; // Inicializar el tiempo total de ejecución

    // Realizar la multiplicación de matrices y medir el tiempo en cada repetición
    for (int repetition = 1; repetition <= numRepetitions; ++repetition) {
        // Reservar memoria para las matrices
        vector<vector<int>> matrixA(size, vector<int>(size));
        vector<vector<int>> matrixB(size, vector<int>(size));

        // Llenar las matrices con valores aleatorios usando un generador más eficiente
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(1, 100); // Generar valores aleatorios entre 1 y 100

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrixA[i][j] = dis(gen); // Llenar la matriz A con valores aleatorios
                matrixB[i][j] = dis(gen); // Llenar la matriz B con valores aleatorios
            }
        }

        // Medir el tiempo de ejecución antes y después de la multiplicación de matrices
        high_resolution_clock::time_point startTime = high_resolution_clock::now();

        // Realizar la multiplicación de matrices
        vector<vector<int>> result = multiplyMatrices(matrixA, matrixB);

        high_resolution_clock::time_point endTime = high_resolution_clock::now();
        duration<double> elapsedTime = duration_cast<duration<double>>(endTime - startTime);

        // Mostrar el tiempo de ejecución de cada repetición
        cout << "Repetición " << repetition << ": " << elapsedTime.count() << " segundos" << endl;

        totalElapsedTime += elapsedTime.count();
    }

    // Mostrar el tiempo total de ejecución de todas las repeticiones
    cout << "Tiempo total de ejecución de las " << numRepetitions << " repeticiones: " << totalElapsedTime << " segundos" << endl;

    return 0; // Salir del programa con un código de éxito
}
