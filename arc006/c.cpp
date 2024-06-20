#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> space(N, 9999999999);

    int64_t w;
    for(int64_t i = 0; i < N; i++) {
        cin >> w;

        // いれる場所を決める
        // lower_boundを使用するためにソートする…必要はなかった(指定した値以上で最初に見つかったところに指定した値をいれるのだから順番が入れ替わることはない)
        // sort(space.begin(), space.end());
        
        // lower_bound:指定した値以上のところを取得するもの)
        auto iter = lower_bound(space.begin(), space.end(), w);
        space[iter - space.begin()] = w;
    }

    auto iter = lower_bound(space.begin(), space.end(), 9999999999);
    cout << (iter - space.begin()) << endl;

    return(0);
}