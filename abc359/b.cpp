#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> A(2 * N);
    for(int64_t i = 0; i < 2 * N; i++) {
        cin >> A.at(i);
    }

    int64_t ans = 0;
    for(int64_t i = 2; i < 2 * N; i++) {
        if(A[i - 2] == A[i] && A[i - 1] != A[i]) {
            ans++;
        }
    }

    cout << ans << endl;
    
    return(0);
}