#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
    int64_t X, Y;
    cin >> X >> Y;

    int64_t ans = 0;
    int64_t wk = Y / X;
    while(wk >= (0x1ll << ans)) {
        ans++;
    }

    cout << ans << endl;

    return(0);
}