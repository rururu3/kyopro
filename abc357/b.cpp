#include <atcoder/dsu>
#include <cstdio>
#include <iostream>

using namespace std;
using namespace atcoder;

int main() {
    string S;
    cin >> S;

    int64_t upper = 0, lower = 0;

    for(int64_t i = 0; i < S.length(); i++) {
        if(S[i] >= 'a' && S[i] <= 'z') {
            lower++;
        }
        else {
            upper++;
        }
    }

    if(lower > upper) {
        transform(S.begin(), S.end(), S.begin(), ::tolower);
    }
    else {
        transform(S.begin(), S.end(), S.begin(), ::toupper);
    }

    std::cout << S << endl;

    return(0);
}