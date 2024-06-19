#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
using namespace atcoder;

// 累積和
const int64_t AMax = 1000000;
int64_t prefixSum[AMax + 1] = {0};

int main() {
    int64_t N;
    cin >> N;

    vector<int64_t> A(N);

    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    // Aをソートして問題ない
    std::sort(A.begin(), A.end(), std::less<int64_t>());

    // 累積和
    for_each(A.begin(), A.end(), [](int64_t x) {
        prefixSum[x]++;
    });
    for(int64_t i = 0; i < AMax; i++) {
        prefixSum[i + 1] += prefixSum[i];
    }

    // 算出
    int64_t ans = 0;
    for(int64_t i = 0; i < N; ) {
        int64_t num = prefixSum[A[i]] - prefixSum[A[i] - 1];
        ans += num * (num - 1) / 2;

        for(int64_t j = 1; j < AMax / A[i] + 1; j++) {
            int64_t a = prefixSum[min(AMax, A[i] * (j + 1) - 1)] - prefixSum[A[i] * j - 1];
            if(j == 1) {
                a -= num;
            }
            ans += (a * j * num);
        }

        i += num;
    }

    std::cout << ans << endl;

    return(0);
}