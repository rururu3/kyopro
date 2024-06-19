#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N, M;
    cin >> N >> M;

    // Mのビットがあるところだけ処理
    int64_t div = 2;
    int64_t ans = 0;
    for(int64_t i = 0; M > 0; M = M >> 1) {
        if(M & 0x1) {
            int64_t add = max(0l, N % div - (div / 2 - 1));
            ans += (N / div) * div / 2 + add;
            ans %= 998244353;
        }
        div *= 2;
    }

    std::cout << ans << endl;

    return(0);
}