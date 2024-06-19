#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
using namespace atcoder;

struct _DATA {
    int c;
    int a[15];
    char r;
    _DATA() {
        c = r = 0;
        memset(a, 0, sizeof(a));
    }
};

_DATA d[100];

int main() {
    int64_t N, M, K;
    cin >> N >> M >> K;

    for(int i = 0; i < M; i++) {
        cin >> d[i].c;
        for(int j = 0; j < d[i].c; j++) {
            cin >> d[i].a[j];
        }
        cin >> d[i].r;
    }

    int ans = 0;

    for(int i = 0; i < (0x1 << N); i++) {
        bool flg = true;
        for(int m = 0; m < M; m++) {
            int cnt = 0;
            for(int c = 0; c < d[m].c; c++) {
                if(i & 0x1 << (d[m].a[c] - 1)) {
                    cnt++;
                }
            }
            flg &= ((d[m].r == 'o') == (cnt >= K));
        }
        if(flg) {
            ans++;
        }
    }

    std::cout << ans << endl;

    return(0);
}