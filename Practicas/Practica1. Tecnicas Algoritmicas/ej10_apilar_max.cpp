#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> w,s;
vector<vector<int>> mem;

int apilarMax(int i, int c){
    if(c < 0) return -1;
    if(i == n) return 0;

    if(mem[i][c] == 0){
        mem[i][c] = max(apilarMax(i+1,c), apilarMax(i+1,min(c-w[i],s[i])) + 1);
    }
    return mem[i][c];
}


int main() {
    n = 5;
    w.push_back(19);
    w.push_back(7);
    w.push_back(5);
    w.push_back(6);
    w.push_back(1);

    s.push_back(15);
    s.push_back(13);
    s.push_back(7);
    s.push_back(8);
    s.push_back(2);

    int maxS = 0;
    for (int i = 0; i < n; ++i) maxS += s[i];

    mem.resize(n,vector<int>(maxS,0));

    int res = apilarMax(0,maxS+w[0]);
    cout << res;
    return 0;
}
