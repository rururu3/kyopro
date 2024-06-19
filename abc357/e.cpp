#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <atcoder/scc.hpp>

using namespace std;
using namespace atcoder;


// 強連結成分分解ライブラリを使うといいっぽい(scc_graph)
int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> A(N);
    for(int64_t i = 0; i < N; i++) {
        cin >> A.at(i);
        A[i]--;
    }

    scc_graph g(N);
    for(int64_t i = 0; i < N; i++) {
        g.add_edge(i, A[i]);
    }

    int64_t ans[N] = {0};

    // sccが返すものはトポロジカルソートされているので端っこから入ってるイメージ
    auto scc = g.scc();
    for(int64_t i = scc.size() - 1; i >= 0; i--) {
        if(scc[i].size() > 1 || scc[i][0] == A[scc[i][0]]) {
            for(auto v : scc[i]) {
                ans[v] = scc[i].size();
            }
        }
        else {
            ans[scc[i][0]] = ans[A[scc[i][0]]] + 1;
        }
    }

    int64_t sum = 0;
    for(int64_t i = 0; i < N; i++) {
        sum += ans[i];
    }

    cout << sum << endl;

    return(0);
}