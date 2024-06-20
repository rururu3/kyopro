#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

// ルート保存用
vector<vector<int64_t>> route(8);

// 行ったことある保存用
vector<int64_t> checks(8, 0);

// 深さ優先
int64_t dfs(int64_t nIdx, int64_t cnt, int64_t N) {
    // 全頂点行っている
    if(cnt == N) {
        return(1);
    }

    int64_t ret = 0;

    for(auto& v: route[nIdx]) {
        if(checks[v] == 0) {
            checks[v] = 1;
            ret += dfs(v, cnt + 1, N);
            checks[v] = 0;
        }
    }

    return(ret);
}

int main() {
    int64_t N, M;
    cin >> N >> M;

    int64_t a = 0, b = 0;
    for(int64_t i = 0; i < M; i++) {
        cin >> a >> b;

        // 0オリジン
        a--;
        b--;

        // 両方の点にルートを追加
        route[a].push_back(b);
        route[b].push_back(a);
    }

    // 最初は0からなので行ったことにする
    checks[0] = 1;
    // dfsで解く
    int64_t ans = dfs(0, 1, N);

    std::cout << ans << endl;

    return(0);
}