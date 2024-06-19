#include <atcoder/dsu>
#include <cstdio>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N, M;
    cin >> N >> M;

    vector<int64_t> A(M, 0);
    vector<int64_t> X(M, 0);
    
    for(int i = 0; i < M; i++) {
        cin >> A.at(i);
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int wk;
            cin >> wk;
            X[j] += wk;
        }
    }

    bool flg = true;
    for(int i = 0; i < M; i++) {
        if(A[i] > X[i]) {
            flg = false;
            break;
        }
    }

    cout << (flg ? "Yes" : "No") << endl;

    return(0);
}