#include <atcoder/dsu>
#include <cstdio>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
    string S;
    cin >> S;

    int64_t ans = 0;
    for(int i = 0; i < (0x1 << (S.length() - 1)); i++) {
        int64_t sum = 0, wk = S[0] - '0';
        for(int j = 1; j < S.length(); j++) {
            if(0x1 & i >> (j - 1)) {
                sum += wk;
                wk = 0;
            }
            wk = wk * 10 + S[j] - '0';
        }
        sum += wk;

        ans += sum;
    }

    cout << ans << endl;

    return(0);
}