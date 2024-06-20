#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
    string S;
    cin >> S;
    string T;
    cin >> T;

    bool success = false;
    for(int64_t i = S.size() - T.size(); i >= 0; i--) {
        bool wk = true;
        for(int64_t j = 0; j < T.size(); j++) {
            if(S[i + j] != '?' && S[i + j] != T[j]) {
                wk = false;
                break;
            }
        }
        if(wk) {
            for(int64_t j = 0; j < T.size(); j++) {
                S[i + j] = T[j];
            }
            success = true;
            break;
        }
    }

    if(success == false) {
        cout << "UNRESTORABLE" << endl;
    }
    else {
        // ?をaに変える
        for(int64_t i = 0; i < S.size(); i++) {
            if(S[i] == '?') {
                S[i] = 'a';
            }
        }
        cout << S << endl;
    }

    return(0);
}