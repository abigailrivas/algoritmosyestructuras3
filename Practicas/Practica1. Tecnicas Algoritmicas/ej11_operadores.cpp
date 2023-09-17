#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

vector<int> v;
vector<vector<int>> mem;

int operadores(int i, int w){
    if(i == -1 && w == 0) return 1;
    if(i == -1) return 0;

    int aux = (w > 0)? w : 0;
    if(mem[i][aux] == -1){
        mem[i][aux] = operadores(i-1,w-v[i]) || operadores(i-1,w/v[i]) ||operadores(i-1,pow(w,1.0 / v[i]));
    }
    return mem[i][aux];
}

int main() {
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);
    v.push_back(2);
    v.push_back(1);

    int n = v.size();
    int w = 400;

    mem.resize(n,vector<int>(w+1,-1));

    int res = operadores(n-1,w);
    cout << res;
    return 0;
}
