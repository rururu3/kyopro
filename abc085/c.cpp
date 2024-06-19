#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
using namespace atcoder;

struct _DATA {
    int64_t t;
    int64_t x;
    int64_t y;
};

int main() {
    int64_t N;
    cin >> N;

    vector<_DATA> D(N);
    for(int64_t i = 0; i < N; i++) {
        cin >> D[i].t >> D[i].x >> D[i].y;
    }

    int64_t x = 0, y = 0, t = 0;
    for(int64_t i = 0; i < N; i++) {
        // 距離
        int64_t distance = abs(x - D[i].x) + abs(y - D[i].y);
        distance = (D[i].t - t) - distance;
        if(distance < 0 || distance % 2 != 0) {
            cout << "No" << endl;
            return(0);
        }
        x = D[i].x;
        y = D[i].y;
        t = D[i].t;
    }

    cout << "Yes" << endl;

    return(0);
}