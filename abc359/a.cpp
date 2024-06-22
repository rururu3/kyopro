#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
    int64_t N;
    cin >> N;

    string s;
    int64_t ans = 0;
    for(int64_t i = 0; i < N; i++) {
        cin >> s;
        if(s == "Takahashi") {
            ans++;
        }
    }

    cout << ans << endl;
    
    return(0);
}