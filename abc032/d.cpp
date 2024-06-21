#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

int64_t N, W;
int64_t ans = 0;

// dfs
// x: 荷物調べた個数
// sumv: 価値合計
// sumw: 重さ合計
// luggages: 荷物
void dfs(int64_t x, int64_t sumv, int64_t sumw, vector<pair<int64_t, int64_t>>& luggages)
{
	if(x >= N) {
		ans = max(ans, sumv);
		return;
	}
    // まだ入れれるときはいれる
	if(luggages[x].second <= sumw) {
		dfs(x + 1, sumv + luggages[x].first, sumw - luggages[x].second, luggages);
    }
    // 入れない
	dfs(x + 1, sumv, sumw, luggages);
}

int main() {
    cin >> N >> W;

    int64_t flagv = 1, flagw = 1;

    // first: 価値 second: 重さ
    vector<pair<int64_t, int64_t>> luggages(N);
    for(int64_t i = 0; i < N; i++) {
        cin >> luggages.at(i).first >> luggages.at(i).second;

		if(luggages.at(i).first > 1000)
		{
			flagv = 0;
		}
		if(luggages.at(i).second > 1000)
		{
			flagw = 0;
		}
    }

    if(!flagv && !flagw) {
        dfs(0l, 0l, W, luggages);
    }
    else if(flagw) {
        // dpで解く(dp[i]: 重さiのときの最大価値)
        vector<int64_t> dp(W + 1, -99999999999);
        dp[0] = 0;
        for(auto& v: luggages) {
            for(int64_t i = W; i >= v.second; i--) {
                dp[i] = max(dp[i], dp[i - v.second] + v.first);
            }
        }

        for(int64_t i = 1; i <= W; i++) {
            ans = max(ans, dp[i]);
        }
    }
    else {
        // dpで解く(dp[i]: 価値iのときの最小の重さ)
        vector<int64_t> dp(2000001, 99999999999);
        dp[0] = 0;
        for(auto& v: luggages) {
            for(int64_t i = 2000000; i >= v.first; i--) {
                dp[i] = min(dp[i], dp[i - v.first] + v.second);
            }
        }

        for(int64_t i = 1; i <= 2000000; i++) {
            if(dp[i] <= W) {
                ans = i;
            }
        }
    }

    cout << ans << endl;

    return(0);
}