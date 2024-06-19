#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
using namespace atcoder;

char A[10][10];

int pos1(int x, int y) {
    return(y * 10 + x);
}

void dusAdd(dsu& d, int x, int y) {
    if(A[y][x] == 'o') {
        // 上
        if(y > 0 && A[y - 1][x] == 'o') {
            d.merge(pos1(x, y - 1), pos1(x, y));
        }
        // 下
        if(y < 10 - 1 && A[y + 1][x] == 'o') {
            d.merge(pos1(x, y + 1), pos1(x, y));
        }
        // 左
        if(x > 0 && A[y][x - 1] == 'o') {
            d.merge(pos1(x - 1, y), pos1(x, y));
        }
        // 右
        if(x < 10 - 1 && A[y][x + 1] == 'o') {
            d.merge(pos1(x + 1, y), pos1(x, y));
        }
    }
}

int main() {
    int oCnt = 0;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> A[i][j];
            if(A[i][j] == 'o') {
                oCnt++;
            }
        }
    }

    // DSUで解けるはず
    dsu d(100);

    // まずは現在状態でDSUを作る
    for(int x = 0; x < 10; x++) {
        for(int y = 0; y < 10; y++) {
            dusAdd(d, x, y);
        }
    }

    // DUSをコピーして島に変えてグループが一つになるかを見る
    for(int x = 0; x < 10; x++) {
        for(int y = 0; y < 10; y++) {
            dsu wkd = d;
            if(A[y][x] == 'x') {
                A[y][x] = 'o';
                dusAdd(wkd, x, y);
                if(wkd.size(pos1(x, y)) == oCnt + 1) {
                    cout << "YES" << endl;
                    return(0);
                }
                A[y][x] = 'x';
            }
        }
    }
    cout << "NO" << endl;

    return(0);
}