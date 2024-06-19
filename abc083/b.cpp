#include <atcoder/dsu>
#include <cstdio>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N, A, B;
    cin >> N >> A >> B;

    int64_t ans = 0;

    for(int64_t i = 1; i <= N; i++) {
        int64_t sum = 0;
        int64_t wk = i;
        while(wk) {
            sum += (wk % 10);
            wk /= 10;
        }

        if(sum >= A && sum <= B) {
            ans += i;
        }
    }

    cout << ans << endl;

    return(0);
}