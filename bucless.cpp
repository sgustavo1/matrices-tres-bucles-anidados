#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

const int BLOCK_SIZE = 32;

// Función para realizar la multiplicación de matrices con bloques
void MultiplyByBlocks(int n, vector<vector<double>>& a, vector<vector<double>>& b, vector<vector<double>>& c) {
    for (int bi = 0; bi < n; bi += BLOCK_SIZE) {
        for (int bj = 0; bj < n; bj += BLOCK_SIZE) {
            for (int bk = 0; bk < n; bk += BLOCK_SIZE) {
                for (int i = 0; i < BLOCK_SIZE; i++) {
                    for (int j = 0; j < BLOCK_SIZE; j++) {
                        for (int k = 0; k < BLOCK_SIZE; k++) {
                            c[bi + i][bj + j] += a[bi + i][bk + k] * b[bk + k][bj + j];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Introduce la dimensión n de la matriz: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n, 1.0)); // Llenamos A con 1.0
    vector<vector<double>> B(n, vector<double>(n, 2.0)); // Llenamos B con 2.0
    vector<vector<double>> C(n, vector<double>(n, 0.0)); // Inicializamos C con 0.0

    double elapsed = 0.0;
    const int NUM_REPETITIONS = 5;

    // "Calentamiento" inicial para preparar la caché
    MultiplyByBlocks(n, A, B, C);

    cout << "Multiplicando matrices " << NUM_REPETITIONS << " veces..." << endl;

    for (int i = 0; i < NUM_REPETITIONS; ++i) {
        auto start = high_resolution_clock::now();
        MultiplyByBlocks(n, A, B, C);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        elapsed += duration.count() / 1e6;
        if (i == 0) {
            cout << "Primera repetición tomó " << elapsed << " segundos" << endl;
        }
    }

    double averageTime = elapsed / NUM_REPETITIONS;

    cout << "Tiempo promedio por operación (por bloques) = " << averageTime << " segundos" << endl;

    return 0;
}
