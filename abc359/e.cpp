#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> H(N);
    for(int64_t i = 0; i < N; i++) {
        cin >> H.at(i);
    }

    // 左側が低かったら今までの分右側の高さまで水を注ぐ必要がある
    // stは左から{ 高さ, 幅 }という水が入っているデータ保存(左からデータが入り右から取っていくのでstack)
    stack<pair<int64_t, int64_t>> st;
    int64_t ans = 0;
    for(int64_t i = 0; i < N; i++) {
        // 幅
        int64_t w = 1;
        // 水データの右側が壁より小さければデータを取り出し答えから引く(最終的にその高さ＊幅で算出するのでじゃまになる)
        while(st.size() > 0 && st.top().first <= H[i]) {
            auto v = st.top();
            st.pop();
            w += v.second;
            ans -= v.first * v.second;
        }
        st.push({H[i], w});
        ans += H[i] * w;

        cout << ans + 1 << " ";
    }

    cout << endl;
    
    return(0);
}