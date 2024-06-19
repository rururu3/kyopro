#include <atcoder/dsu>
#include <cstdio>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N, L, R;
    cin >> N >> L >> R;

    int64_t i = 0;
    for(i = 1; i < L; i++) {
        cout << i << " ";
    }
    for( ; i <= R; i++) {
        cout << R - (i - L) << " ";
    }
    for( ; i <= N; i++) {
        cout << i << " ";
    }

    return(0);
}