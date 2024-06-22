#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>
#include <atcoder/modint>
#include <map>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    // K文字が反転時に同じでなければOKなのでOKだった場合はdpに登録する感じ
    vector<map<string, modint998244353>> dp(N + 1);
    dp[0][""] = 1;
    for(int64_t i = 0; i < N; i++) {
        for(auto& v: dp[i]) {
            for(auto c: {'A', 'B'}) {
                if(S[i] == c || S[i] == '?') {
                    string wk = v.first + c;
                    string rwk = wk;
                    reverse(rwk.begin(), rwk.end());
                    if(wk.size() != K || wk != rwk) {
                        if(wk.size() == K) {
                            wk.erase(0, 1);
                        }
                        dp[i + 1][wk] = dp[i + 1][wk] + v.second.val();
                    }
                }
            }
        }
    }

    modint998244353 ans(0);

    for(auto& v: dp[N]) {
        ans += v.second;
    }
    
    cout << ans.val() << endl;

    return(0);
}