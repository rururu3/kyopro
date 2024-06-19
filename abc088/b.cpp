#include <atcoder/dsu>
#include <cstdio>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> D(N, 0);
    for(int64_t i = 0; i < N; i++) {
        cin >> D.at(i);
    }

    // 降順ソート
    sort(D.begin(), D.end(), std::greater<int64_t>());

    int64_t ans = 1;
    for(int64_t i = 1; i < N; i++) {
        if(D[i - 1] != D[i]) {
            ans++;
        }
    }

    cout << ans << endl;

    return(0);
}