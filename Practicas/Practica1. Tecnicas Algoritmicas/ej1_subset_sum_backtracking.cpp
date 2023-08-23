//Implementación de backtracking.
// Obtener los subconjuntos de C tal que sus elementos sumen k.

#include <cstdio>
#include <vector>
using namespace std;

bool subset_sum(vector<int> &C, int i, int j, int suma_restante, vector<int> &solucion){
    // Podas
    if (j < 0) return false; // No podemos sumar naturales para obtener un negativo;
    if (j > suma_restante) return false;

    suma_restante -= C[i];

    if (i == 0) return j == 0; // Chequea si llegue a una solución válida o no, no se pasa de k.
    else {
        // Agrego el elemento actual;
        if(subset_sum(C, i - 1, j, suma_restante,solucion)) return true;
        else {
            // No considero el elemento actual en la solución;
            solucion.push_back(C[i]);
            subset_sum(C, i - 1, j - C[i], suma_restante,solucion);
            return true;
        }
    }
}

int main() {
    // Caso de test-
    // [0,1,2,3,4,5] k = 8 soluciones = {[0,1,3,4], [0,3,5], [4,3,1],..}
    vector<int> C(6);
    int n = C.size(), k = 8, suma_restante = 0;
    for (int i = 0; i < n; ++i) {
        C[i] = i;
        suma_restante += i;
    }

    vector<int> solucion;
    subset_sum(C,n - 1, k, suma_restante,solucion);
    int m = solucion.size();
    printf("solucion: {");
    for (int i = 0; i < m; i++) {
        printf("%d", solucion[i]);
        if (i < m - 1) printf(", ");
    }
    printf("}\n");

    return 0;
}