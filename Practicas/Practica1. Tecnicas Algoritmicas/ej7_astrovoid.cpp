#include <iostream>
#include <vector>

using namespace std;

int inf = 0;
vector<int> P;
vector<vector<int>> mem;

int astrovoidTopDown(int j, int c){
    if(j == 0 && c == 1) return -P[j];
    if(j == 0 && c == 0) {
        mem[j][c] = 0;
        return 0;
    }
    if(j + 1 < c || c < 0) return -inf;

    if(mem[j][c] != -1) return mem[j][c];

    int compro = astrovoidTopDown(j-1, c - 1) - P[j];
    int vendo = astrovoidTopDown(j-1, c + 1) + P[j];
    int res = max(compro,vendo);
    int nada = astrovoidTopDown(j-1, c + 1);

    return mem[j][c] = max(res,nada);
}

int main() {
    P.push_back(3);
    P.push_back(2);
    P.push_back(5);
    P.push_back(6);

    int n = P.size();

    for (int i = 0; i < n; ++i) inf += P[i];

    mem.resize(n+1,vector<int>(n+1,-1));

    int res = astrovoidTopDown(n - 1,0);

    cout << res;
    return 0;
}
