#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>
#include <map>

using namespace std;
using namespace atcoder;

int main() {
    int64_t A, B, C, X;
    cin >> A >> B >> C >> X;

    int64_t ans = 0;

    for(int64_t i = 0; i <= A; i++) {
        for(int64_t j = 0; j <= B; j++) {
            for(int64_t k = 0; k <= C; k++) {
                if(X == i * 500 + j * 100 + k * 50) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return(0);
}