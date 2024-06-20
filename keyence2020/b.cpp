#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N;
    cin >> N;

    vector<pair<int64_t, int64_t>> arms(N);

    int64_t X, L;
    for(int64_t i = 0; i < N; i++) {
        cin >> X >> L;
        arms[i].first = X - L;
        arms[i].second = X + L;
    }

    // 右端でソート
    sort(arms.begin(), arms.end(), [](const pair<int64_t, int64_t>& a, const pair<int64_t, int64_t>& b) {
        return(a.second < b.second);
    });

    int64_t ans = 0;
    int64_t cur = -9999999999;
    for(auto& v: arms) {
        if(cur <= v.first) {
            ans++;
            cur = v.second;
        }
    }

    std::cout << ans << endl;

    return(0);
}