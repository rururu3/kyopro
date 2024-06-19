#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
using namespace atcoder;

char ans[729][729] { ' ' }; // 729 = 6^3

void hoge(int64_t level, int64_t left, int64_t top) {
    if(level == 0) {
        ans[top][left] = '#';
        return;
    }

    int64_t s = pow(3, level - 1);

    for(int64_t i = 0; i < 3; i++) {
        for(int64_t j = 0; j < 3; j++) {
            if(i == 1 && j == 1) {
                // 白塗りつぶし
                for(int64_t wy = top + s; wy < top + 2 * s; wy++) {
                    for(int64_t wx = left + s; wx < left + 2 * s; wx++) {
                        ans[wy][wx] = '.';
                    }
                }
            }
            else {
                hoge(level - 1, left + j * s, top + i * s);
            }
        }
    }
}

int main() {

    int64_t N;
    cin >> N;

    int64_t s = pow(3, N);

    hoge(N, 0, 0);

    for(int64_t i = 0; i < s; i++) {
        for(int64_t j = 0; j < s; j++) {
            std::cout << ans[i][j];
        }
        std::cout << endl;
    }

    return(0);
}