#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int BLOCK_SIZE = 32;
const int NUM_REPETITIONS = 5;

void Multiply(int n, const vector<vector<double>>& a, const vector<vector<double>>& b, vector<vector<double>>& c) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0.0;  // Resetear la matriz resultado
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    // ... (parte inicial del código sin cambios)

    auto startTotal = high_resolution_clock::now();  // Marcar el tiempo de inicio total

    for (int i = 0; i < NUM_REPETITIONS; ++i) {
        auto start = high_resolution_clock::now();  // Marca el tiempo de inicio
        Multiply(n, A, B, C);  // Llama a la función de multiplicación
        auto stop = high_resolution_clock::now();  // Marca el tiempo de finalización
        auto duration = duration_cast<microseconds>(stop - start);  // Calcula la duración en microsegundos
        cout << "Tiempo de la repetición " << (i + 1) << " = " << duration.count() << " microsegundos" << endl;
        elapsed += duration.count();
    }

    auto stopTotal = high_resolution_clock::now();  // Marcar el tiempo de finalización total
    auto durationTotal = duration_cast<microseconds>(stopTotal - startTotal);  // Calcular la duración total en microsegundos
    double averageTime = static_cast<double>(durationTotal.count()) / NUM_REPETITIONS;

    cout << "Tiempo total = " << elapsed << " microsegundos" << endl;
    cout << "Tiempo promedio por operación = " << averageTime << " microsegundos" << endl;

    return 0;
}
