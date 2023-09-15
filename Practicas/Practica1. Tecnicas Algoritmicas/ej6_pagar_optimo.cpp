#include <iostream>
#include <vector>

using namespace std;

int n = 3,c = 2;
vector<vector<pair<int,int>>> estados(n+1,vector<pair<int,int>>(c+1,{-1,-1}));

pair<int,int> pagarOptimoBacktracking(vector<int> &B, int i, int j){
    if(i < 0 && j > 0){
        return {100,100};
    } else if(j <= 0){
        return {0,0};
    }

    pair<int,int> res1 = pagarOptimoBacktracking(B,i-1,j);
    pair<int,int> res2 = pagarOptimoBacktracking(B,i-1,j-B[i]);
    res2.first += B[i];
    res2.second += 1;

    if(res1.first < res2.first || (res1.first == res2.first && res1.second < res2.second)) return res1;

    return res2;
}

pair<int,int> pagarOptimoTopDown(vector<int> &B, int i, int j, vector<vector<pair<int,int>>>& estados){
    int aux = (j > 0)? j : 0;

    if(estados[i][aux].first != -1) return estados[i][aux];
    if(i == n && j > 0){
        estados[i][aux] = {100,100};
        return estados[i][aux];
    } else if(j <= 0){
        estados[i][aux] = {0,0};
        return estados[i][aux];
    }

    pair<int,int> res1 = pagarOptimoTopDown(B,i+1,j,estados);
    pair<int,int> res2 = pagarOptimoTopDown(B,i+1,j-B[i], estados);
    res2.first += B[i];
    res2.second += 1;

    if(res1.first < res2.first || (res1.first == res2.first && res1.second < res2.second)) {
        estados[i][aux] = res1;
        return estados[i][aux];
    }

    return estados[i][aux] = res2;
}



int main() {
    vector<int> B(n);

    for (int i = 0; i < n; ++i) B[i] = i+1;

    //pair<int,int> res = pagarOptimoBacktracking(B,n,c);
    pair<int,int> res = pagarOptimoTopDown(B,0,c,estados);
    cout << res.first << "," << res.second;

    return 0;
}




