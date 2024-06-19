#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <atcoder/modint.hpp>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

// 解説見てmintを使えば一発(等比数列の和まではわかったんだけど、mintを忘れてた)
int main() {
    int64_t N;
    cin >> N;

    int64_t x = N;

    mint r = 1;

    while(x) {
        x /= 10;
        r *= mint(10);
    }

    mint ans = mint(N) * (r.pow(N) - mint(1)) * ((r - mint(1)).inv());

    cout << ans.val() << endl;

    return(0);
}