/*
 * Uso de backtracking
 * Objetivo: Dada una matriz M de nxn simetrica, y un k natural < n, determinar un subconjunto de tamaño
 * k de {1...n} tal que maximice la suma de las posiciones con esos indices.

 * 3.a
 * Solución candidata: Un subconjunto de tamaño k con indices entre 1 y n
 * Solución válida: Los elementos del subconjunto son indices que maximizan la suma de los elementos de M.
 * Solución parcial y extensión: Una solución parcial es una solución que todavía se le puede agregar elementos si es de
 * tamaño menor a K y se extiende si y solo sí me lleva a una solución válida y óptima. Sino, vuelvo hacia atrás.
*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> solucion_optima;
int maxSuma = -1; // Puede q todos los elementos sean 0 y esa sería la maxSuma

void indicesMaximaSuma(vector<vector<int>> &M, int k, int suma, vector<int> solucion_parcial, int i){
    // Chequeo si ya tengo una solución completa
    if(k == 0) {
        // Chequeo si es válida
        if(suma > maxSuma){
            maxSuma = suma;
            solucion_optima = solucion_parcial;
        }
        return;
    }

    int n = M.size(), d = 0;
    solucion_parcial.push_back(i);
    // Obtengo cual es la suma entre i y todas las combinaciones con los indices que ya tengo
    for (int j = 0; j < n; ++j) {
        d += M[i][solucion_parcial[j]] + M[solucion_parcial[j]][i];
    }
    // Incluyo al elemento actual a la solución
    indicesMaximaSuma(M, k - 1, suma + d, solucion_parcial, i + 1);
    // No lo incluyo
    solucion_parcial.pop_back();
    indicesMaximaSuma(M, k, suma, solucion_parcial, i + 1);
}



