// Ejercicio 2, backtracking.

// Cubo Mágico de orden n: es un cuadrado con los números {1,..., n^2}, tal que todas sus
// filas, columnas y las dos diagonales suman lo mismo (numero mágico).
// Objetivo: contar cuántos cuadrados mágicos de orden n existen.

#include <cstdio>
#include <vector>

using namespace std;

// cambiar a vector
bool cuantos_cubos_magicos(vector<int> &restantes, int contador, vector<vector<int>> &cuboMagico, int numMagico, int f, int c){
    int sizeCubo = cuboMagico.size();
    int n = restantes.size();
    
    if(n == 0) return false; // Ya no tengo numeros para agregar

    // Chequeo filas y columnas
    int sumaFila = 0, sumaCol = 0;
    for(int i = 0; i < c; i++) sumaFila += cuboMagico[f][i];
    for(int i = 0; i < f; i++) sumaCol += cuboMagico[i][c];

    //Chequeo diagonales
    int sumIzq = 0, sumDer = 0;
    for (int i = 0; i < f && i < c; i++) sumIzq += cuboMagico[i][i];
    for (int i = 0; i < f && i < c; i++) sumDer += cuboMagico[i][c-i];
    if (sumaFila > numMagico || sumaCol > numMagico || sumIzq != numMagico || sumDer > numMagico) return false;

    if (c == sizeCubo && f != sizeCubo) {
        if(sumaFila < numMagico) return false;

        return cuantos_cubos_magicos(restantes,contador,cuboMagico,numMagico,f+1,0);
    }

    if(f == sizeCubo) return true;
    for (int i = 1; i < n; ++i) {
        if(restantes[i-1] == 0 && sumaFila + i <= numMagico && sumaCol + i <= numMagico) {
            cuboMagico[f][c] = i;
            restantes[i-1] = 1;
            contador += cuantos_cubos_magicos(restantes, contador,cuboMagico,numMagico,f,c + 1);
            // Backtracking
            restantes[i-1] = 0;
        }
    }
    return contador;
}

int main(){
    int n = 3, contador = 0, sizeCubo = 3;
    vector<vector<int>> cuboMagico(sizeCubo);
    int numMagico = ((n * n * n) + n) / 2;
    vector<int> restantes(n*n,0);
    int res = cuantos_cubos_magicos(restantes, contador, cuboMagico, numMagico, 0, 0);
    printf("La cantidad de cubos mágicos es %d\n", res);

    return 0;
}
