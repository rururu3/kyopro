#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
    int64_t M;
    cin >> M;

    // お釣りにする
    M = 1000 - M;

    int64_t ans = 0;
    int64_t coins[6] = {500, 100, 50, 10, 5, 1};

    for(auto& c: coins) {
        int64_t div = M / c;
        M -= div * c;
        ans += div;
    }

    std::cout << ans << endl;

    return(0);
}