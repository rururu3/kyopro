#include <atcoder/dsu>
#include <cstdio>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N, M;
    cin >> N >> M;
    int64_t H;

    int64_t ans = 0;
    for(ans = 0; ans < N; ans++) {
        cin >> H;
        if(H > M) {
            break;
        }
        M -= H;
    }

    std::cout << ans << endl;

    return(0);
}