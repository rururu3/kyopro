#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
    int64_t H, N;
    cin >> H >> N;

    vector<pair<int64_t, int64_t>> magics(N);
    for(int64_t i = 0; i < N; i++) {
        cin >> magics.at(i).first >> magics.at(i).second;
    }

    // dpで解く
    // dp[i] 体力j残っているときの消費魔力が入っている
    vector<int64_t> dp(H + 1, 9999999999);
    dp[H] = 0;
    for(int64_t i = 0; i < N; i++) {
        for(int64_t j = H; j >= 0; j--) {
            int64_t wkj = max(0l, j - magics[i].first);
            dp[wkj] = min(dp[wkj], dp[j] + magics[i].second);
        }
    }

    cout << dp[0] << endl;

    return(0);
}