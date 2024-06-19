#include <atcoder/dsu>
#include <cstdio>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    int64_t ans = 0;
    while(true) {
        for(int i = 0; i < N; i++) {
            if(A[i] % 2 == 0) {
                A[i] /= 2;
            }
            else {
                goto END;
            }
        }
        ans++;
    }

END:

    cout << ans << endl;

    return(0);
}