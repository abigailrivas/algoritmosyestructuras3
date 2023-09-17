#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

vector<int> A = {1,2,4,6};
vector<int> B = {1,5,5,7,9};

int parejasMax(vector<int>& A, vector<int>& B){
    int n = A.size();
    int m = B.size();
    int contador = 0;
    int ult = 0;
    for (int i = 0; i < min(n,m); ++i) {
        while(ult != m){
            if(abs(A[i] - B[ult]) <= 1) {
                contador++;
                ++ult;
            }
            break;
        }
    }
    return contador;
}

int main() {
    int res = parejasMax(A,B);
    cout << res;
    return 0;
}
