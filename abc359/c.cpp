#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
    int64_t Sx, Sy, Tx, Ty;

    cin >> Sx >> Sy;
    cin >> Tx >> Ty;

    int64_t ans = 0;

    // 多分Y移動は距離でいいはず
    ans += abs(Sy - Ty);

    int64_t dx = abs(Sx - Tx);
    if(Sx < Tx) {
        // Sの開始がどこか
        if((Sy % 2 == Sx % 2)) {
            dx--;
        }
        dx -= ans;
        if(dx > 0) {
            ans += (dx + 1) / 2;
        }
    }
    else if(Sx > Tx) {
        // Sの開始がどこか
        if((Sy % 2 != Sx % 2)) {
            dx--;
        }
        dx -= ans;
        if(dx > 0) {
            ans += (dx + 1) / 2;
        }
    }

    cout << ans << endl;
    
    return(0);
}