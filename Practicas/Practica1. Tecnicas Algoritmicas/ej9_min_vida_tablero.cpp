#include <iostream>
#include <vector>

using namespace std;

int m = 3, n = 3;
vector<vector<int>> tablero(m,vector<int>(n,0));
vector<vector<int>> mem(m,vector<int>(n,0));

int minVida(int i, int j){
    if(i == m || j == n) return 1;
    if(mem[i][j] != 0) return mem[i][j];

    int res;
    if(i == m - 1 && j < n-1) res = minVida(i,j+1) - tablero[i][j];
    if(j == n - 1 && i < m-1) res = minVida(i+1,j) - tablero[i][j];
    else res = min(minVida(i+1,j), minVida(i,j+1)) - tablero[i][j];

    if(res <= 0) res = 1;

    return mem[i][j] = res;
}


int main() {
    tablero[0][0] = -2;
    tablero[0][1] = -3;
    tablero[0][2] = 3;
    tablero[1][0] = -5;
    tablero[1][1] = -10;
    tablero[1][2] = 1;
    tablero[2][0] = 10;
    tablero[2][1] = 30;
    tablero[2][2] = -5;

    int res = minVida(0,0);
    cout << res;
    return 0;
}
